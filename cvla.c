#include <malloc.h>
#include <stdio.h>
#include <string.h>

#include "cvla.def.h"
#include "cvla.err.h"

#define DEFAULT_CVLA_LEN 32

static CVLArrayStatusCode cvla_expand(CVLArray* cvla) {
#ifdef __MEM_SENSITIVE__
    void* new_cvla = malloc((cvla->_cvla_length + DEFAULT_CVLA_LEN) * cvla->_cvla_elsz);

    if (new_cvla == NULL) {
        return CVLAMemError;
    }

    cvla->_cvla_length += DEFAULT_CVLA_LEN;
#else
    cvla->_cvla_length += DEFAULT_CVLA_LEN;

    void* new_cvla = malloc(cvla->_cvla_length * cvla->_cvla_elsz);
#endif

    memcpy(new_cvla, cvla->_cvla, cvla->_cvla_sz * cvla->_cvla_elsz);

    free(cvla->_cvla);

    cvla->_cvla = new_cvla;

    return CVLASuccess;
}

CVLArrayStatusCode cvla_new(size_t arr_length, size_t arr_elsz, void* arr, CVLArray** cvla) {
    if (arr_elsz == 0 || cvla == NULL) {
        return CVLAFuncArgError;
    }

    CVLArray* new_cvla = malloc(sizeof(CVLArray));

#ifdef __MEM_SENSITIVE__
    if (new_cvla == NULL) {
        return CVLAMemError;
    }
#endif

    new_cvla->_cvla_elsz = arr_elsz;
    new_cvla->_cvla_length = arr_length + DEFAULT_CVLA_LEN;
    new_cvla->_cvla_sz = arr_length;
    new_cvla->_cvla = malloc(new_cvla->_cvla_elsz * new_cvla->_cvla_length);

    memcpy(new_cvla->_cvla, arr, arr_length * arr_elsz);

    *cvla = new_cvla;

    return CVLASuccess;
}

CVLArrayStatusCode cvla_fpush(void* el, CVLACopyFunc cpy_func, CVLArray* cvla) {
    if (el == NULL || cvla == NULL || cpy_func == NULL) {
        return CVLAFuncArgError;
    }

    if (cvla->_cvla_sz == cvla->_cvla_length) {
#ifdef __MEM_SENSITIVE__
        CVLArrayStatusCode cvla_expand_status = cvla_expand(cvla);
        if (cvla_expand_status != CVLASuccess) {
            return cvla_expand_status;
        }
#endif
        cvla_expand(cvla);
    }

    cpy_func(cvla->_cvla + cvla->_cvla_elsz * cvla->_cvla_sz, el, 1);

    cvla->_cvla_sz += 1;

    return CVLASuccess;
}

CVLArrayStatusCode cvla_push(void* el, CVLArray* cvla) {
    if (el == NULL || cvla == NULL) {
        return CVLAFuncArgError;
    }

    if (cvla->_cvla_sz == cvla->_cvla_length) {
#ifdef __MEM_SENSITIVE__
        CVLArrayStatusCode cvla_expand_status = cvla_expand(cvla);
        if (cvla_expand_status != CVLASuccess) {
            return cvla_expand_status;
        }
#endif
        cvla_expand(cvla);
    }

    memcpy(cvla->_cvla + cvla->_cvla_elsz * cvla->_cvla_sz, el, cvla->_cvla_elsz);

    cvla->_cvla_sz += 1;

    return CVLASuccess;
}

CVLArrayStatusCode cvla_fpop(void* el, CVLACopyFunc cpy_func, CVLArray* cvla) {
    if (el == NULL || cpy_func == NULL || cvla == NULL) {
        return CVLAFuncArgError;
    }

    if (cvla->_cvla_sz == 0) {
        return CVLAZeroSizeError;
    }

    cvla->_cvla_sz -= 1;

    cpy_func(el, cvla->_cvla + cvla->_cvla_sz * cvla->_cvla_elsz, 1);

    return CVLASuccess;
}

CVLArrayStatusCode cvla_pop(void* el, CVLArray* cvla) {
    if (el == NULL || cvla == NULL) {
        return CVLAFuncArgError;
    }

    if (cvla->_cvla_sz == 0) {
        return CVLAZeroSizeError;
    }

    cvla->_cvla_sz -= 1;

    memcpy(el, cvla->_cvla + cvla->_cvla_sz * cvla->_cvla_elsz, cvla->_cvla_elsz);

    return CVLASuccess;
}

CVLArrayStatusCode cvla_fprint(FILE* f, CVLAPrintFunc print_func, CVLArray* cvla) {
    if (f == NULL || print_func == NULL || cvla == NULL) {
        return CVLAFuncArgError;
    }

    print_func(f, cvla->_cvla, cvla->_cvla_sz);

    return CVLASuccess;
}

CVLArrayStatusCode cvla_free(CVLArray* cvla) {
    if (cvla == NULL) {
        return CVLAFuncArgError;
    }

    if (cvla->_cvla != NULL) {
        free(cvla->_cvla);
    }

    free(cvla);

    return CVLASuccess;
}