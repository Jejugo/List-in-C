#include <stdio.h>
#include "lista.h"

int main(void) {
    ListaOrd L1, L2, L3;
    int erro;
    elem x;
    
    cria(&L1);
    cria(&L2);
    cria(&L3);
    
        
    x=3;
    inserir(&L1,x,&erro);
    x=2;
    inserir(&L1,x,&erro);
    x=8;
    inserir(&L1,x,&erro);
    x=10;
    inserir(&L2,x,&erro);
    x=5;
    inserir(&L2,x,&erro);
    x=7;
    inserir(&L2,x,&erro);
    x=1;
    inserir(&L2,x,&erro);    
    
    printf("\n Os elementos da lista 1 sao: ");
    imprimir(L1);
    printf("\n Os elementos da lista 2 sao: ");
    imprimir(L2);
    
    unir_usando_sentinelas(&L1,&L2,&L3);
    printf("\n A nova lista unida eh: ");
    imprimir(L3);
    
    finaliza(&L1);
    finaliza(&L2);
    finaliza(&L3);
    system("pause");
    
    return 0;
}
