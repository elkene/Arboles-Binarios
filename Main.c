#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "nodo/nodo.h"
#include "funciones/funciones.h"
#include "cola/cola.h"


int main() {
    NodoBinario *raiz = NULL;

    int valores[] = {10,5,4,3,5,6,6,7,15,15,11,12,17,16,18};
    for (int i = 0; i < sizeof(valores) / sizeof(valores[0]); i++) {
        ingresarElementoArbol(&raiz, &valores[i], comparar);
    }

    void **moda;
    int cantidadModa;
    encontrarModa(raiz, &moda, &cantidadModa, compararEnteros);

    printf("Valores:\n");
    imprimirInOrden(raiz,imprimir_entero);    
    printf("\n");
    printf("Moda(s): ");
    for (int i = 0; i < cantidadModa; i++) {
        printf("%d ", *(int *)moda[i]);
    }
    printf("\n");
    

    free(moda);
    free(cantidadModa);
    liberarArbol(raiz);
    
    return 0; 
}