//Roniel Nunes Barbosa

#include <stdlib.h>
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

void exibeQuadro(char matriz[linha][coluna]){

    for (int i = 0; i < linha; i++){
        printf("\n");
        for (int j = 0; j < coluna; j++){
            printf(" %c", matriz[i][j]);
        }
        
    }
    
}

int linhaAleatoria(){
    int i = (1+( rand() %(linha -2)));
    return i;  //gera um i aleatorio no intervalo de 1 a 18.
}

int colunaAleatoria(){
    int j = (1+( rand() %(coluna - 2)));
    return j; //Gera um j aleatorio no intervalo de 1 a 78. 
}

void verificaQuantidade(int *quantidade){
    printf("%d",(*quantidade));
    if ((*quantidade) <= 0)
        (*quantidade) = 1 + rand()%100;
    else if((*quantidade) > 100)
        (*quantidade) = 100;
}



void pintaSimboloAsterisco(char matriz[linha][coluna], int quantidade){
    int i, j, count = 0;

    while (count <  quantidade){
        i = linhaAleatoria();
        j = colunaAleatoria();
        if(matriz[i][j] == ' '){
            matriz[i][j] = '*';
            count ++;
        }
    }

}
    
void pintaSimboloSoma(char matriz[linha][coluna], int quantidade){
    int i, j, count = 0;

    while (count <  quantidade){
        i = linhaAleatoria();
        j = colunaAleatoria();

        if(matriz[i][j] == ' ' && matriz[i - 1][j] == ' ' && matriz[i + 1][j] == ' ' && matriz[i][j - 1] == ' ' && matriz[i][j + 1]){            
            matriz[i - 1][j] = '*';//Esquerda
            matriz[i + 1][j] = '*'; //Direita
            matriz[i][j] = '*'; //meio
            matriz[i][j - 1] = '*'; //Baixo
            matriz[i][j + 1] = '*'; //Cima
            count ++;
        }
    }
}

void pintaSimboloX(char matriz[linha][coluna], int quantidade){
        int i, j, count = 0;

    while (count <  quantidade){
        i = linhaAleatoria();
        j = colunaAleatoria();

        if(matriz[i][j] == ' ' && matriz[i - 1][j - 1] == ' ' && matriz[i - 1][j + 1] == ' ' && matriz[i + 1][j - 1] == ' ' && matriz[i + 1][j + 1]){            
            matriz[i - 1][j - 1] = '*';//Diagonal Esquerda cima
            matriz[i + 1][j - 1] = '*'; //Diagonal Direita Baixo
            matriz[i][j] = '*'; //meio
            matriz[i - 1][j + 1] = '*';//Diagonal Direita cima
            matriz[i + 1][j + 1] = '*'; // Diagonal  Esquerda baixo
            count ++;
        }
    }
}

void pintaSimboloYngAng(char matriz[linha][coluna], int quantidade){
        int i, j, count = 0;

    while (count <  quantidade){
        i = linhaAleatoria();
        j = colunaAleatoria();

        if(matriz[i][j] == ' ' && matriz[i + 7][j]==' '){            
            //matriz[i][j] = '*';
            matriz[i+4][j+1] = '*';
            matriz[i+4][j+2] = '*';
            matriz[i+3][j+3] = '*';
            matriz[i+2][j+4] = '*';
            matriz[i+1][j+4] = '*';
            matriz[i][j+4] = '*';
            matriz[i-1][j+4] = '*';
            matriz[i+1][j+3] = '*';
            matriz[i][j+3] = '*';
            matriz[i-1][j+3] = '*';
            matriz[i-2][j+3] = '*';
            matriz[i-3][j+2] = '*';
            matriz[i-2][j+2] = '*';
            matriz[i][j+2] = '*';
            matriz[i+3][j+1] = '*';
            matriz[i+2][j+1] = '*';
            matriz[i+1][j+1] = '*';
            matriz[i][j+1] = '*';
            matriz[i-3][j] = '*';
            matriz[i-2][j] = '*';
            matriz[i-1][j] = '*';
            matriz[i-3][j-1] = '*';
            matriz[i-2][j-1] = '*';
            matriz[i-1][j-1] = '*';
            matriz[i-2][j-2] = '*';
            matriz[i-1][j-3] = '*';
            matriz[i][j-3] = '*';
            matriz[i+1][j-3] = '*';
            matriz[i+2][j-3] = '*';
            matriz[i+3][j-2] = '*';
            matriz[i+4][j-1] = '*';
            matriz[i+4][j] = '*';
            matriz[i+2][j] = '*';
            matriz[i][j] = '*'; //meio do desenho
            count ++;
        }
    }
}

