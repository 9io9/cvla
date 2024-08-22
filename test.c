//
// Created by mario on 2024/8/22.
//

#include "cvla.h"

void cvla_int_print(FILE* f, void* int_arr, size_t int_arr_len) {
    int* arr = int_arr;

    for (size_t int_arr_id = 0; int_arr_id < int_arr_len; ++int_arr_id) {
        fprintf(f, "%d ", arr[int_arr_id]);
    }

    fprintf(f, "\n");
}

int main(int argc, char* argv[]) {
    CVLArray* cvla = NULL;

    if (cvla_new(0, sizeof(int), NULL, &cvla) != CVLASuccess) {
        return -1;
    }

    int test_data = 633;

    if (cvla_push(&test_data, cvla) != CVLASuccess) {
        return -1;
    }

    if (cvla_fprint(stdout, cvla_int_print, cvla) != CVLASuccess) {
        return -1;
    }

    return 0;
}