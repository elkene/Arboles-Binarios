#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "nodo/nodo.h"
#include "funciones/funciones.h"
#include "cola/cola.h"


int main(int argc, char *argv[]) {
    NodoBinario *raiz = NULL;
    srand(time(NULL));

    for (int i = 0; i < 10; i++) {
        void *p = malloc(sizeof(float));
        *(float *)p = 1 + (rand() / (float)RAND_MAX) * (20 - 1);
        ingresarElementoArbol(&raiz, p, comparar);
    }

    printf("Recorrido en preorden: ");
    imprimirPreOrden(raiz, imprimir_float);
    printf("\n");

    printf("Recorrido en inorden: ");
    imprimirInOrden(raiz, imprimir_float);
    printf("\n");

    printf("Recorrido en postorden: ");
    imprimirPostOrden(raiz, imprimir_float);
    printf("\n");
    printf("Recorrido en nivel: ");
    imprimirNivelOrden(raiz, imprimir_float);
    printf("\n");

    printf("Altura del arbol: %d\n", alturaArbol(raiz));

    float *min = encontrarMinimo(raiz);
    float *max = encontrarMaximo(raiz);

    printf("Numero mas chico en el arbol: %.2f\n", *min);
    printf("Numero mas grande en el arbol: %.2f\n", *max);
    for (int i = 0; i < 10; i++) {
    liberarArbol(raiz);
    }    
    return 0;
}