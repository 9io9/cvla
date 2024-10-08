#ifndef CVLA_H
#define CVLA_H

#include <stdio.h>
#include "cvla.def.h"
#include "cvla.err.h"

#define FUNC_ASSERT(...)

extern CVLArrayStatusCode cvla_new(size_t arr_length, size_t arr_elsz, void* arr, CVLArray** cvla);

extern CVLArrayStatusCode cvla_fpush(void* el, CVLACopyFunc cpy_func, CVLArray* cvla);

extern CVLArrayStatusCode cvla_push(void* el, CVLArray* cvla);

extern CVLArrayStatusCode cvla_fpop(void* el, CVLACopyFunc cpy_func, CVLArray* cvla);

extern CVLArrayStatusCode cvla_pop(void* el, CVLArray* cvla);

extern CVLArrayStatusCode cvla_fprint(FILE* f, CVLAPrintFunc print_func, CVLArray* cvla);

extern CVLArrayStatusCode cvla_free(CVLArray** cvla);

extern CVLArrayStatusCode cvla_clean(CVLArray* cvla);

// no argument check version

FUNC_ASSERT(ARR_ELSZ != 0, CVLA != NULL)
extern CVLArrayStatusCode cvla_new_nocheck(size_t arr_length, size_t arr_elsz, void* arr, CVLArray** cvla);

FUNC_ASSERT(EL != NULL, CPY_FUNC != NULL, CVLA != NULL)
extern CVLArrayStatusCode cvla_fpush_nocheck(void* el, CVLACopyFunc cpy_func, CVLArray* cvla);

FUNC_ASSERT(EL != NULL, CVLA != NULL)
extern CVLArrayStatusCode cvla_push_nocheck(void* el, CVLArray* cvla);

FUNC_ASSERT(EL != NULL, CPY_FUNC != NULL, CVLA != NULL)
extern CVLArrayStatusCode cvla_fpop_nocheck(void* el, CVLACopyFunc cpy_func, CVLArray* cvla);

FUNC_ASSERT(EL != NULL, CVLA != NULL)
extern CVLArrayStatusCode cvla_pop_nocheck(void* el, CVLArray* cvla);

FUNC_ASSERT(F != NULL, PRINT_FUNC != NULL, CVLA != NULL)
extern CVLArrayStatusCode cvla_fprint_nocheck(FILE* f, CVLAPrintFunc print_func, CVLArray* cvla);

FUNC_ASSERT(CVLA != NULL)
extern CVLArrayStatusCode cvla_free_nocheck(CVLArray** cvla);

FUNC_ASSERT(CVLA != NULL)
extern CVLArrayStatusCode cvla_clean_nocheck(CVLArray* cvla);

#undef FUNC_ASSERT
#endif //CVLA_H
