#include <stdio.h>
#include "../headers/funcao.h"

void inicializaQuadro(char matriz[linha][coluna]){

    for (int i = 0; i < linha; i++){
        for (int j = 0; j < coluna; j++){
            matriz[i][j] = ' ';

            //Faz o preenchimento da primeira linha e da ultima linha com -
            if ( (i == 0) || (i == (linha - 1))){
                matriz[i][j] = '-';
            }
            if( (j == 0 && i!=0 && i != linha -1) || (j == coluna - 1 && i !=0 && i != linha -1)){
                matriz[i][j] = '|';
                
            }
            
        }
        
    }
}

void exibeMatriz(char matriz[linha][coluna]){

    for (int i = 0; i < linha; i++){
        printf("\n");
        for (int j = 0; j < coluna; j++){
            printf(" %c", matriz[i][j]);
        }
        
    }
    
}