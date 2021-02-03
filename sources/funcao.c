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
    
    if ((*quantidade) <= 0)
        (*quantidade) = 1 + rand()%100;
    else if((*quantidade) > 100)
        (*quantidade) = 100;
}

void verificaQuantidadeYinYang(int *quantidade){
    
    if ((*quantidade) <= 0)
        (*quantidade) = 1 + rand()%100;
    else if((*quantidade) > 100)
        (*quantidade) = 100;
}

void verificaQuantidadeArroba(int *quantidade){
    
    if ((*quantidade) <= 0)
        (*quantidade) = 1 + rand()%5;
    else if((*quantidade) > 100)
        (*quantidade) = 4;
}

void verificaQuantidadeBatman(int *quantidade){
    
    if ((*quantidade) <= 0)
        (*quantidade) = 1 + rand()% 2;
    else if((*quantidade) > 100)
        (*quantidade) = 3;
}

void pinturaMista(char matriz[linha][coluna],int quantidade){
    int quantidadeTintaAsterisco = 0, quantidadeTintaSoma = 0,quantidadeTintaX = 0;

    printf("Quantidade %d\n",quantidade);
    while ((quantidadeTintaAsterisco + quantidadeTintaSoma + quantidadeTintaX) != quantidade)
    {
        quantidadeTintaAsterisco = 1+ rand() % quantidade;
        quantidadeTintaSoma = 1+ rand() % quantidade;
        quantidadeTintaX = 1+ rand() % quantidade;
    }
    printf("Quantidade %d\n",quantidadeTintaAsterisco+quantidadeTintaSoma+quantidadeTintaX);

    pintaSimboloAsterisco(matriz,quantidadeTintaAsterisco);
    pintaSimboloSoma(matriz,quantidadeTintaSoma);
    pintaSimboloX(matriz,quantidadeTintaX);
    exibeQuadro(matriz);
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

        if(matriz[i][j] == ' ' && matriz[i - 1][j] == ' ' && matriz[i + 1][j] == ' ' && matriz[i][j - 1] == ' ' && matriz[i][j + 1] == ' '){            
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

        if(matriz[i][j] == ' ' && matriz[i - 1][j - 1] == ' ' && matriz[i - 1][j + 1] == ' ' && matriz[i + 1][j - 1] == ' ' && matriz[i + 1][j + 1] == ' '){            
            matriz[i - 1][j - 1] = '*';//Diagonal Esquerda cima
            matriz[i + 1][j - 1] = '*'; //Diagonal Direita Baixo
            matriz[i][j] = '*'; //meio
            matriz[i - 1][j + 1] = '*';//Diagonal Direita cima
            matriz[i + 1][j + 1] = '*'; // Diagonal  Esquerda baixo
            count ++;
        }
    }
}

