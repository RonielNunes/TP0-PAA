# TP0-PAA


Este trabalho é individual e você deverá criar um programa para gerar obras de arte aleatórias. Para isso o programa deverá imprimir um quadro na tela de 20 linhas por 80 colunas. Na primeira e última linhas deverão ser impresso o símbolo '-' em todas as 80 colunas. Na primeira e última coluna deverá ser impresso o símbolo '|' em todas as linhas, com exceção da primeira e última que já irão conter o símbolo '-'. Desta forma estará delimitado o quadro para a obra de arte aparecer.

A obra de arte deverá ser gerada a partir de 3 figuras básicas:

Asterisco simples:    

*
                                                              
Símbolo de soma com asteriscos:         

 *
***
 *

Letra X com asteriscos: 

* *
 *
* *

No início do programa, o usuário irá escolher qual tipo de figura básica irá utilizar em seu quadro. Poderá escolher apenas uma das três, ou então uma mistura aleatória das três. Logo em seguida irá escolher quantas figuras serão utilizadas para a geração do quadro. Se o usuário digitar um número menor ou igual a zero, será gerado um número de figuras aleatório entre 1 e 100. Se o usuário digitar um número maior do que 100, será considerado o número 100. Exemplo de menu inicial do programa com estas opções (o que está sublinhado foram os dados digitados pelo usuário):

PROGRAMA GERADOR DE OBRA DE ARTE:
=================================
Escolha o tipo de figura basica a ser usada para criar a obra:
1 - asterisco simples.
2 - simbolo de soma com asteriscos.
3 - letra X com asteriscos.
4 - figuras aleatorias
5 ou qualquer outro numero – opcao de obra de arte criada pelo aluno
Digite o tipo de figura basica desejada: 1
Digite a quantidade de figuras (menor ou igual a zero para aleatorio): 5
Após a digitação destas opções o programa irá então gerar e imprimir na tela o quadro, solicitando ao final a opção de fazer um novo quadro com estes mesmos valores. O novo quadro poderá ser diferente, uma vez que a posição em que cada figura será colocada no quadro sempre é aleatória. Se a posição aleatória gerada já estiver ocupada por uma figura gerada anteriormente, uma nova posição aleatória deverá ser gerada. Não pode haver conflito com nenhuma parte das figuras anteriores, nem mesmo com um único asterisco. Outra restrição é que todas as figuras devem aparecer completamente (não pode ser impresso por exemplo um pedaço de uma letra X), e sempre dentro do quadro delimitado pelos símbolos '-' e '|'.

A opção 5 deverá ser criada pelo aluno, criando uma obra de arte específica, inventada pelo aluno, sendo obviamente diferente dos demais alunos. A criatividade será avaliada, e esta opção deverá ser feita de uma forma que obrigatoriamente também utilize números aleatórios. A utilização de números aleatórios não precisa ficar restrita a apenas as posições em que aparecerão as figuras, podendo também influenciar nas próprias figuras geradas.

Exemplos de saída:
Valores: tipo de figura: 1, número de figuras: 50
--------------------------------------------------------------------------------
|*   *                                                   *                     |
|           * *                                                                |
|        *     *                                                *              |
|                             *                     *                          |
|                                         *                                    |
|                **                *                                         * |
|                                                 *                           *|
|                                  *                             *             |
|*                 *            * *                                      *     |
|                                   * **                                       |
|                 *                                          *                 |
|*                                                                 *   *       |
|      *            *                       *                                  |
|                                                                    *         |
|                *           *                      *                          |
|    *               *                     *                       *           |
|       *           *          **                       *                      |
|                                                 *                       *    |
--------------------------------------------------------------------------------
Valores: tipo de figura: 2, número de figuras: 20
--------------------------------------------------------------------------------
|                                                                              |
|                                           *                  *               |
|                                          ***                ***              |
|                                           *                  *               |
|                                                     *                        |
|     *                                              ***             *         |
| *  ***                                              *  *          ***        |
|***  *                                             *   ***          *         |
| *                                                ***   *                     |
|      *                                            *                          |
|     ***      *                                                               |
|      *      ***             *              *          *   *                  |
|              *             ***            ***        *** ***                 |
|    *       *                *            * *          *   *                  |
|   ***     ***             *             ***  *                               |
|    *       *             ***          *  *  ***                              |
|                           *          ***     *                               |
|                                       *                                      |
--------------------------------------------------------------------------------


Valores: tipo de figura: 3, número de figuras: 15
--------------------------------------------------------------------------------
|* *                                                                           |
| *    * *                                 * *  * *    * *                     |
|* *    *                                   *    *      *                      |
|      * *                                 * *  * *    * *                     |
|                                                                              |
|                                  * *    * * * *                              |
|                                   *      *   *                               |
|                                  * *    * * * *                              |
|                                                                         * *  |
|                * *                                       * *             *   |
|                 *                * *                      *      * *    * *  |
|                * *     * *        *                      * *      *  * *     |
|                         *        * *                             * *  *      |
|                        * *                                           * *     |
|                                                                              |
|                                                                              |
|                                                                              |
|                                                                              |
--------------------------------------------------------------------------------


Valores: tipo de figura: 4, número de figuras: 10
--------------------------------------------------------------------------------
|                                                                              |
|                                                                              |
|               * *                                                            |
|                *                                  * *                        |
|               * *                                  *                         |
|                                                   * *                        |
|                                *                                             |
|                               ***                                            |
|                                *                    *                        |
|                                                                              |
|                                                                              |
|               *                                                      *       |
|              ***                   * *                                       |
|               *                     *                        *               |
|                                    * *                      ***              |
|     * * * *                                                  *               |
|      *   *                                                                   |
|     * * * *                                                                  |
--------------------------------------------------------------------------------
