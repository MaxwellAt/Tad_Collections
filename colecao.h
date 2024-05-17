#ifndef TADGENERICO_MEU_COLLECTION_H_H
#define TADGENERICO_MEU_COLLECTION_H_H
#define TRUE 1
#define FALSE 0
// Definição do TAD Collection
typedef struct {
    int capacidade;
    int tamanho;
    int cur;
    void **elementos;
} Collection;


//---- criar uma colecao
Collection *create(int capacidade);
//---- Inserir um TIPO ESCOLHIDO na colecao
int colInsert(Collection *c, void *elemento);
//---- Remover um TIPO ESCOLHIDO na colecao identificado pelo campo char, int e float
void colRemove(Collection *c, void *elemento, int (*cmp)(void *, void *));
//---- Consultar um TIPO ESCOLHIDO na colecao identificado pelo campo char, int e float
int *colQuery(Collection *c, void *elemento, int (*cmp)(void *, void *));
// Pega o primeiro item da coleção
void *colGetFirst(Collection *c);
// Pega o próximo item da coleção
void *colGetNext(Collection *c);
//-- destruir a coleção se estiver vazia.
int colDestroy(Collection *c);
//-- esvaziar a colecão
int colClear(Collection *c);

#endif //TADGENERICO_MEU_COLLECTION_H_H