void pintaSimboloYinYang(char matriz[linha][coluna], int quantidade){
        int i, j, count = 0, maxTentativa = 100;

    while ((count <  quantidade) && ( maxTentativa >= 1)){
        i = linhaAleatoria();
        j = colunaAleatoria();

        if(
        matriz[i-5][j] ==' ' && matriz[i-5][j-1] == ' '&& matriz[i-5][j-2] == ' '&& matriz[i-5][j+1] == ' '&& matriz[i-5][j+2] == ' '&& 
        matriz[i-5][j+3] == ' '&& matriz[i-4][j] == ' '&& matriz[i-4][j-1] == ' '&& matriz[i-4][j-2] == ' '&& matriz[i-4][j-3] == ' '&& 
        matriz[i-4][j+1] == ' '&& matriz[i-4][j+2] == ' '&& matriz[i-4][j+3] == ' '&& matriz[i-4][j+4] == ' '&& matriz[i-3][j-2] == ' '&& 
        matriz[i-3][j-3] == ' '&& matriz[i-3][j-4] == ' '&& matriz[i-3][j+1] == ' '&& matriz[i-3][j+2] == ' '&& matriz[i-3][j+3] == ' '&& 
        matriz[i-3][j+4] == ' '&& matriz[i-3][j+5] == ' '&& matriz[i-2][j-2] == ' '&& matriz[i-2][j-3] == ' '&& matriz[i-2][j-4] == ' '&& 
        matriz[i-2][j+1] == ' '&& matriz[i-2][j+2] == ' '&& matriz[i-2][j+5] == ' '&& matriz[i-1][j] == ' '&& matriz[i-1][j-1] == ' '&& 
        matriz[i-1][j-2] == ' '&& matriz[i-1][j-3] == ' '&& matriz[i-1][j-4] == ' '&& matriz[i-1][j+1] == ' '&& matriz[i-1][j+5] == ' '&& 
        matriz[i][j] == ' '&& matriz[i][j-1] == ' '&& matriz[i][j-2] == ' '&& matriz[i][j-3] == ' '&& matriz[i][j-4] == ' '&& 
        matriz[i][j+5] == ' '&& matriz[i+1][j-3] == ' '&& matriz[i+1][j-4] == ' '&& matriz[i+1][j+2] == ' '&& matriz[i+1][j+3] == ' '&& 
        matriz[i+1][j+5] == ' '&& matriz[i+2][j-2] == ' '&& matriz[i+2][j-3] == ' '&& matriz[i+2][j-4] == ' '&& matriz[i+2][j+2] == ' '&& 
        matriz[i+2][j+3] == ' '&& matriz[i+2][j+5] == ' '&& matriz[i+3][j-1] == ' '&& matriz[i+3][j-2] == ' '&& matriz[i+3][j-3] == ' '&& 
        matriz[i+3][j+4] == ' '&& matriz[i+4][j] == ' '&& matriz[i+4][j-1] == ' '&& matriz[i+4][j-2] == ' '&& matriz[i+4][j+1] == ' '&& 
        matriz[i+4][j+2] == ' '&& matriz[i+4][j+3] == ' '
        ){          

            
            matriz[i-5][j] = '*'; //Primeira linha do desenho
            matriz[i-5][j-1] = '*';
            matriz[i-5][j-2] = '*';
            matriz[i-5][j+1] = '*';
            matriz[i-5][j+2] = '*';
            matriz[i-5][j+3] = '*';


            matriz[i-4][j] = '*'; //segunda
            matriz[i-4][j-1] = '*';
            matriz[i-4][j-2] = '*';
            matriz[i-4][j-3] = '*';
            matriz[i-4][j+1] = '*';
            matriz[i-4][j+2] = '*';
            matriz[i-4][j+3] = '*';
            matriz[i-4][j+4] = '*';

            //matriz[i-3][j] = '*'; //terceira
            matriz[i-3][j-2] = '*';
            matriz[i-3][j-3] = '*';
            matriz[i-3][j-4] = '*';
            matriz[i-3][j+1] = '*';
            matriz[i-3][j+2] = '*';
            matriz[i-3][j+3] = '*';
            matriz[i-3][j+4] = '*';
            matriz[i-3][j+5] = '*';
            
            //matriz[i-2][j] = '*'; //quarta
            matriz[i-2][j-2] = '*';
            matriz[i-2][j-3] = '*';
            matriz[i-2][j-4] = '*';
            matriz[i-2][j+1] = '*';
            matriz[i-2][j+2] = '*';
            matriz[i-2][j+5] = '*';


            matriz[i-1][j] = '*'; //quinta
            matriz[i-1][j-1] = '*';
            matriz[i-1][j-2] = '*';
            matriz[i-1][j-3] = '*';
            matriz[i-1][j-4] = '*';
            matriz[i-1][j+1] = '*';
            matriz[i-1][j+5] = '*';

            matriz[i][j] = '*'; //meio do desenho
            matriz[i][j-1] = '*';
            matriz[i][j-2] = '*';
            matriz[i][j-3] = '*';
            matriz[i][j-4] = '*';
            matriz[i][j+5] = '*';

           // matriz[i+1][j] = '*'; //Primeira linha do meio para baixo
            matriz[i+1][j-3] = '*'; 
            matriz[i+1][j-4] = '*';
            matriz[i+1][j+2] = '*'; 
            matriz[i+1][j+3] = '*'; 
            matriz[i+1][j+5] = '*'; 
            
            
            //matriz[i+2][j] = '*'; //segunda
            matriz[i+2][j-2] = '*';
            matriz[i+2][j-3] = '*';
            matriz[i+2][j-4] = '*';
            matriz[i+2][j+2] = '*';
            matriz[i+2][j+3] = '*';
            matriz[i+2][j+5] = '*';

            //matriz[i+3][j] = '*'; //terceira
            matriz[i+3][j-1] = '*'; 
            matriz[i+3][j-2] = '*'; 
            matriz[i+3][j-3] = '*'; 
            matriz[i+3][j+4] = '*'; 

            matriz[i+4][j] = '*'; //quarta
            matriz[i+4][j-1] = '*';
            matriz[i+4][j-2] = '*';
            matriz[i+4][j+1] = '*';
            matriz[i+4][j+2] = '*';
            matriz[i+4][j+3] = '*';
            
            
            count ++;
        }
         maxTentativa -= 1;
    }
}

