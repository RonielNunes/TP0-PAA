#include <machineArts.h>

void inicializaQuadro(char matriz[linha][coluna]){

    for (int i = 0; i < linha; i++){
        for (int j = 0; j < coluna; j++){
            //Faz o preenchimento da primeira linha e da ultima linha com -
            if ( (i == 0) || (i == (linha - 1))){
                matriz[i][j] = '-';
            }
            if( (i != 0 && coluna == 0) || (i != 0 && j == coluna - 1) ){
                matriz[i][j] = '|';
            }
            
        }
        
    }
}

void exibeMatriz(char matriz[linha][coluna]){

    for (int i = 0; i < linha; i++){
        printf("\n");
        for (int j = 0; j < coluna; j++){
            printf("%c ", matriz[i][j]);
        }
        
    }
    
}