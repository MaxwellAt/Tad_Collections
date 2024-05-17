#include <stdio.h>
#include "colecao.h"
#include <stdlib.h>
#include <string.h>

typedef struct {
    char nome[30];
    int idade;
    float media;
} Aluno;

void listaElementos(Collection *c) {
    Aluno *a;
    a = (Aluno *) colGetFirst(c);
    while (a != NULL) {
        printf("Nome: %s, Idade: %d, Media escolar: %.2f\n", a->nome, a->idade, a->media);
        a = (Aluno *) colGetNext(c);
    }
    if(a == NULL && c->tamanho == 0) {
        printf("----------Coleção vazia--------\n");
    }
}

int cmp(void *a, void *b) {
    Aluno *aluno = (Aluno *) a;
    Aluno *aluno2 = (Aluno *) b;
    if(strcmp(aluno->nome, aluno2->nome) == 0 && aluno->idade == aluno2->idade && aluno->media == aluno2->media) {
        return TRUE;
    }
    return FALSE;
}

int main() {
    printf("Deseja uma demonstração? (s/n): ");
    char op;
    scanf("%c", &op);
    if(op == 's') {
        Collection *c = create(10);
        Aluno a1 = {"João", 20, 7.1f};
        Aluno a2 = {"Maria", 22, 7.5f};
        Aluno a3 = {"José", 21, 6.9f};
        colInsert(c, &a1);
        colInsert(c, &a2);
        colInsert(c, &a3);
        listaElementos(c);
        printf("Removendo o aluno João\n");
        colRemove(c, &a1, cmp);
        listaElementos(c);
        printf("Consultando o aluno Maria\n");
        Aluno *a = (Aluno *) colQuery(c, &a2, cmp);
        if(a != NULL) {
            printf("Nome: %s, Idade: %d, Media escolar: %.2f\n", a->nome, a->idade, a->media);
        } else {
            printf("Aluno não encontrado\n");
        }
        colClear(c);
        printf("Listando elementos\n");
        listaElementos(c);
        colDestroy(c);

        return 0;
    }
    Collection *c = NULL;
    do{
        printf("1 - Criar coleção\n");
        printf("2 - Inserir elemento\n");
        printf("3 - Remover elemento\n");
        printf("4 - Consultar elemento\n");
        printf("5 - Listar elementos\n");
        printf("6 - Destruir coleção\n");
        printf("7 - Esvaziar coleção\n");
        printf("0 - Sair\n");
        printf("Opção: ");
        int opcao;
        scanf("%d", &opcao);
        if(opcao < 0 || opcao > 7) {
            printf("Voce deve inserir um numero\n");
            return -1;
        }
        switch (opcao) {
            case 1: {
                if(c!=NULL){
                    printf("Coleção já criada\n");
                    printf("Primeiro destrua a coleção anterior\n");
                    break;
                }
                int capacidade;
                printf("Capacidade da coleção: ");

                scanf("%d", &capacidade);
                if(capacidade <= 0) {
                    printf("Capacidade inválida\n");
                    break;
                };
                c = create(capacidade);
                printf("Coleção criada com sucesso!\n");
                break;
            }
            case 2: {
                if(c==NULL){
                    printf("Coleção não criada\n");
                    break;
                }
                Aluno *a = (Aluno *) malloc(sizeof(Aluno));
                if(a==NULL) {
                    printf("Erro ao criar aluno.");
                    return -1;
                }
                printf("Nome: ");
                scanf("%s", a->nome);
                printf("Idade: ");
                scanf("%d", &a->idade);
                printf("Media escolar: ");
                scanf("%f", &a->media);
                if(colInsert(c, a)) {
                    printf("Aluno inserido com sucesso\n");
                } else {
                    printf("Erro ao inserir aluno\n");
                }
                break;
            }
            case 3: {
                if(c==NULL){
                    printf("Coleção não criada\n");
                    break;
                }
                Aluno *a = (Aluno *) malloc(sizeof(Aluno));
                if(a==NULL) {
                    printf("Erro ao criar aluno.");
                    return -1;
                }
                printf("Nome: ");
                scanf("%s", a->nome);
                printf("Idade: ");
                scanf("%d", &a->idade);
                printf("Media escolar: ");
                scanf("%f", &a->media);
                colRemove(c, a, cmp);
                break;
            }
            case 4: {
                if(c==NULL){
                    printf("Coleção não criada\n");
                    break;
                }
                Aluno *a = (Aluno *) malloc(sizeof(Aluno));
                if(a==NULL) {
                    printf("Erro ao criar aluno.");
                    return -1;
                }
                printf("Nome: ");
                scanf("%s", a->nome);
                printf("Idade: ");
                scanf("%d", &a->idade);
                printf("Media escolar: ");
                scanf("%f", &a->media);
                Aluno *aluno = (Aluno *) colQuery(c, a, cmp);
                if(aluno != NULL) {
                    printf("Nome: %s, Idade: %d, Media escolar: %.2f\n", aluno->nome, aluno->idade, aluno->media);
                } else {
                    printf("Aluno não encontrado\n");
                }
                break;
            }
            case 5: {
                if(c==NULL){
                    printf("Coleção não criada\n");
                    break;
                }
                listaElementos(c);
                break;
            }
            case 6: {
                if(c==NULL){
                    printf("Coleção não criada\n");
                    break;
                }
                if (colDestroy(c)){
                    printf("Coleção destruída\n");
                    c = NULL;
                } else {
                    printf("Coleção não destruída\n");
                }
                break;
            }
            case 7: {
                if(c==NULL){
                    printf("Coleção não criada\n");
                    break;
                }
                if(colClear(c)){
                    printf("Coleção esvaziada\n");
                } else {
                    printf("Coleção não esvaziada\n");
                }
                break;
            }
            case 0: {
                return 0;
            }
            default: {
                printf("Opção inválida\n");
            }
        }
    } while(TRUE);
}