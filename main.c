#include <stdio.h>
#include <stdlib.h>
#include <./headers/machineArts.h>
#include <./headers/menu.h>

//gcc -o teste main.c ./headers/machineArts.h ./headers/machineArts.c ./headers/menu.h ./headers/menu.

int main(int argc, char const *argv[])
{
    char matriz[linha][coluna];

    inicializaQuadro(matriz[linha][coluna]);
    exibeMatriz(matriz[linha][coluna]);
    
    return 0;
}