void pintaSimboloArroba(char matriz[linha][coluna], int quantidade){
        int i, j, count = 0, maxTentativa = 100;

    while (count <  quantidade && maxTentativa >= 0){
        i = linhaAleatoria();
        j = colunaAleatoria();

        if( 
            matriz[i-5][j] == ' ' &&matriz[i-5][j+1] == ' ' && matriz[i-5][j-1] == ' ' && matriz[i-5][j-2] == ' ' && matriz[i-5][j-3] == ' ' && 
            matriz[i-5][j-4] == ' ' && matriz[i-4][j+2] == ' ' && matriz[i-4][j-5] == ' ' && matriz[i-3][j+3] == ' ' && matriz[i-3][j-6] == ' ' && 
            matriz[i-2][j] == ' ' && matriz[i-2][j-2] == ' ' && matriz[i-2][j-3] == ' ' && matriz[i-2][j-6] == ' ' && matriz[i-2][j+3] == ' ' && 
            matriz[i-1][j] == ' ' && matriz[i-1][j-1] == ' ' && matriz[i-1][j-4] == ' ' && matriz[i-1][j-6] == ' ' && matriz[i-1][j+3] == ' ' && 
            matriz[i][j] == ' ' && matriz[i][j+3] == ' ' && matriz[i][j-4] == ' ' && matriz[i][j-6] == ' ' && matriz[i+1][j] == ' ' && 
            matriz[i+1][j+2] == ' ' && matriz[i+1][j-1]== ' ' && matriz[i+1][j-4] == ' ' && matriz[i+1][j-6] == ' ' && matriz[i+2][j+1] == ' ' && 
            matriz[i+2][j-1] == ' ' && matriz[i+2][j-2] == ' ' && matriz[i+2][j-3] == ' ' && matriz[i+2][j-6] == ' ' && matriz[i+3][j+3] == ' ' && 
            matriz[i+4][j] == ' ' && matriz[i+4][j+1] == ' ' && matriz[i+4][j+2] == ' ' && matriz[i+4][j-1] == ' ' && matriz[i+4][j-2] == ' ' && 
            matriz[i+4][j-3] == ' ' && matriz[i+4][j-4] == ' '){

            matriz[i-5][j] = '*';//primeira linha
            matriz[i-5][j+1] = '*';
            matriz[i-5][j-1] = '*';
            matriz[i-5][j-2] = '*';
            matriz[i-5][j-3] = '*';
            matriz[i-5][j-4] = '*';

            matriz[i-4][j+2] = '*';//2
            matriz[i-4][j-5] = '*';

            matriz[i-3][j+3] = '*';//3
            matriz[i-3][j-6] = '*';

            matriz[i-2][j] = '*';//4
            matriz[i-2][j-2] = '*';
            matriz[i-2][j-3] = '*';
            matriz[i-2][j-6] = '*';
            matriz[i-2][j+3] = '*';

            matriz[i-1][j] = '*';//5
            matriz[i-1][j-1] = '*';
            matriz[i-1][j-4] = '*';
            matriz[i-1][j-6] = '*';
            matriz[i-1][j+3] = '*';

            matriz[i][j] = '*'; //meio
            matriz[i][j+3] = '*';
            matriz[i][j-4] = '*';
            matriz[i][j-6] = '*';

            matriz[i+1][j] = '*';//1
            matriz[i+1][j+2] = '*';
            matriz[i+1][j-1] = '*';
            matriz[i+1][j-4] = '*';
            matriz[i+1][j-6] = '*';

            //matriz[i+2][j] = '*';//2
            matriz[i+2][j+1] = '*';
            matriz[i+2][j-1] = '*';
            matriz[i+2][j-2] = '*';
            matriz[i+2][j-3] = '*';
            matriz[i+2][j-6] = '*';

            matriz[i+3][j+3] = '*';//3
            matriz[i+3][j-5] = '*';


            matriz[i+4][j] = '*';//4
            matriz[i+4][j+1] = '*';
            matriz[i+4][j+2] = '*';
            matriz[i+4][j-1] = '*';
            matriz[i+4][j-2] = '*';
            matriz[i+4][j-3] = '*';
            matriz[i+4][j-4] = '*';

            count ++;
        }
        maxTentativa -=1;
    }
}

