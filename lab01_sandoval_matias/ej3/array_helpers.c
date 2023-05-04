#include "array_helpers.h"


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
        printf("1Error en el formato de archivo. Error in file format\n");
        exit(EXIT_FAILURE);
    }


    unsigned int i = 0;
    if(size > max_size) {
        printf("Error en el formato de archivo. maxsize allowed is %d\n",max_size);
        exit(EXIT_FAILURE);
    }


    while(i<size) {
        result = fscanf(fp, " %d", &(array[i]));
        if (result != 1) {
            printf("Error en el formato de archivo. Error in file format\n");
            exit(EXIT_FAILURE);
        }
        i++;
    }
    fclose(fp);
    return size;
}


void array_dump(int a[], unsigned int length) {
    //imprimir el array por pantalla

    printf("[");

    for (unsigned int i = 0; i < length; i++) {
        printf("%d",a[i]);
        if(i<length - 1) {
            printf(", ");
        }
    }
    printf("]\n");
}




