#include "colecao.h"
#include <stdio.h>
#include <stdlib.h>

// Implementar as funções do TAD Collection
Collection *create(int capacidade) {
    // Verificar se a capacidade é válida
    if (capacidade <= 0) {
        return NULL;
    }
    // Alocar memória para a coleção
    Collection *c = (Collection *) malloc(sizeof(Collection));
    if (c == NULL) {
        return NULL;
    }
    // Alocar memória para o vetor de elementos
    c->elementos = (void **) malloc(capacidade * sizeof(void *));
    if (c->elementos == NULL) {
        free(c);
        return NULL;
    }
    // Inicializar os campos da coleção
    c->capacidade = capacidade;
    c->tamanho = 0;
    c->cur = 0;
    return c;
}

int colInsert(Collection *c, void *elemento) {
    // Verificar se a coleção é válida
    if (c == NULL) {
        return FALSE;
    }
    // Verificar se a coleção está cheia
    if (c->tamanho == c->capacidade) {
        return FALSE;
    }
    // Inserir o elemento na coleção
    c->elementos[c->tamanho] = elemento;
    c->tamanho++;
    return TRUE;
}

void colRemove(Collection *c, void *elemento, int (*cmp)(void *, void *)) {
    // Verificar se a coleção é válida
    if (c == NULL) {
        return;
    }
    // Verificar se a coleção está vazia
    if (c->tamanho == 0) {
        return;
    }
    // Remover o elemento da coleção
    int i;
    for (i = 0; i < c->tamanho; i++) {
        if (cmp(c->elementos[i], elemento) == TRUE) {
            int j;
            for (j = i; j < c->tamanho - 1; j++) {
                c->elementos[j] = c->elementos[j + 1];
            }
            c->tamanho--;
            return;
        }
    }
}

int *colQuery(Collection *c, void *elemento, int (*cmp)(void *, void *)) {
    // Verificar se a coleção é válida
    if (c == NULL) {
        return NULL;
    }
    // Buscar o elemento na coleção
    int i;
    for (i = 0; i < c->tamanho; i++) {
        if (cmp(c->elementos[i], elemento) == TRUE) {
            return c->elementos[i];
        }
    }
    return FALSE;
}

void *colGetFirst(Collection *c) {
    // Verificar se a coleção é válida
    if (c == NULL) {
        return NULL;
    }
    // Verificar se a coleção está vazia
    if (c->tamanho == 0) {
        return NULL;
    }
    // Retornar o primeiro elemento da coleção
    c->cur = 0;
    return c->elementos[c->cur];
}

void *colGetNext(Collection *c) {
    // Verificar se a coleção é válida
    if (c == NULL) {
        return NULL;
    }
    // Verificar se a coleção está vazia
    if (c->tamanho == 0) {
        return NULL;
    }
    // Verificar se já chegou ao final da coleção
    if (c->cur >= c->tamanho - 1) {
        return NULL;
    }
    // Retornar o próximo elemento da coleção
    c->cur++;
    return c->elementos[c->cur];
}

int colDestroy(Collection *c) {
    // Verificar se a coleção é válida
    if (c == NULL) {
        return FALSE;
    }
    // Verificar se a coleção está vazia
    if (c->tamanho > 0) {
        return FALSE;
    }
    // Liberar a memória alocada para a coleção
    free(c->elementos);
    free(c);
    return TRUE;
}

int colClear(Collection *c) {
    // Verificar se a coleção é válida
    if (c == NULL) {
        return FALSE;
    }
    // Limpar a coleção
    c->tamanho = 0;
    c->cur = 0;
    return TRUE;
}