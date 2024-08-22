#ifndef CVLA_H
#define CVLA_H

#include <stdio.h>
#include "cvla.def.h"
#include "cvla.err.h"

extern CVLArrayStatusCode cvla_new(size_t arr_length, size_t arr_elsz, void* arr, CVLArray** cvla);

extern CVLArrayStatusCode cvla_fpush(void* el, CVLACopyFunc cpy_func, CVLArray* cvla);

extern CVLArrayStatusCode cvla_push(void* el, CVLArray* cvla);

extern CVLArrayStatusCode cvla_fpop(void* el, CVLACopyFunc cpy_func, CVLArray* cvla);

extern CVLArrayStatusCode cvla_pop(void* el, CVLArray* cvla);

extern CVLArrayStatusCode cvla_fprint(FILE* f, CVLAPrintFunc print_func, CVLArray* cvla);

extern CVLArrayStatusCode cvla_free(CVLArray* cvla);

// no argument check version

extern CVLArrayStatusCode cvla_new_nocheck(size_t arr_length, void* arr, CVLArray** cvla);

extern CVLArrayStatusCode cvla_fpush_nocheck(void* el, CVLACopyFunc cpy_func, CVLArray* cvla);

extern CVLArrayStatusCode cvla_push_nocheck(void* el, CVLArray* cvla);

extern CVLArrayStatusCode cvla_fpop_nocheck(void* el, CVLACopyFunc cpy_func, CVLArray* cvla);

extern CVLArrayStatusCode cvla_pop_nocheck(void* el, CVLArray* cvla);

extern CVLArrayStatusCode cvla_fprint_nocheck(FILE* f, CVLAPrintFunc print_func, CVLArray* cvla);

extern CVLArrayStatusCode cvla_free_nocheck(CVLArray* cvla);

#endif //CVLA_H
