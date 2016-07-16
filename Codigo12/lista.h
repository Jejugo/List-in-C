#include <stdio.h>
#define INF 9999   // valor a ser usado no nó sentinela

typedef int elem;

typedef struct bloco {
        elem info;
        struct bloco *prox;
} no;

typedef no *ListaOrd;

void cria(ListaOrd*);
void finaliza(ListaOrd*);
void inserir(ListaOrd*,elem,int*);
void remover(ListaOrd*,elem,int*);
int esta_na_lista(ListaOrd,elem);
void imprimir(ListaOrd);
void unir(ListaOrd*,ListaOrd*,ListaOrd*);
void unir_usando_sentinelas(ListaOrd*,ListaOrd*,ListaOrd*);
