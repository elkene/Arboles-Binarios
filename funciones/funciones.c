#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../nodo/nodo.h"
#include "funciones.h"
#include "../cola/lista.h"
#include "../cola/cola.h"
#include "../pilas/pilas.h"



void IniciarListaDoble(ListaDoble *lista) {
    lista->head = NULL;
    lista->tail = NULL;
    lista->size = 0;
}

void AddHead(ListaDoble *lista, void *dato) {
    NodoDoble *nuevo = (NodoDoble *)malloc(sizeof(NodoDoble));
    if (nuevo == NULL) {
        printf("Error: No se pudo asignar memoria para el nuevo nodo\n");
        return;
    }
    nuevo->data = dato;
    nuevo->next = lista->head;
    nuevo->prev = NULL;
    if (lista->head != NULL) {
        lista->head->prev = nuevo;
    } else {
        lista->tail = nuevo;
    }
    lista->head = nuevo;
    lista->size++;
}

void AddTail(ListaDoble *lista, void *dato) {
    NodoDoble *nuevo = (NodoDoble *)malloc(sizeof(NodoDoble));
    if (nuevo == NULL) {
        printf("Error: No se pudo asignar memoria para el nuevo nodo\n");
        return;
    }
    nuevo->data = dato;
    nuevo->next = NULL;
    nuevo->prev = lista->tail;
    if (lista->tail != NULL) {
        lista->tail->next = nuevo;
    } else {
        lista->head = nuevo;
    }
    lista->tail = nuevo;
    lista->size++;
}

NodoDoble *GetNodoPos(ListaDoble *lista, int pos) {
    NodoDoble *temp = lista->head;
    while (temp != NULL && pos > 0) {
        temp = temp->next;
        pos--;
    }
    return temp;
}



void ImprimirLista(ListaDoble *lista, void (*func)(void *)) {
    NodoDoble *actual = lista->head;
    while (actual != NULL) {
        func(actual->data);
        actual = actual->next;
    }
}

void LiberarLista(ListaDoble *lista) {
    NodoDoble *temp;
    while (lista->head != NULL) {
        temp = lista->head;
        lista->head = lista->head->next;
        free(temp->data);
        free(temp);
    }
    lista->tail = NULL;
    lista->size = 0;
}

NodoDoble *GetNodo(ListaDoble *lista, void *dato) {
    NodoDoble *temp = lista->head;
    while (temp != NULL) {
        if (temp->data == dato) {
            return temp;
        }
        temp = temp->next;
    }
    return NULL;
}

void BorrarNodo(ListaDoble *lista, void *dato) {
    NodoDoble *curr = GetNodo(lista, dato);
    if (curr == NULL) {
        printf("No se encontro el nodo\n");
        return;
    }

    if (curr->prev == NULL) {
        lista->head = curr->next;
    } else {
        curr->prev->next = curr->next;
    }

    if (curr->next == NULL) {
        lista->tail = curr->prev;
    } else {
        curr->next->prev = curr->prev;
    }

    free(curr);
    lista->size--;
}

int alturaArbol(NodoBinario *raiz) {
    if (raiz == NULL) {
        return 0;
    } else {
        int altura_izquierda = alturaArbol(raiz->izq);
        int altura_derecha = alturaArbol(raiz->der);
        return (altura_izquierda > altura_derecha ? altura_izquierda : altura_derecha) + 1;
    }
}

int comparar(void *a, void *b) {
    int *int_a = (int *)a;
    int *int_b = (int *)b;
    return (*int_a - *int_b);
}

int compararchar(const void *a, const void *b) {
    if (*(char *)a < *(char *)b) return -1;
    if (*(char *)a > *(char *)b) return 1;
    return 0;
}

int compararEnteros(const void *a, const void *b) {
    return (*(int *)a - *(int *)b);
}



void imprimir_entero(void *dato) {
    int *valor = (int *)dato;
    printf("%d ", *valor);
}

void imprimir_float(void *dato) {
    float *valor = (float *)dato;
    printf("\n%.2f ", *valor);
}

void *encontrarMinimo(NodoBinario *raiz) {
    if (raiz == NULL) {
        return NULL;
    }
    NodoBinario *actual = raiz;
    while (actual->izq != NULL) {
        actual = actual->izq;
    }
    return actual->dato;
}

void *encontrarMaximo(NodoBinario *raiz) {
    if (raiz == NULL) {
        return NULL;
    }
    NodoBinario *actual = raiz;
    while (actual->der != NULL) {
        actual = actual->der;
    }
    return actual->dato;
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

    imprimirInOrden(raiz->izq,printf);
    printf(raiz->dato);
    imprimirInOrden(raiz->der,printf);

}
void imprimirPostOrden(NodoBinario *const raiz, void (*printf)(void*))
{
    if (raiz==NULL)
    return;

    imprimirPostOrden(raiz->izq,printf);
    imprimirPostOrden(raiz->der,printf);
    printf(raiz->dato);

}

