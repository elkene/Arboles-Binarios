#pragma once

typedef struct _NodoBinario {
    void *dato;
    struct _NodoBinario *izq;
    struct _NodoBinario *der;
}NodoBinario;