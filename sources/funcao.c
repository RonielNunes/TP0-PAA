/*
*   Programa: PROGRAMA GERADOR DE OBRA DE ARTE
*   Autor: Roniel Nunes Barbosa
*   Matéria: Projeto e Análise de Algoritmos
*   Professor: Daniel Mendes Barbosa
*       
*/

#include <stdlib.h>
#include <stdio.h>
#include "../headers/funcao.h"
#include "../headers/menu.h"

/*
    Função incializaQuadro, faz a criação inicial do quadro. Através das condições criadas foi conseguido limitar onde pintar com espaço vazio, ' ou |.
 Os espaço vazio no interrior do quadro, foi algo que serviu para usar nas condições de pintura nas funções seguintes. Através desse espaço, foi
 conseguido implementar condições que buscam lugares sem asterios de outras figuras já inseridas. 
*/

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

/*
    A função exibeQuadro, funcina simplesmente com a leitura dos dados presente na matriz. Ela exibe cada conteúdo presentes nos indices da mesma,
quebrado linha após a chegada na última coluna.
*/

void exibeQuadro(char matriz[linha][coluna]){

    for (int i = 0; i < linha; i++){
        printf("\n");
        for (int j = 0; j < coluna; j++){
            printf(" %c", matriz[i][j]);
        }
    }
}

/*
    A função linhaAleatoria, funciona com a delimitação dos espaços que podem ser usados para gerar a imagem. Nessa função, temos a escolha 
de um indice(i) aleatório da matriz. Além disso, limita-se o intervalo de 1 a 18 para que a imagem não colida com as bordas do quadro. 
*/

int linhaAleatoria(){
    int i = (1+( rand() %(linha -2)));
    return i;  //gera um i aleatorio no intervalo de 1 a 18.
}

/*
    A função colunaAleatoria, funciona com a delimitação dos espaços que podem ser usados para gerar a imagem. Nessa função, temos a escolha 
de um indice(j) aleatório da matriz. Além disso, limita-se o intervalo de 1 a 78 para que a imagem não colida com as bordas do quadro. 
*/

int colunaAleatoria(){
    int j = (1+( rand() %(coluna - 2)));
    return j; //Gera um j aleatorio no intervalo de 1 a 78. 
}

/*
    O verificaQuantidade, é o tratamento de quantidade de imagens permitida no quadro. Se a quatidade for menor que ou igual a zero, temos um sorteio
para uma nova quantidade de 1 a 100. Caso a quantidade incial, seja maior que 100, temos setado que o limite será 100.
*/

void verificaQuantidade(int *quantidade){
    
    if ((*quantidade) <= 0)
        (*quantidade) = 1 + rand()%100;
    else if((*quantidade) > 100)
        (*quantidade) = 100;
    else
        return;
}

/*
    O verificaQuantidadeYinYang, é o tratamento de quantidade de imagens permitida no quadro referentes ao yan yang. Se a quatidade for menor que ou 
igual a zero, temos um sorteio para uma nova quantidade de 1 a 6. Caso a quantidade incial, seja maior que 100, temos setado que o limite será 6.
*/

void verificaQuantidadeYinYang(int *quantidade){
    
    if ((*quantidade) <= 0)
        (*quantidade) = 1 + rand()%5;
    else if((*quantidade) > 100)
        (*quantidade) = 6;
}

/*
    O verificaQuantidadeArroba, é o tratamento de quantidade de imagens permitida no quadro referentes ao Arroba. Se a quatidade for menor que ou 
igual a zero, temos um sorteio para uma nova quantidade de 1 a 7. Caso a quantidade incial, seja maior que 100, temos setado que o limite será 7.
*/

void verificaQuantidadeArroba(int *quantidade){
    
    if ((*quantidade) <= 0)
        (*quantidade) = 1 + rand()%6;
    else if((*quantidade) > 100)
        (*quantidade) = 7;
}