void liberarArbol(NodoBinario *raiz) {
    if (raiz == NULL)
        return;

    liberarArbol(raiz->izq);
    liberarArbol(raiz->der);
    free(raiz->dato); 
    free(raiz); 
}
void imprimirNivelOrden(NodoBinario *const arbol, void (*print)(void *)) {
    if (arbol == NULL)
        return;

    Cola colaAuxiliar;
    IniciarListaDoble(&colaAuxiliar);
    pushcola(&colaAuxiliar, arbol);

    while (!estavaciacola(&colaAuxiliar)) {
        NodoBinario *nodo = (NodoBinario *)popcola(&colaAuxiliar);
        print(nodo->dato);

        if (nodo->izq != NULL)
            pushcola(&colaAuxiliar, nodo->izq);
        if (nodo->der != NULL)
            pushcola(&colaAuxiliar, nodo->der);
    }
}

void imprimirNivelInverso(NodoBinario *const arbol, void(*print)(void*)){
    if(arbol==NULL)
    return;

    Cola aux;
    IniciarListaDoble(&aux);
    pushcola(&aux,arbol);
    Pilas pila;
    IniciarListaDoble(&pila);

    while(!estavaciacola(&aux)){
        NodoBinario *nodo=(NodoBinario *)popcola(&aux);
        push(&pila,nodo);
        if(nodo->izq!=NULL){
            pushcola(&aux,nodo->izq);
        }
        if(nodo->der!=NULL){
            pushcola(&aux,nodo->der);
        }
    }
    while (!estaVacia(&pila)) {
        NodoBinario *nodo = (NodoBinario *)pop(&pila);
        print(nodo->dato);
    }

    LiberarLista(&pila);
}

NodoBinario **buscarNodo(NodoBinario **raiz, void *data, int (*comparar)(void *, void *)) {
    if (*raiz == NULL || comparar((*raiz)->dato, data) == 0) {
        return raiz;
    }

    if (comparar((*raiz)->dato, data) > 0) {
        return buscarNodo(&((*raiz)->izq), data, comparar);
    } else {
        return buscarNodo(&((*raiz)->der), data, comparar);
    }
}

NodoBinario **buscarMinimo(NodoBinario **raiz) {
    NodoBinario **actual = raiz;

    while ((*actual)->izq != NULL) {
        actual = &((*actual)->izq);
    }

    return actual;
}


int eliminarNodo(NodoBinario **raiz, void *data, int (*comparar)(void *, void *)) {
    NodoBinario **nborrar = buscarNodo(raiz, data, comparar);

    if (*nborrar == NULL) {
        return 0;
    }

    if ((*nborrar)->izq == NULL && (*nborrar)->der == NULL) {
        free(*nborrar);
        *nborrar = NULL;
        return 1;
    } else if ((*nborrar)->der == NULL) {
        NodoBinario *temporal = *nborrar;
        *nborrar = (*nborrar)->izq;
        free(temporal);
        temporal = NULL;
        return 1;
    } else if ((*nborrar)->izq == NULL) {
        NodoBinario *temporal = *nborrar;
        *nborrar = (*nborrar)->der;
        free(temporal);
        temporal = NULL;
        return 1;
    } else {
        NodoBinario **minimo = buscarMinimo(&((*nborrar)->der));
        (*nborrar)->dato = (*minimo)->dato;
        return eliminarNodo(&((*nborrar)->der), (*minimo)->dato, comparar);
    }
}

void imprimirArbolGrafico(NodoBinario *raiz, void (*print)(void *)) {
    if (raiz == NULL) {
        printf("Árbol vacío.\n");
        return;
    }

    Cola colaAuxiliar;
    IniciarListaDoble(&colaAuxiliar);
    pushcola(&colaAuxiliar, raiz);

    int nodosNivelActual = 1;
    int nodosNivelSiguiente = 0;
    int nivel = 0;
    int espacio = 4; 

    while (!estavaciacola(&colaAuxiliar)) {
        NodoBinario *nodo = (NodoBinario *)popcola(&colaAuxiliar);
        nodosNivelActual--;

        if (nodo->izq != NULL) {
            pushcola(&colaAuxiliar, nodo->izq);
            nodosNivelSiguiente++;
        }

        if (nodo->der != NULL) {
            pushcola(&colaAuxiliar, nodo->der);
            nodosNivelSiguiente++;
        }

        for (int i = 0; i < nivel * espacio; i++) {
            printf(" ");
        }

        if (nodo->izq != NULL || nodo->der != NULL) {
            printf("(");
        }

        print(nodo->dato);

        if (nodo->izq != NULL || nodo->der != NULL) {
            printf(")");
        }

        if (nodosNivelActual > 0) {
            printf("/");
        }

        if (nodosNivelSiguiente > 0) {
            printf("\\");
        }

        if (nodosNivelActual == 0) {
            printf("\n");
            nodosNivelActual = nodosNivelSiguiente;
            nodosNivelSiguiente = 0;
            nivel++;
        }
    }
}