void pintaSimboloBatman(char matriz[linha][coluna], int quantidade){
        int i, j, count = 0,maxTentativa = 100;

    while ((count <  quantidade) && (maxTentativa >= 0)){
        i = linhaAleatoria();
        j = colunaAleatoria();

        if(
            matriz[i-2][j-4] == ' ' && matriz[i-2][j-5] == ' ' && matriz[i-2][j-6] == ' ' && matriz[i-2][j-7] == ' ' && matriz[i-2][j-8]== ' ' && 
            matriz[i-2][j-9] == ' ' && matriz[i-2][j-10] == ' ' && matriz[i-2][j-11] == ' ' && matriz[i-2][j-12] == ' ' && 
            matriz[i-2][j+4] == ' ' && matriz[i-2][j+5] == ' ' && matriz[i-2][j+6] == ' ' && matriz[i-2][j+7] == ' ' && matriz[i-2][j+8] == ' ' && 
            matriz[i-2][j+9]  == ' ' && matriz[i-2][j+10] == ' ' && matriz[i-2][j+11] == ' ' && matriz[i-2][j+12] == ' ' && matriz[i-1][j-1] == ' ' &&
            matriz[i-1][j-4] == ' ' && matriz[i-1][j-10] == ' ' && matriz[i-1][j-11] == ' ' && matriz[i-1][j+1] == ' ' && matriz[i-1][j+4] == ' ' && 
            matriz[i-1][j+10] == ' ' && matriz[i-1][j+11] == ' ' && matriz[i][j] == ' ' && matriz[i][j-1] == ' ' && matriz[i][j-3] == ' ' && 
            matriz[i][j-4] == ' ' && matriz[i][j-9] == ' ' && matriz[i][j-10] == ' ' && matriz[i][j+1] == ' ' && matriz[i][j+3] == ' ' && 
            matriz[i][j+4] == ' ' && matriz[i][j+9] == ' ' && matriz[i][j+10] == ' ' && matriz[i+1][j-1] == ' ' && matriz[i+1][j-2] == ' ' && 
            matriz[i+1][j-3] == ' ' && matriz[i+1][j-8] == ' ' && matriz[i+1][j-9] == ' ' && matriz[i+1][j+1] == ' ' && matriz[i+1][j+2] == ' ' && 
            matriz[i+1][j+3] == ' ' && matriz[i+1][j+8] == ' ' && matriz[i+1][j+9] == ' ' && matriz[i+2][j-8] == ' ' && matriz[i+3][j-8] == ' ' && 
            matriz[i+4][j-5] == ' ' && matriz[i+4][j-6] == ' ' && matriz[i+4][j-7] == ' ' && matriz[i+4][j-8] == ' ' && matriz[i+4][j+5] == ' ' && 
            matriz[i+4][j+6] == ' ' && matriz[i+4][j+7] == ' ' && matriz[i+4][j+8] == ' ' && matriz[i+5][j-3] == ' ' && matriz[i+5][j-4] == ' ' && 
            matriz[i+5][j-5] == ' ' && matriz[i+5][j+3] == ' ' && matriz[i+5][j+4] == ' ' && matriz[i+5][j+5] == ' ' && matriz[i+6][j-1] == ' ' && 
            matriz[i+6][j-2] == ' ' && matriz[i+6][j-3] == ' ' && matriz[i+6][j+1] == ' ' && matriz[i+6][j+2] == ' ' && matriz[i+6][j+3] == ' ' && 
            matriz[i+7][j] == ' ' && matriz[i+7][j-1] == ' ' && matriz[i+7][j+1] == ' ' && matriz[i+8][j] == ' ' 
        ){

                     
            //matriz[i-2][j] = '*';//2
            matriz[i-2][j-4] = '*';
            matriz[i-2][j-5] = '*';
            matriz[i-2][j-6] = '*';
            matriz[i-2][j-7] = '*';
            matriz[i-2][j-8] = '*';
            matriz[i-2][j-9] = '*';
            matriz[i-2][j-10] = '*';
            matriz[i-2][j-11] = '*';
            matriz[i-2][j-12] = '*';
            matriz[i-2][j+4] = '*';
            matriz[i-2][j+5] = '*';
            matriz[i-2][j+6] = '*';
            matriz[i-2][j+7] = '*';
            matriz[i-2][j+8] = '*';
            matriz[i-2][j+9] = '*';
            matriz[i-2][j+10] = '*';
            matriz[i-2][j+11] = '*';
            matriz[i-2][j+12] = '*';

            //matriz[i-1][j] = '*';//1
            matriz[i-1][j-1] = '*';
            matriz[i-1][j-4] = '*';
            matriz[i-1][j-10] = '*';
            matriz[i-1][j-11] = '*';
            matriz[i-1][j+1] = '*';
            matriz[i-1][j+4] = '*';
            matriz[i-1][j+10] = '*';
            matriz[i-1][j+11] = '*';

            
            matriz[i][j] = '*'; //meio
            matriz[i][j-1] = '*'; 
            matriz[i][j-3] = '*'; 
            matriz[i][j-4] = '*'; 
            matriz[i][j-9] = '*'; 
            matriz[i][j-10] = '*'; 
            matriz[i][j+1] = '*'; 
            matriz[i][j+3] = '*'; 
            matriz[i][j+4] = '*'; 
            matriz[i][j+9] = '*'; 
            matriz[i][j+10] = '*'; 

            //matriz[i+1][j] = '*';//1
            matriz[i+1][j-1] = '*';
            matriz[i+1][j-2] = '*';
            matriz[i+1][j-3] = '*';
            matriz[i+1][j-8] = '*';
            matriz[i+1][j-9] = '*';
            matriz[i+1][j+1] = '*';
            matriz[i+1][j+2] = '*';
            matriz[i+1][j+3] = '*';
            matriz[i+1][j+8] = '*';
            matriz[i+1][j+9] = '*';




            //matriz[i+2][j] = '*';//2
            matriz[i+2][j-8] = '*';
            matriz[i+2][j+8] = '*';


            //matriz[i+3][j] = '*';//3
            matriz[i+3][j-8] = '*';
            matriz[i+3][j+8] = '*';
            


            //matriz[i+4][j] = '*';//4
            matriz[i+4][j-5] = '*';
            matriz[i+4][j-6] = '*';
            matriz[i+4][j-7] = '*';
            matriz[i+4][j-8] = '*';
            matriz[i+4][j+5] = '*';
            matriz[i+4][j+6] = '*';
            matriz[i+4][j+7] = '*';
            matriz[i+4][j+8] = '*';

            //matriz[i+5][j] = '*';//5
            matriz[i+5][j-3] = '*';
            matriz[i+5][j-4] = '*';
            matriz[i+5][j-5] = '*';
            matriz[i+5][j+3] = '*';
            matriz[i+5][j+4] = '*';
            matriz[i+5][j+5] = '*';



            //matriz[i+6][j] = '*';//6
            matriz[i+6][j-1] = '*';
            matriz[i+6][j-2] = '*';
            matriz[i+6][j-3] = '*';
            matriz[i+6][j+1] = '*';
            matriz[i+6][j+2] = '*';
            matriz[i+6][j+3] = '*';

            matriz[i+7][j] = '*';//7
            matriz[i+7][j-1] = '*';
            matriz[i+7][j+1] = '*';
            matriz[i+8][j] = '*';//8
            count ++;
        }
        maxTentativa-=1;
    }
}