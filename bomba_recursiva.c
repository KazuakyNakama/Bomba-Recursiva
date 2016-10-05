#include <stdio.h>

/* bomba_recursiva.c
 *
 * dados o mapa e a pot�ncia da bomba recursiva, informe em que
 * posi��o essa bomba deve ser lan�ada para causar o maior estrago (destruir o maior n�mero de alvos).
 *
 *
 * Luiz Fernando Kazuaky Nakama (Ci�ncias da Computa��o)
 * Caio Cesar Lopes Teles de Menezes (Ci�ncias da Computa��o)
 * Victor de Almeida Chagas (Ci�ncias da Computa��o)
 *
 *
 * �ltima Data de Modifica��o: 07/06/2016
 */

int recursao(int, int, int, int, int, int [][*]);

int main()
{
    int i, j, l, c, p, x = -1, y = -1, d = 0, cont = 0;    //Se n�o houver nenhuma destrui��o, x e y retornam -1

    scanf("%d %d %d", &l, &c, &p);    //N�mero de linhas, colunas e pot�ncia da bomba

    int matriz[l][c];
    for(i = 0; i < l; i++){
        for(j = 0; j < c; j++){
            scanf("%d", &matriz[i][j]);
        }
    }

    for(i = 0; i < l; i++){
        for(j = 0; j < c; j++){
            cont = recursao(l, c, p, i, j, matriz);    //cont recebe a quantidade de c�lulas destru�das
            if(cont > d){    //Se a quantidade de celulas destru�das for maior que a das verifica��es anteriores, ent�o:
                x = i;       //x recebe o �ndice da linha
                y = j;       //y recebe o �ndice da coluna
                d = cont;    //d recebe a quantidade de celulas destru�das
            }
        }
    }
    printf("%d %d %d\n", x, y, d);

    return 0;
}

/* Fun��o que recebe como par�metros a quantidade de linhas e colunas estabelecidas e
 * a pot�ncia da bomba. Recebe tamb�m A linha e a coluna em que ser� verificada e a matriz,
 * retorna cont com a quantidade total de destrui��o das c�lulas.
 */
int recursao(int l, int c, int p, int i, int j, int matriz[l][c])
{
    int cont = 0;

    if(matriz[i][j] < p && matriz[i][j] > -1){    //Se a c�lula for menor que a pot�ncia da bomba e se a c�lula ainda n�o foi destru�da, ent�o:
        matriz[i][j] = -1;    //A c�lula recebe -1 para indicar que foi destru�da
        cont++;    //cont � incrementado, pois houve a destrui��o de uma c�lula
        //Caso as verifica��es abaixo sejam executadas, cont � somado com o retorno da fun��o recursao com os vizinhos da c�lula como par�metros
        if(i > 0) cont += recursao(l, c, p, i - 1, j, matriz);    //Se n�o for a primeira linha da matriz, a verifica��o � feita com a linha anterior
        if(i < l - 1) cont += recursao(l, c, p, i + 1, j, matriz);    //Se n�o for a �ltima linha da matriz, a verifica��o � feita com a linha posterior
        if(j > 0) cont += recursao(l, c, p, i, j - 1, matriz);    //Se n�o for a primeira coluna da matriz, a verifica��o � feita com a coluna anterior
        if(j < c - 1) cont += recursao(l, c, p, i, j + 1, matriz);    //Se n�o for a �ltima coluna da matriz, a verifica��o � feita com a coluna posterior
    }
    return cont;
}
