/*
- Método iterativo que recebe DUAS strings como parâmetros e retorna true 
se as strings são anagramas, ou false caso contrário.
- Na saída padrão, para cada par de strings de entrada, escrever uma linha de saída 
com SIM/NÃO indicando se as strings são anagramas ou não.
- Exemplo: ENTRADAS      SAÍDAS
            listen         SIM
            silent         SIM
*/

#include <stdio.h>
#include <stdlib.h>

/**
 * Verifica se duas strings são anagramas, comparando a frequência de
 * cada letra entre elas usando um vetor de contagem de 26 posições
 * (uma para cada letra do alfabeto, ignorando acentos e cedilha).
 * Retorna 1 se forem anagramas, ou 0 caso contrário.
 * @param str1 a primeira string a ser comparada
 * @param str2 a segunda string a ser comparada
 * @return 1 se as strings forem anagramas, 0 caso contrário
 */
int saoAnagramas(char str1[], char str2[]){

    // conta manualmente o tamanho da primeira string
    int tam1 = 0;
    while(str1[tam1] != '\0') {
        tam1++;
    }

    // conta manualmente o tamanho da segunda string
    int tam2 = 0;
    while(str2[tam2] != '\0'){
        tam2++;
    }

    // se os tamanhos forem diferentes, não são anagramas
    if (tam1 != tam2) {
        return 0; // falso
    }

    // vetor de frequência: uma posição para cada letra do alfabeto (a-z)
    int contagem[26] = {0}; // {0} zera todas as 26 posições

    
    for(int i = 0; i < tam1; i++) {
        
    // pega o caractere de cada string na posição i, calcula sua posição
    // no alfabeto (0-25) e soma 1 no vetor para str1, subtrai 1 para str2.
    // se as strings forem anagramas, tudo se cancela e o vetor fica zerado.
        char c1 = str1[i];
        if (c1 >= 'a' && c1 <= 'z') {
            contagem[c1 - 'a']++;
        } else if (c1 >= 'A' && c1 <= 'Z') {
            contagem[c1 - 'A']++;
        }

        char c2 = str2[i];
        if (c2 >= 'a' && c2 <= 'z') {
            contagem[c2 - 'a']--;
        } else if (c2 >= 'A' && c2 <= 'Z') {
            contagem[c2 - 'A']--;
        }
    }

    // se sobrar algum valor diferente de 0, as letras não batem
    for(int i = 0; i < 26; i++){
        if (contagem[i] != 0){
            return 0; // falso
        }
    }
    return 1; // verdadeiro
}

int main() {
    char str1[100];
    char str2[100];

    // lê os pares de strings até o final da entrada (EOF)
    while(scanf("%s %s", str1, str2) != EOF){
        if(saoAnagramas(str1, str2)){
            printf("SIM\n");
        } else {
            printf("NAO\n");
        }
    }
    return 0;
}