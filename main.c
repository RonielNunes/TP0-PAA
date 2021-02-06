/*
*   Programa: PROGRAMA GERADOR DE OBRA DE ARTE
*   Autor: Roniel Nunes Barbosa
*   Matéria: Projeto e Análise de Algoritmos
*   Professor: Daniel Mendes Barbosa
*   Descrição:
*           Este programa faz a criação de obras de artes em um quadro de 20x80.  
*       E feito a leitura da obra de arte escolhida pelo usuário e em seguida a 
*       quantidade de figuras desejadas no painel. As imagens escolhidas podem ser 
*       os simbolos: asteriscos, soma, X, yin yang, arroba e batman.
*   Data de conclusão: 03/02/2021
*/

#include <stdio.h>
#include <stdlib.h>

#include "./headers/funcao.h"
#include "./headers/menu.h"

//gcc -o teste main.c ./headers/funcao.h ./sources/funcao.c ./headers/menu.h ./sources/menu.c

int main(int argc, char const *argv[])
{
    
    
    char matriz[linha][coluna];          // Variáveis usadas no main, criação da variável matriz usada para simular o quadro a ser pintado
    int quantidade, opcao, repeticao = 2, parada = 0;     //e variáveis de controle e operções(quantidade de simbolos, opcao para escolha do simbolo e parada do programa).

    while (parada != 1)
    {
        menu(&opcao,&quantidade);       //função usada para a criação do painel menu, faz a leitura da opção e quantidade. 

        switch (opcao)
        {
        case 1:                                           //case 1, faz a pintura dos Simbolos de asteriscos.
            inicializaQuadro(matriz);                     //Faz o preenchimento inicial do quadro, com as linha que marcam sua delimitação orizontal e vertical, além de seu preenchimeto interno com espaço.
            while (repeticao == 2){
                verificaQuantidade(&quantidade);              //Faz a limitação da quantidade de imagens permitidas por tipo. 
                pintaSimboloAsterisco(matriz,quantidade);     //Faz o pintura dos simbolos de asteriscos.
                exibeQuadro(matriz);                          //Faz a exibição da obra prima final.
                menuAuxiliar(&quantidade,&repeticao);
    
            }
            break;
        case 2:                                           //Case 2, faz a pintura dos simbolos de Soma.
            inicializaQuadro(matriz);
            while (repeticao == 2){
                verificaQuantidade(&quantidade);
                pintaSimboloSoma(matriz,quantidade);          //Faz a pintura dos simbolos soma no painel. 
                exibeQuadro(matriz);
                menuAuxiliar(&quantidade,&repeticao);
            }
            break;
        case 3:                                           //case 3, faz a pintura dos simbolos de X.
            inicializaQuadro(matriz);
            while (repeticao == 2){
                verificaQuantidade(&quantidade);
                pintaSimboloX(matriz,quantidade);             //Faz a pintura dos simbolos X no painel.
                exibeQuadro(matriz);
                menuAuxiliar(&quantidade,&repeticao);
            }
            break;
        case 4:                                           //case 4, faz uma pintura mista.
            inicializaQuadro(matriz);
            while (repeticao == 2){
                verificaQuantidade(&quantidade);
                pinturaMista(matriz,quantidade);              //Faz o cálculo para a pintura mista das obras, somente das 3 primeiras listadas. Utiliza quantidades aleatórias entre as três.
                menuAuxiliar(&quantidade,&repeticao);
            }
            break;
        case 5:                                           //Case 5, faz a pintura de uma arte criada por mim, que foi o simbolo do yin yang.
            inicializaQuadro(matriz);
            while (repeticao == 2){
                verificaQuantidadeYinYang(&quantidade);       //Função de verificação de quantidade de imagems yin yang.
                pintaSimboloYinYang(matriz,quantidade);       //Pintura desenvolvida yin yang.
                exibeQuadro(matriz);
                menuAuxiliar(&quantidade,&repeticao);
            }
            break;
        case 6:                                           //Case 6, faz a pintura de uma arte criada por mim, que foi o simbolo do Arroba.
            inicializaQuadro(matriz);
            while (repeticao == 2){
                verificaQuantidadeArroba(&quantidade);        //Função de verificação de quantidade de imagens arroba.
                pintaSimboloArroba(matriz,quantidade);        //Pintura desenvolvida simbolo arroba.
                exibeQuadro(matriz);
                menuAuxiliar(&quantidade,&repeticao);
            }
            break;

        case 7:                                           //Case 7, faz a pintura de uma arte criada por mim, que foi o simbolo do batman.
            inicializaQuadro(matriz);
            while (repeticao == 2){
                verificaQuantidadeBatman(&quantidade);        //Função de verificação de quantidade de imagens do simbolo do batman.
                pintaSimboloBatman(matriz,quantidade);        //Pintura desenvolvida simbolo do Batman.
                exibeQuadro(matriz);
                menuAuxiliar(&quantidade,&repeticao);
            }
            break;
        case 8:                                           //Case 8, lida com o encerramento do programa e mensagem final.
            parada = 1;                                   //Alteração do valor da variável parada para encerrrar o while 
            mensagemEncerramento();                       //Função que lida com a mensagem de encerramento do programa.
            break;             
        default:                                          // Case default, çida com tratemeto de erros de opções não validas.
            mensagemErro();                               //Função que lida com a mensagem aviso de erro no programa. 
            break;
        }
        repeticao = 2;
    }
    return 0;
}
