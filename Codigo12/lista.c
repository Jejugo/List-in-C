#include "lista.h"

void cria(ListaOrd *L) {
     *L=NULL;
}

void finaliza(ListaOrd *L) {
     no *p;
     p=*L;
     while (p!=NULL) {
           *L=(*L)->prox;
           free(p);
           p=*L;
     }
}

void inserir(ListaOrd *L, elem x, int *erro) {
     no *atual, *ant, *p;
     
     p=(no*) malloc(sizeof(no));
     if (p==NULL)
        *erro=1;
     else {
          *erro=0;
          p->info=x;
          if ((*L==NULL) || (x <(*L)->info)) {
             p->prox=*L;
             *L=p;
          }
          else {
               ant=NULL;
               atual=*L;
               while ((atual!=NULL) && (atual->info<x)) {
                     ant=atual;
                     atual=atual->prox;
               }
               p->prox=atual;
               ant->prox=p;
          }
     }
             
     return;
}

void remover(ListaOrd *L, elem x, int *erro) {
     no *p, *ant;     
     if ((*L==NULL) || (x <(*L)->info))
        *erro=1;
     else if (x==(*L)->info) {
          *erro=0;
          p=*L;
          *L=(*L)->prox;
          free(p);
     }
     else {
          ant=NULL;
          p=*L;
          while ((p!=NULL) && (p->info<x)) {
                ant=p;
                p=p->prox;
          }
          if ((p!=NULL) && (p->info==x)) {
             *erro=0;
             ant->prox=p->prox;
             free(p);
          }
          else *erro=1;
     }     
     return;
}

int esta_na_lista(ListaOrd L, elem x) {
    no *p;
     
    p=L;
    while ((p!=NULL) && (p->info<x)) {
          p=p->prox;
    }
    
    if ((p!=NULL) && (p->info==x)) return 1;
    else return 0;
}

void imprimir(ListaOrd L) {
     no *p;
     
     p=L;
     while (p!=NULL) {
           printf("%d ",p->info);
           p=p->prox;
     }
     printf("\n\n ");
     return;
}

//OBS: une duas listas ordenadas L1 e L2 em uma nova lista L3. L1 e L2 são destruídas
void unir(ListaOrd *L1, ListaOrd *L2, ListaOrd *L3) {
     no *p1, *p2, *p3;

     p1=*L1;
     p2=*L2;
     p3=*L3;

     while ((p1!=NULL) || (p2!=NULL)) {
           if ((p2==NULL) || ((p1!=NULL) && (p1->info<p2->info))) {
              if (*L3==NULL)
                 *L3=p1;
              else p3->prox=p1;
              p3=p1;
              p1=p1->prox;
           }
           else if ((p1==NULL) || ((p2!=NULL) && (p1->info>=p2->info))) {
              if (*L3==NULL)
                 *L3=p2;
              else p3->prox=p2;
              p3=p2;
              p2=p2->prox;
           }
     }
     
     //arrumando ponteiros das listas originais
     *L1=NULL;
     *L2=NULL;
}



//para comparar com a versão anterior, quando nós sentinela forem ensinados
//OBS: notar como a lógica fica mais simples
void unir_usando_sentinelas(ListaOrd *L1, ListaOrd *L2, ListaOrd *L3) {
     no *p1, *p2, *p3, *escolhido;
     
     //inserindo um nó sentinela em cada lista, com um valor "infinito"
     //deveria ser feito no programa principal ou no projeto da lista
     int erro;
     inserir(L1,INF,&erro);
     inserir(L2,INF,&erro);

     p1=*L1;
     p2=*L2;
     p3=*L3;

     while ((p1->info!=INF) || (p2->info!=INF)) {
           if (p1->info<p2->info) {
              escolhido=p1;
              p1=p1->prox;
           }
           else {
                escolhido=p2;
                p2=p2->prox;
           }
           if (*L3==NULL)
              *L3=escolhido;
           else p3->prox=escolhido;
           p3=escolhido;
     }
     p3->prox=NULL;
     
     //arrumando ponteiros das listas originais
     *L1=p1;
     *L2=p2;
}
