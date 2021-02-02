//Roniel Nunes Barbosa
#define linha 20
#define coluna 80

void inicializaQuadro(char matriz[linha][coluna]);
void exibeQuadro(char matriz[linha][coluna]);
void pintaSimboloAsterisco(char matriz[linha][coluna], int quantidade);
void pintaSimboloSoma(char matriz[linha][coluna], int quantidade);
void pintaSimboloX(char matriz[linha][coluna], int quantidade);
void pintaSimboloYngAng(char matriz[linha][coluna], int quantidade);
int linhaAleatoria();
int colunaAleatoria();
void verificaQuantidade(int *quantidade);