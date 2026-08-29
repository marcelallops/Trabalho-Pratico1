/*
- Refaça a questão Ciframento de César de forma recursiva.
- Chave de ciframento: 3. Desloca cada letra 3 posições no alfabeto.
- Na saída padrão, para cada linha de entrada, escreva uma linha com a
 mensagem criptografada.
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

char* cifrarRecursivo(char* string, int i){
    int tamanho = minhaStrlen(string);

    if (i == tamanho) {
        char* vazia = (char*) malloc(1 * sizeof(char));
        vazia[0] = '\0';
        return vazia;
    }

    char c = string[i];
    if (c >= 'a' && c <= 'z') {
        c = (c - 'a' + 3) % 26 + 'a';
    } else if (c >= 'A' && c <= 'Z') {
        c = (c - 'A' + 3) % 26 + 'A';
    }

    char* resto = cifrarRecursivo(string, i + 1);
    int tamResto = minhaStrlen(resto);

    char* resultado = (char*) malloc((tamResto + 2) * sizeof(char));
    resultado[0] = c;
    for (int k = 0; k < tamResto; k++) {
        resultado[k + 1] = resto[k];
    }
    resultado[tamResto + 1] = '\0';

    free(resto);
    return resultado;
}

char* cifrar(char* string){
    return cifrarRecursivo(string, 0);
}

int main(){
    char linha[1000];
    while(fgets(linha, 1000, stdin) != NULL){
        int tamanho = minhaStrlen(linha);
        while (tamanho > 0 && (linha[tamanho-1] == '\n' || linha[tamanho-1] == '\r')) {
            linha[tamanho-1] = '\0';
            tamanho--;
        }
        char* resultado = cifrar(linha);
        printf("%s\n", resultado);
        free(resultado);
    }
    return 0;
}