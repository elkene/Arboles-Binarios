#pragma once
#include "../nodo/nodo.h"

typedef struct {
    NodoDoble *head;
    NodoDoble *tail;
    int size;
} ListaDoble;

typedef struct {
    void *valor;
    int frecuencia;
} FrecuenciaValor;