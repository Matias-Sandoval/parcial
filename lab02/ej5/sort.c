#include <assert.h>
#include <stdbool.h>
#include <stdlib.h>
#include <stdio.h>

#include "array_helpers.h"
#include "sort_helpers.h"
#include "sort.h"
#include "fixstring.h"


static unsigned int partition(fixstring a[], unsigned int izq, unsigned int der) {
    unsigned int piv;
    piv = izq;
    unsigned i = izq + 1;
    unsigned j = der;
    
    while(i<=j) {
        if (goes_before(a[i],a[piv])) {
            i++;
        } else if (goes_before(a[piv],a[j])) {
            j--;
        } else if (goes_before(a[j],a[piv]) && goes_before(a[piv], a[i])) {
            swap(a,i,j);
        }
    }
    swap(a,piv,j);
    return j;
}

static void quick_sort_rec(fixstring a[], unsigned int izq, unsigned int der) {
    unsigned int ppiv;
    ppiv = partition(a,izq,der);
    
    if (ppiv > izq) {
        quick_sort_rec(a,izq,ppiv-1);
    }
    if(ppiv < der) {
        quick_sort_rec(a,ppiv + 1,der);
    }
        
}

void quick_sort(fixstring a[], unsigned int length) {
    quick_sort_rec(a, 0, (length == 0) ? 0 : length - 1);
}




