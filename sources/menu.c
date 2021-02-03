//Roniel Nunes Barbosa
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
    printf("   5 - Arte criada yin yang                                             \n");
    printf("   6 - Arte criada Arroba                                               \n");
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

void mensagemEncerramento(){
    printf("\n\n PROGRAMA ENCERRADO! TENHA UM BOM DIA!\n\n");
}

void mensagemErro(){
    printf("\n\nOPCAO NAO ENCONTADA! Tente novamente!\n\n");
}