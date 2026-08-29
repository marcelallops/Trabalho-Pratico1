
/*
- Método iterativo que recebe uma string como parâmetro e retorna o 
comprimento da substring mais longa sem caracteres repetidos.
- Na saída padrão, para cada linha de entrada, escrever uma linha de saída 
com o comprimento da substring mais longa sem repetição.
- EXEMPLO: ENTRADA      SAÍDA
           abcabcbb       3    (correspondendo à substring "abc")
*/

#include <stdio.h>
#include <stdlib.h>

int minhaStrlen(char* s){
    int contador = 0;
    while(s[contador] != '\0'){
        contador++;
    }
    return contador;
}

/**
 * Verifica se o caractere na posição j já aparece em alguma posição
 * entre i e j-1 (ou seja, se já existe dentro da janela atual).
 * @param texto a string sendo analisada
 * @param i o início da janela atual
 * @param j a posição do caractere novo, sendo testado
 * @return 1 se o caractere em j já existir na janela, 0 caso contrário
 */
int existeRepetido(char* texto, int i, int j) {
    for (int k = i; k < j; k++) { // percorre cada posição já dentro da janela
        if (texto[k] == texto[j]) { // compara com o caractere novo (j)
            return 1; // achou repetição, não precisa continuar procurando
        }
    }
    return 0; // percorreu tudo sem achar repetição
}

/**
 * Calcula o comprimento da maior substring sem caracteres repetidos.
 * Usa a técnica de janela deslizante: para cada posição inicial i,
 * estende j enquanto não houver repetição dentro da janela [i, j].
 * @param texto a string a ser analisada
 * @return o comprimento da maior substring sem repetição
 */
int maiorSemRepeticao(char* texto) {
    int tamanho = minhaStrlen(texto);
    int maior = 0; // guarda o maior tamanho de janela encontrado até agora

    for (int i = 0; i < tamanho; i++) { // i é o início da janela
        int j = i; // j é o fim da janela, começa igual a i
        while (j < tamanho && !existeRepetido(texto, i, j)) {
            j++; // estende a janela enquanto não achar repetição
        }
        int tamanhoJanela = j - i; // calcula o tamanho da janela atual
        if (tamanhoJanela > maior) {
            maior = tamanhoJanela; // atualiza o maior, se essa janela for maior
        }
    }
    return maior;
}

int main() {
    char linha[1000];
    while(fgets(linha, 1000, stdin) != NULL){ // lê linha por linha até o fim da entrada
        int tamanho = minhaStrlen(linha);
        if(linha[tamanho - 1] == '\n'){
            linha[tamanho - 1] = '\0';
        }
        printf("%d\n", maiorSemRepeticao(linha)); // imprime o resultado da análise
    }
    return 0;
}