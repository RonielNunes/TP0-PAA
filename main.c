//Roniel Nunes Barbosa

#include <stdio.h>
#include <stdlib.h>

#include "./headers/funcao.h"
#include "./headers/menu.h"

//gcc -o teste main.c ./headers/funcao.h ./sources/funcao.c ./headers/menu.h ./sources/menu.c

int main(int argc, char const *argv[])
{
    
    char matriz[linha][coluna];
    int quantidade = 1;
    int opcao;
    int parada = 1;

    while (parada != 0)
    {
        menu(&opcao,&quantidade);

        //printf("%d %d\n",opcao,quantidade);

        switch (opcao)
        {
        case 1:
            inicializaQuadro(matriz);
            verificaQuantidade(&quantidade);
            pintaSimboloAsterisco(matriz,quantidade);
            exibeQuadro(matriz);
            break;
        case 2:
            inicializaQuadro(matriz);
            verificaQuantidade(&quantidade);
            pintaSimboloSoma(matriz,quantidade);
            exibeQuadro(matriz);
            break;
        case 3:
            inicializaQuadro(matriz);
            verificaQuantidade(&quantidade);
            pintaSimboloX(matriz,quantidade);
            exibeQuadro(matriz);
            break;
        case 4:
            inicializaQuadro(matriz);
            verificaQuantidade(&quantidade);
            pintaSimboloX(matriz,quantidade);
            exibeQuadro(matriz);
            break;
        case 5:
            inicializaQuadro(matriz);
            verificaQuantidade(&quantidade);
            pintaSimboloYngAng(matriz,quantidade);
            exibeQuadro(matriz);
            break;
        case 6:
            inicializaQuadro(matriz);
            verificaQuantidade(&quantidade);
            pintaSimboloArroba(matriz,quantidade);
            exibeQuadro(matriz);
            break;             
        default:
            printf("entrou aqui");
            break;
        }



    }
    




    // char matriz[linha][coluna];
    // int quantidade = 1;
    // int opcao;

    //  inicializaQuadro(matriz);
    //  exibeMatriz(matriz);
    // // pintaSimboloAsterisco(matriz,quantidade);

    // // exibeMatriz(matriz);

    // // pintaSimboloSoma(matriz,quantidade);

    // // exibeMatriz(matriz);

    // // pintaSimboloX(matriz,quantidade);

    // // exibeMatriz(matriz);
    
    // pintaSimboloYngAng(matriz,quantidade);
    // exibeMatriz(matriz);
    return 0;
}
