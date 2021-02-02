#include <stdio.h>
#include <stdlib.h>

#include "./headers/funcao.h"
#include "./headers/menu.h"

//gcc -o teste main.c ./headers/funcao.h ./sources/funcao.c ./headers/menu.h ./sources/menu.c

int main(int argc, char const *argv[])
{
    char matriz[linha][coluna];
    int quantidade = 1;

     inicializaQuadro(matriz);
     exibeMatriz(matriz);
    // pintaSimboloAsterisco(matriz,quantidade);

    // exibeMatriz(matriz);

    // pintaSimboloSoma(matriz,quantidade);

    // exibeMatriz(matriz);

    // pintaSimboloX(matriz,quantidade);

    // exibeMatriz(matriz);
    
    pintaSimboloYngAng(matriz,quantidade);
    exibeMatriz(matriz);
    return 0;
}
