#ifndef _ARRAY_HELPERS_H_
#define _ARRAY_HELPERS_H_

#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

unsigned int array_from_file(int array[],
                             unsigned int max_size,
                             const char *filepath); 

void array_dump(int a[], unsigned int length);

bool array_is_sorted(int a[], unsigned int length);

void array_swap(int a[], unsigned int i, unsigned int j);

#endif