void imprimirArbolGraficoInverso(NodoBinario *raiz, void (*print)(void *))
{
     if (raiz == NULL) {
        printf("Árbol vacío.\n");
        return;
    }

    Pilas aux;
    IniciarListaDoble(&aux);
    push(&aux, raiz);

    int nodosNivelActual = 1;
    int nodosNivelSiguiente = 0;
    int nivel = 0;
    int espacio = 4; 

    while (!estavaciacola(&aux)) {
        NodoBinario *nodo = (NodoBinario *)pop(&aux);
        nodosNivelActual--;

        if (nodo->izq != NULL) {
            push(&aux, nodo->izq);
            nodosNivelSiguiente++;
        }

        if (nodo->der != NULL) {
            push(&aux, nodo->der);
            nodosNivelSiguiente++;
        }

        for (int i = 0; i < nivel * espacio; i++) {
            printf(" ");
        }

        if (nodo->izq != NULL || nodo->der != NULL) {
            printf("(");
        }

        print(nodo->dato);

        if (nodo->izq != NULL || nodo->der != NULL) {
            printf(")");
        }

        if (nodosNivelActual > 0) {
            printf("/");
        }

        if (nodosNivelSiguiente > 0) {
            printf("\\");
        }

        if (nodosNivelActual == 0) {
            printf("\n");
            nodosNivelSiguiente = nodosNivelSiguiente;
            nodosNivelSiguiente = 0;
            nivel++;
        }
    }

}
typedef int (*Comparar)(const void *, const void *);

int contarNodosCompletos(NodoBinario *raiz) {
    if (raiz == NULL) {
        return 0;
    }

    if (raiz->izq != NULL && raiz->der != NULL) {
        return 1 + contarNodosCompletos(raiz->izq) + contarNodosCompletos(raiz->der);
    }

    return contarNodosCompletos(raiz->izq) + contarNodosCompletos(raiz->der);
}

int contarSemiCompletos(NodoBinario *raiz) {
    if (raiz == NULL || (raiz->izq == NULL && raiz->der == NULL)) {
        return 0;
    }

    int semiCompletos = 0;

    if ((raiz->izq == NULL && raiz->der != NULL) || (raiz->izq != NULL && raiz->der == NULL)) {
        semiCompletos = 1;
    }

    semiCompletos += contarSemiCompletos(raiz->izq);
    semiCompletos += contarSemiCompletos(raiz->der);

    return semiCompletos;
}
//Funciones del examen
void actualizarFrecuencias(NodoBinario *raiz, FrecuenciaValor *frecuencias, int *maxFrecuencia, int (*comparar)(const void *, const void *)) {
    if (raiz == NULL) {
        return;
    }

    actualizarFrecuencias(raiz->izq, frecuencias, maxFrecuencia, comparar);

    int i = 0;
    while (frecuencias[i].valor != NULL && comparar(raiz->dato, frecuencias[i].valor) != 0) {
        i++;
    }

    if (frecuencias[i].valor == NULL) {
        frecuencias[i].valor = raiz->dato;
    }
    frecuencias[i].frecuencia++;

    if (frecuencias[i].frecuencia > *maxFrecuencia) {
        *maxFrecuencia = frecuencias[i].frecuencia;
    }

    actualizarFrecuencias(raiz->der, frecuencias, maxFrecuencia, comparar);
}

void encontrarModa(NodoBinario *raiz, void ***moda, int *cantidadModa, int (*comparar)(const void *, const void *)) {
    FrecuenciaValor frecuencias[100] = {{NULL, 0}};

    int maxFrecuencia = 0;
    actualizarFrecuencias(raiz, frecuencias, &maxFrecuencia, comparar);

    int cantidad = 0;
    for (int i = 0; frecuencias[i].valor != NULL; i++) {
        if (frecuencias[i].frecuencia == maxFrecuencia) {
            cantidad++;
        }
    }

    void **valoresModa = (void **)malloc(cantidad * sizeof(void *));
    int j = 0;
    for (int i = 0; frecuencias[i].valor != NULL; i++) {
        if (frecuencias[i].frecuencia == maxFrecuencia) {
            valoresModa[j++] = frecuencias[i].valor;
        }
    }

    *moda = valoresModa;
    *cantidadModa = cantidad;
}


