/*
- Método iterativo que recebe uma string invertida.
- Na saída padrão, para cada linha de entrada, escreva uma linha de string 
de saída.
*/

#include <stdio.h>
#include <stdlib.h>

/**
 * Inverte uma string, criando uma nova sem alterar a original.
 * Usa minhaStrlen para descobrir o tamanho da string recebida
 * e assim saber quanto de memória alocar e até onde percorrer.
 * @param string a string a ser invertida
 * @return uma nova string com os caracteres em ordem invertida
 */

 // receber um ponteiro char (ou seja, uma string) chamado s, e devolve um int (o tamanho dela)
 int minhaStrlen(char* s){
    int contador = 0; 
    while(s[contador] != '\0') { // enquanto nao for '\0', continua repetindo até dar false.
        contador++;
    }
    return contador;
 }

  
 char* inverter(char* string){ // receber uma string original ('string') e vai devolver ('char*') uma string nova, invertida.
    int tamanho = minhaStrlen(string); // chamar a função anterior para descobrir quantos caracteres 'string' tem.
    char* nova = (char*) malloc ((tamanho + 1) * sizeof(char)); // reservar memória suficiente para guardar 'tamanho' caracteres + 1 espaço extra pro '\0' final.
    // 'nova' guarda o endereço de onde essa memoria reservada começa

    // o for, preenchendo "nova" com os caracteres de "string" na ordem invertida.
    for(int i = 0; i < tamanho; i++) {
        nova[i] = string[tamanho - 1 - i]; // para cada i, pegar o carctere de string na posição espelhada: tamanho - 1 - i.
    }
    nova [tamanho] = '\0'; 
    return nova;
 }

 int main () {
    char linha [1000]; // array fixo até 999 carcteres + '\0' para guardar cada linha lida.
    while(fgets(linha, 1000, stdin) !=NULL){ // ler uma linha do teclado por vez. 'fgets' devolve 'NULL' quando a entrada acabar (fim do arquivo)
        int tamanho = minhaStrlen(linha);
        // descobrir o tamanho da linha lida e, se o ultimo carctere for uma quebra de linha('\n', que o 'fgets' inclui), substitui por '\0'.
        if(linha[tamanho - 1] == '\n'){ 
            linha[tamanho - 1] = '\0';
        }
        char* resultado = inverter(linha); // chamar a função de inversão, passando a linha ja limpa
        printf("%s\n", resultado); // imprimir o resultado
        free(resultado); // liberar memória que 'inverter' alocou no 'malloc'.
    }
    return 0;
 }