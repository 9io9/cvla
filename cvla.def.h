//
// Created by mario on 2024/8/22.
//

#ifndef CVLA_DEF_H
#define CVLA_DEF_H

#include <stddef.h>

typedef struct CVLArray {
    size_t _cvla_length;
    size_t _cvla_sz;
    size_t _cvla_elsz;
    void* _cvla;
}CVLArray;

typedef void(*CVLACopyFunc)(void*,void*,size_t);
typedef void(*CVLAPrintFunc)(FILE*,void*,size_t);

#endif //CVLA_DEF_H
