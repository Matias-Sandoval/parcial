#include "array_helpers.h"
#include <stdbool.h>


bool array_is_sorted(int a[], unsigned int length) {
    unsigned int i = 1;
    bool r = true;
    while (i<length) {
        if(a[i]<a[i-1]) {
            r = false;
        }
        i++;
    }
    return r;
}



unsigned int array_from_file(int array[],
                             unsigned int max_size,
                             const char *filepath) {

    FILE * fp;
	    fp = fopen(filepath,"r");


    if (fp == NULL) {
        printf("Error al abrir\n");
        exit(EXIT_FAILURE);
    }

    unsigned int size;
    int result = fscanf(fp, " %u ", &size);
    if(result!=1) {
        printf("1Error en el formato de archivo.\n");
        exit(EXIT_FAILURE);
    }


    unsigned int i = 0;
    if(size > max_size) {
        printf("Error en el formato de archivo. maxsize permitido es: %d\n",max_size);
        exit(EXIT_FAILURE);
    }


    while(i<size) {
        result = fscanf(fp, " %d", &(array[i]));
        if (result != 1) {
            printf("Error en el formato de archivo.\n");
            exit(EXIT_FAILURE);
        }
        i++;
    }
    fclose(fp);
    return size;
}


void array_dump(int a[], unsigned int length) {

    printf("[");

    for (unsigned int i = 0; i < length; i++) {
        printf("%d",a[i]);
        if(i<length - 1) {
            printf(", ");
        }
    }
    printf("]\n");
}






