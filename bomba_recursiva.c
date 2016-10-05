#include <stdio.h>

/* bomba_recursiva.c
 *
 * dados o mapa e a potência da bomba recursiva, informe em que
 * posição essa bomba deve ser lançada para causar o maior estrago (destruir o maior número de alvos).
 *
 *
 * Luiz Fernando Kazuaky Nakama (Ciências da Computação)
 * Caio Cesar Lopes Teles de Menezes (Ciências da Computação)
 * Victor de Almeida Chagas (Ciências da Computação)
 *
 *
 * Última Data de Modificação: 07/06/2016
 */

int recursao(int, int, int, int, int, int [][*]);

int main()
{
    int i, j, l, c, p, x = -1, y = -1, d = 0, cont = 0;    //Se não houver nenhuma destruição, x e y retornam -1

    scanf("%d %d %d", &l, &c, &p);    //Número de linhas, colunas e potência da bomba

    int matriz[l][c];
    for(i = 0; i < l; i++){
        for(j = 0; j < c; j++){
            scanf("%d", &matriz[i][j]);
        }
    }

    for(i = 0; i < l; i++){
        for(j = 0; j < c; j++){
            cont = recursao(l, c, p, i, j, matriz);    //cont recebe a quantidade de células destruídas
            if(cont > d){    //Se a quantidade de celulas destruídas for maior que a das verificações anteriores, então:
                x = i;       //x recebe o índice da linha
                y = j;       //y recebe o índice da coluna
                d = cont;    //d recebe a quantidade de celulas destruídas
            }
        }
    }
    printf("%d %d %d\n", x, y, d);

    return 0;
}

/* Função que recebe como parâmetros a quantidade de linhas e colunas estabelecidas e
 * a potência da bomba. Recebe também A linha e a coluna em que será verificada e a matriz,
 * retorna cont com a quantidade total de destruição das células.
 */
int recursao(int l, int c, int p, int i, int j, int matriz[l][c])
{
    int cont = 0;

    if(matriz[i][j] < p && matriz[i][j] > -1){    //Se a célula for menor que a potência da bomba e se a célula ainda não foi destruída, então:
        matriz[i][j] = -1;    //A célula recebe -1 para indicar que foi destruída
        cont++;    //cont é incrementado, pois houve a destruição de uma célula
        //Caso as verificações abaixo sejam executadas, cont é somado com o retorno da função recursao com os vizinhos da célula como parâmetros
        if(i > 0) cont += recursao(l, c, p, i - 1, j, matriz);    //Se não for a primeira linha da matriz, a verificação é feita com a linha anterior
        if(i < l - 1) cont += recursao(l, c, p, i + 1, j, matriz);    //Se não for a última linha da matriz, a verificação é feita com a linha posterior
        if(j > 0) cont += recursao(l, c, p, i, j - 1, matriz);    //Se não for a primeira coluna da matriz, a verificação é feita com a coluna anterior
        if(j < c - 1) cont += recursao(l, c, p, i, j + 1, matriz);    //Se não for a última coluna da matriz, a verificação é feita com a coluna posterior
    }
    return cont;
}
