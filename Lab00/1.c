#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>

void pedirArreglo(int a[], int n) {
    int i = 0;
    while(i < n) {
        printf("Ingrese el elemento en la posicion %d:  ",i);
        scanf("%d",&a[i]);
        i = i + 1;
    }

    printf("-------------------------------------\n");
}


typedef struct {
    bool is_upperbound;
    bool is_lowerbound;
    bool exists;
    unsigned int where;
}bound_data;

bound_data check_bound(int value, int arr[], unsigned int length) {
    bound_data res;
    int n;
    unsigned int i = 0;
    bool max = true;
    bool min = true;
    bool hayexiste;
    while (i<length) {
        if (value > arr[i]) { //aqui me dice si value es menor 
            min = false;
        }
        if (value < arr[i]) { //aqui me dice si value es mayor
        max = false; 
        }
        if (arr[i] == value) {
            n = i;
            hayexiste = true;
        }
    i = i +1;
}

    res.is_upperbound = max;
    res.is_lowerbound = min;
    res.exists = hayexiste;
    res.where = n;
    return res;
}

int main(void) {
    int ARRAY_SIZE;
    printf("Ingrese el tamaño del arreglo: ");
    scanf("%d",&ARRAY_SIZE);
    int a[ARRAY_SIZE];
    int value = 9;
    pedirArreglo(a,ARRAY_SIZE);
    
    bound_data result = check_bound(value, a, ARRAY_SIZE);

    printf("%d\n", result.is_upperbound); // Imprime 1
    printf("%d\n", result.is_lowerbound); // Imprime 0
    printf("%u\n", result.exists);        // Imprime 1
    printf("%u\n", result.where);         // Imprime 2

    return EXIT_SUCCESS;
}

