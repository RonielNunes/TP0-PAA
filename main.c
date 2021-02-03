//Roniel Nunes Barbosa

#include <stdio.h>
#include <stdlib.h>

#include "./headers/funcao.h"
#include "./headers/menu.h"

//gcc -o teste main.c ./headers/funcao.h ./sources/funcao.c ./headers/menu.h ./sources/menu.c

int main(int argc, char const *argv[])
{
    
    char matriz[linha][coluna];
    int quantidade,opcao,parada = 0;

    while (parada != 1)
    {
        menu(&opcao,&quantidade);

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
            pinturaMista(matriz,quantidade);
            break;
        case 5:
            inicializaQuadro(matriz);
            verificaQuantidade(&quantidade);
            pintaSimboloYinYang(matriz,quantidade);
            exibeQuadro(matriz);
            break;
        case 6:
            inicializaQuadro(matriz);
            verificaQuantidadeArroba(&quantidade);
            pintaSimboloArroba(matriz,quantidade);
            exibeQuadro(matriz);
            break;

        case 7:
            inicializaQuadro(matriz);
            verificaQuantidadeBatman(&quantidade);
            pintaSimboloBatman(matriz,quantidade);
            exibeQuadro(matriz);
            break;
        case 8:
            parada = 1;
            mensagemEncerramento();
            break;             
        default:
            mensagemErro();
            break;
        }



    }
    return 0;
}
