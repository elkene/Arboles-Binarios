#include "../nodo/nodo.h"
void ingresarNodo(NodoBinario **raiz, NodoBinario *nuevo, int (*comparar)(void *, void *));
void ingresarElementoArbol(NodoBinario **raiz, void *dato,int (*comparar)(void *,void*));
void imprimirPreOrden(NodoBinario *const raiz, void (*printf)(void*));
void imprimirInOrden(NodoBinario *const raiz, void (*printf)(void*));
void imprimirPostOrden(NodoBinario *const raiz, void (*printf)(void*));
int comparar(void *a, void *b);
void imprimir_entero(void *dato);

