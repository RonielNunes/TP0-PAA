/*
*   Programa: PROGRAMA GERADOR DE OBRA DE ARTE
*   Autor: Roniel Nunes Barbosa
*   Matéria: Projeto e Análise de Algoritmos
*   Professor: Daniel Mendes Barbosa
*       
*/
#define linha 20
#define coluna 80

/*
    Funções usadas para interagir com o main. 
*/

void inicializaQuadro(char matriz[linha][coluna]);
void exibeQuadro(char matriz[linha][coluna]);
void pintaSimboloAsterisco(char matriz[linha][coluna], int quantidade);
void pintaSimboloSoma(char matriz[linha][coluna], int quantidade);
void pintaSimboloX(char matriz[linha][coluna], int quantidade);
void pinturaMista(char maitriz[linha][coluna],int quantidade);
void pintaSimboloYinYang(char matriz[linha][coluna], int quantidade);
void pintaSimboloArroba(char matriz[linha][coluna], int quantidade);
void pintaSimboloBatman(char matriz[linha][coluna], int quantidade);
int linhaAleatoria();
int colunaAleatoria();
void verificaQuantidade(int *quantidade);
void verificaQuantidadeYinYang(int *quantidade);
void verificaQuantidadeArroba(int *quantidade);
void verificaQuantidadeBatman(int *quantidade);
