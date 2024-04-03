#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#include "../nodo/nodo.h"
#include "funciones.h"

int comparar(void *a, void *b) {
    int *int_a = (int *)a;
    int *int_b = (int *)b;
    return (*int_a - *int_b);
}
void imprimir_entero(void *dato) {
    int *valor = (int *)dato;
    printf("%d ", *valor);
}

void ingresarNodo(NodoBinario **raiz, NodoBinario *nuevo, int (*comparar)(void *, void *)) {
    if (*raiz == NULL) {
        *raiz = nuevo;
    } else {
        if (comparar(nuevo->dato, (*raiz)->dato) < 0) {
            ingresarNodo(&((*raiz)->izq), nuevo, comparar);
        } else {
            ingresarNodo(&((*raiz)->der), nuevo, comparar);
        }
    }
}


void ingresarElementoArbol(NodoBinario **raiz, void *dato, int (*comparar)(void *, void *)) {
    NodoBinario *nuevo = (NodoBinario *)malloc(sizeof(NodoBinario));
    if (nuevo == NULL) {
        fprintf(stderr, "Error: memoria insuficiente para crear un nuevo nodo.\n");
        exit(EXIT_FAILURE);
    }
    nuevo->dato = dato;
    nuevo->izq = NULL;
    nuevo->der = NULL;

    ingresarNodo(raiz, nuevo, comparar);
}

void imprimirPreOrden(NodoBinario *const raiz, void (*printf)(void*))
{
    if (raiz==NULL)
    return;

    printf(raiz->dato);
    imprimirPreOrden(raiz->izq,printf);
    imprimirPreOrden(raiz->der,printf);
}
void imprimirInOrden(NodoBinario *const raiz, void (*printf)(void*))
{
    if (raiz==NULL)
    return;

    imprimirPreOrden(raiz->izq,printf);
    printf(raiz->dato);
    imprimirPreOrden(raiz->der,printf);

}
void imprimirPostOrden(NodoBinario *const raiz, void (*printf)(void*))
{
    if (raiz==NULL)
    return;

    imprimirPreOrden(raiz->izq,printf);
    imprimirPreOrden(raiz->der,printf);
    printf(raiz->dato);

}





