#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#include "nodo/nodo.h"
#include "funciones/funciones.h"


int main() {
    NodoBinario *raiz = NULL;

    int valores[] = {100,50,25,75,150};
    for (int i = 0; i < sizeof(valores) / sizeof(valores[0]); i++) {
        ingresarElementoArbol(&raiz, &valores[i], comparar);
    }

    printf("Recorrido en preorden: ");
    imprimirPreOrden(raiz, imprimir_entero);
    printf("\n");

    printf("Recorrido en inorden: ");
    imprimirInOrden(raiz, imprimir_entero);
    printf("\n");

    printf("Recorrido en postorden: ");
    imprimirPostOrden(raiz, imprimir_entero);
    printf("\n");


    return 0;
}