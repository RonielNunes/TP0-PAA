/*
*   Programa: PROGRAMA GERADOR DE OBRA DE ARTE
*   Autor: Roniel Nunes Barbosa
*   Matéria: Projeto e Análise de Algoritmos
*   Professor: Daniel Mendes Barbosa
*       
*/
#include <stdio.h>
#include <stdlib.h>

#include "../headers/funcao.h"
#include "../headers/menu.h"

void menu(int *opcao, int *quantidade){
    printf("\n");
    printf("===========================================================================\n");
    printf(":                   PROGRAMA GERADOR DE OBRA DE ARTE                      :\n");
    printf("===========================================================================\n");
    printf("   Escolha o tipo de figura basica a ser usada para criar a obra:       \n");
    printf("   1 - asterisco simples.                                               \n");
    printf("   2 - letra de soma com asteriscos.                                    \n");
    printf("   3 - letra X com asteriscos.                                          \n");
    printf("   4 - figura aleatorias                                                \n");
    printf("   5 - Arte criada Simbolo yin yang                                     \n");
    printf("   6 - Arte criada Simbolo Arroba                                       \n");
    printf("   7 - Arte criada Simbolo Batman                                       \n");
    printf("   8 - Encerrar programa                                                \n");
    printf("   Digite o tipo de figura basica desejada: ");
    scanf("%d",opcao);
    if ((*opcao) == 8)
        return;
    else if( (*opcao)>= 1 && (*opcao) <=7 ){
        printf("   Digite a quantidade de figuras (menor ou igual a zero para aleatorio): ");
        scanf("%d",quantidade);
        printf("============================================================================\n");
    }

}
void menuAuxiliar(int *quantidadeMais, int *repeticao){
    int opcao;
    printf("\n===========================================================================\n");
    printf("Deseja um novo quadro ou adicionar mais pinturas ao quadro atual? \n");
    printf("Digite (1) para NOVO Quadro. \n");
    printf("Digite (2) para adicionar mais pinturas ao quadro ATUAL.\n\n");
    printf("Digite: ");
    scanf("%d",&opcao);
    if (opcao == 1)
    {
        (*repeticao) = 0;
        return;
    }else if(opcao == 2){
        (*repeticao) = 2;
        printf("Digite a nova quantidade de pinturas a serem inseridas: ");
        scanf("%d",quantidadeMais);
    }
}

void mensagemEncerramento(){
    printf("\n\n PROGRAMA ENCERRADO! TENHA UM BOM DIA!\n\n");
}

void mensagemErro(){
    printf("\n\nOPCAO NAO ENCONTADA! Tente novamente!\n\n");
}