/*
- Método recursivo que recebe um número inteiro como parâmetro e retorna a 
soma dos dígitos.
- Na saída padrão, para cada linha de entrada, escreva uma linha de saída com o 
resultado da soma dos dígitos.
- Exemplo: ENTRADA     SAÍDA
           12345         15
- Caso base + caso geral (if/else) em todo método recursivo.
- Função acumuladora (ou somador).
*/

#include <stdio.h>
#include <stdlib.h>

/**
 * Calcula a soma dos dígitos de um número inteiro, de forma recursiva.
 * Não usa a técnica dos dois métodos porque o próprio número, diminuindo
 * a cada chamada (n / 10), já funciona como controle da recursão
 * (não é necessário nenhum índice ou contador adicional).
 * @param n o número cujos dígitos serão somados
 * @return a soma dos dígitos de n
*/

int somaDigitos(int n){
    if (n < 10) { // caso base: quando 'n' é menor que 10, ou seja so tem 1 dígito (no caso, a soma dos dígitos é o próprio número)
        return n;
    } else {
        return (n % 10) + somaDigitos(n / 10); 
    // caso geral: 'n % 10' pega o resto da divisão por 10, que é sempre o último dígito do número. soma isso com o resultado de chamar a função de novo, só que com 'n / 10'.
    }
}

int main () {

    int n; // variável para armazenar o número lido a cada linha

    // o 'while' lê cada número da entrada padrão um por um e continua rodando até chegar no fim do arquivo (EOF - End of File)
    while (scanf("%d", &n) != EOF) {
        int resultado = somaDigitos(n); // chama a função recursiva para somar os dígitos 
        printf("%d\n", resultado); // imprime o resultado da soma na saída padrão 
    }
    return 0;
}