/*
    O verificaQuantidadeArroba, é o tratamento de quantidade de imagens permitida no quadro referentes ao Simbolo do batman. Se a quatidade for menor que ou 
igual a zero, temos um sorteio para uma nova quantidade de 1 a 3. Caso a quantidade incial, seja maior que 100, temos setado que o limite será 3.
*/

void verificaQuantidadeBatman(int *quantidade){
    
    if ((*quantidade) <= 0)
        (*quantidade) = 1 + rand()% 2;
    else if((*quantidade) > 100)
        (*quantidade) = 3;
}


/*
    A função pinturaMista é utilizada no case 4, ela funciona com a geração de uma quantidade aleatorias para as 3 primeiras artes(asteriscos,
soma e X). Ela faz a criação de três valores aleatórios a soma envolvendo os três tem que ser igual a quantidade pedida pelo usuario, 
caso, a quantidade pedida seja menor que três é feito um sorteio para cada um considerando o intervalode um a três, nesse momento é 
enviado uma mensagem no terminal inidcando que o número será aleatorio. Após o final dos números aleatorio, e feito a utilização das funções
auxiliares : quantidadeTintaAsterisco, quantidadeTintaSoma e quantidadeTintaX. Concluindo com a exibição da obra gerada. 
*/

void pinturaMista(char matriz[linha][coluna],int quantidade){
    int quantidadeTintaAsterisco = 0, quantidadeTintaSoma = 0,quantidadeTintaX = 0;
    if (quantidade >=3){
         while ((quantidadeTintaAsterisco + quantidadeTintaSoma + quantidadeTintaX) != quantidade){
            quantidadeTintaAsterisco = 1+ rand() % quantidade;
            quantidadeTintaSoma = 1+ rand() % quantidade;
            quantidadeTintaX = 1+ rand() % quantidade;
        }
    }else{
        printf("\nQuantidade inferior que 3. Quantidade aleatoria ativada.\n");
        quantidadeTintaAsterisco = 1+ rand() % 3;
        quantidadeTintaSoma = 1+ rand() % 3;
        quantidadeTintaX = 1+ rand() % 3;
    }

    pintaSimboloAsterisco(matriz,quantidadeTintaAsterisco);
    pintaSimboloSoma(matriz,quantidadeTintaSoma);
    pintaSimboloX(matriz,quantidadeTintaX);
    exibeQuadro(matriz);
}

/*
   A função pintaSimboloAsterisco, tem como parametros a matriz e a quantidade. A pintaSimboloAsterisco utilizando as seguintes condições, uma 
variável chamada count é usada para conferir se a quantidade de asteriscos preenchidos é igual a quantidade total de asteriscos recebida
do usuário. Utitizando a função linhaAleatoria para gerar um número aleatorio entre 1 e 18 para i e a utilizando  a colunaAleatoria para gerar de 
1 a 78 para j, esses intervalos foram escolhidos pois não compõem as bordas do quadro. Então conferimos se o espaço da matriz é um espaço
vazio e se for um espaço vazio, preenchemos com um asteriscos e  incrementamos +1 na quantidade de asteriscos preenchidos. Deste modo, 
é feito a inserção do asterisco na posição desejada. 
*/

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

/*
    A função pintaSimboloSoma, funciona da mesma maneira que a anterior. Sendo diferente simplesmente na sua condição de verificação e 
caso atendida é feito a pintura utilizando mais posições devido se tratar de uma imagem mais complexa. 
*/

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

/*
    A função pintaSimboloX, funciona da mesma maneira que a anterior. Sendo diferente simplesmente na sua condição de verificação e caso atendida
é feito a pintura utilizando mais posições devido se tratar de uma imagem mais complexa. 
*/

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


/*

    Essas últimas três funções que são: pintaSimboloYinYang, pintaSimboloArroba e pintaSimboloBatman. Tem o mesmo funcionamento supracitado das funções 
anteriores, seu diferencial é na questão de se tratar de imagem mais elaboradas, dando em si uma maior quantidade de condições a serem 
atendidas para gerar o seu preenchimento no quadro.

*/

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