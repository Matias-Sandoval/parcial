#include <assert.h>
#include <stdbool.h>
#include <stdio.h>

#include "array_helpers.h"
#include "sort_helpers.h"
#include "sort.h"


static void insert(int a[], unsigned int i) {
    unsigned int j = i;
    while(j > 0 && goes_before(a[j], a[j-1])) {
        swap(a,j-1,j);
        j--;
    }
}




void insertion_sort(int a[], unsigned int length) {
    for (unsigned int i = 1u; i < length; ++i) {
        insert(a, i);
        assert(array_is_sorted(a, i));
    }
}



/*

La función goes_before() implementa una relación de orden entre dos elementos del arreglo que se está ordenando. Determina si dos elementos del arreglo deben intercambiarse o no.

El criterio que usa goes_before() es comparar los elementos utilizando el operador <. Es decir, la función devuelve true si el primer argumento es menor que el segundo, y 0 en caso contrario.


*/

