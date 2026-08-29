/*
- Refazer a questão Ciframento de César de forma recursiva.
- Chave de ciframento: 3. Desloca cada letra 3 posições no alfabeto.
- Na saída padrão, para cada linha de entrada, escreva uma linha com a
  mensagem criptografada.
*/

#include <stdio.h>
#include <stdlib.h>

/**
 * Calcula o comprimento de uma string, contando os caracteres até
 * encontrar o caractere nulo '\0'. 
 * @param s a string cujo tamanho será calculado
 * @return o número de caracteres antes do '\0'
 */
int minhaStrlen(char* s){
    int contador = 0;
    while(s[contador] != '\0'){
        contador++;
    }
    return contador;
}

/**
 * Método recursivo auxiliar: cifra um caractere por vez, avançando pelo índice i,
 * e concatena com o resultado da chamada recursiva para o restante da string.
 * @param string a string a ser cifrada
 * @param i a posição atual sendo processada
 * @return a string cifrada a partir da posição i até o final
 */
char* cifrarRecursivo(char* string, int i){
    int tamanho = minhaStrlen(string);

    // caso base: chegou ao fim da string, não há mais nada para cifrar
    if (i == tamanho) {
        char* vazia = (char*) malloc(1 * sizeof(char)); // aloca só o espaço do '\0'
        vazia[0] = '\0';
        return vazia; // devolve uma string vazia, encerrando a recursão
    }

    // caso geral: cifra o caractere da posição atual (i)
    char c = string[i];
    if (c >= 'a' && c <= 'z') {
        c = (c - 'a' + 3) % 26 + 'a'; // desloca 3 posições, minúscula
    } else if (c >= 'A' && c <= 'Z') {
        c = (c - 'A' + 3) % 26 + 'A'; // desloca 3 posições, maiúscula
    }
    // se não for letra, "c" permanece igual, sem alteração

    // chama a si mesma para cifrar o restante da string (posições i+1 em diante)
    char* resto = cifrarRecursivo(string, i + 1);
    int tamResto = minhaStrlen(resto);

    // monta o resultado final: o caractere cifrado "c" na frente + o "resto" já cifrado
    char* resultado = (char*) malloc((tamResto + 2) * sizeof(char));
    resultado[0] = c; // coloca o caractere cifrado na primeira posição
    for (int k = 0; k < tamResto; k++) {
        resultado[k + 1] = resto[k]; // copia o restante já cifrado logo em seguida
    }
    resultado[tamResto + 1] = '\0'; // fecha a string nova

    free(resto); // libera a memória da chamada recursiva anterior, já copiada
    return resultado;
}

/**
 * Método público que recebe a string a ser cifrada e chama o método
 * recursivo, iniciando o índice em 0 (segue a técnica dos dois métodos).
 * @param string a string a ser cifrada
 * @return a string cifrada
*/

char* cifrar(char* string){
    return cifrarRecursivo(string, 0); // inicia a recursão a partir da posição 0
}

int main(){
    char linha[1000];
    while(fgets(linha, 1000, stdin) != NULL){ // lê uma linha por vez até o fim da entrada
        int tamanho = minhaStrlen(linha);
        if(linha[tamanho - 1] == '\n'){ // remove a quebra de linha, se houver
            linha[tamanho - 1] = '\0';
        }
        char* resultado = cifrar(linha); // chama o método público (que inicia a recursão)
        printf("%s\n", resultado);
        free(resultado); // libera a memória alocada ao longo de toda a recursão
    }
    return 0;
}