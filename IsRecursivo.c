/*
- Refaça a questão Is de forma recursiva.
- 4 métodos: verifica se a string é só vogais, só consoantes, um número
  inteiro, ou um número real. Saída: X1 X2 X3 X4 (SIM/NAO).
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
 * Verifica, recursivamente, se todos os caracteres a partir da posição i
 * são vogais.
 * @param texto a string a verificar
 * @param i a posição atual sendo checada
 * @return 1 se todos forem vogais, 0 caso contrário
 */
int somenteVogaisRec(char* texto, int i){
    if (i == minhaStrlen(texto)) { // caso base: fim da string
        return 1;
    }
    char c = texto[i];
    int ehVogal = (c=='a'||c=='e'||c=='i'||c=='o'||c=='u'||
                   c=='A'||c=='E'||c=='I'||c=='O'||c=='U');
    if (!ehVogal) {
        return 0;
    }
    return somenteVogaisRec(texto, i + 1);
}

/**
 * Método público que inicia a recursão a partir da posição 0.
 * @param texto a string a verificar
 * @return 1 se todos os caracteres forem vogais
 */
int somenteVogais(char* texto){
    return somenteVogaisRec(texto, 0);
}

/**
 * Verifica, recursivamente, se todos os caracteres a partir da posição i
 * são consoantes.
 * @param texto a string a verificar
 * @param i a posição atual sendo checada
 * @return 1 se todos forem consoantes, 0 caso contrário
 */
int somenteConsoantesRec(char* texto, int i){
    if (i == minhaStrlen(texto)) {
        return 1;
    }
    char c = texto[i];
    int ehLetra = (c>='a' && c<='z') || (c>='A' && c<='Z');
    int ehVogal = (c=='a'||c=='e'||c=='i'||c=='o'||c=='u'||
                   c=='A'||c=='E'||c=='I'||c=='O'||c=='U');
    if (!ehLetra || ehVogal) {
        return 0;
    }
    return somenteConsoantesRec(texto, i + 1);
}

int somenteConsoantes(char* texto){
    return somenteConsoantesRec(texto, 0);
}

/**
 * Verifica, recursivamente, se todos os caracteres a partir da posição i
 * são dígitos.
 * @param texto a string a verificar
 * @param i a posição atual sendo checada
 * @return 1 se todos forem dígitos, 0 caso contrário
 */
int ehInteiroRec(char* texto, int i){
    if (i == minhaStrlen(texto)) {
        return 1;
    }
    char c = texto[i];
    if (!(c >= '0' && c <= '9')) {
        return 0;
    }
    return ehInteiroRec(texto, i + 1);
}

int ehInteiro(char* texto){
    if (minhaStrlen(texto) == 0) { // string vazia não é número válido
        return 0;
    }
    return ehInteiroRec(texto, 0);
}

/**
 * Conta, recursivamente, quantos caracteres '.' existem a partir de i.
 * Soma o valor da posição atual (0 ou 1) com o resultado da chamada
 * recursiva, sem usar parâmetro acumulador.
 * @param texto a string a verificar
 * @param i a posição atual sendo checada
 * @return quantidade de pontos encontrados a partir de i
 */
int contarPontos(char* texto, int i){
    if (i == minhaStrlen(texto)) {
        return 0;
    }
    int atual = (texto[i] == '.') ? 1 : 0;
    return atual + contarPontos(texto, i + 1);
}

/**
 * Verifica, recursivamente, se todos os caracteres a partir de i são
 * dígitos ou o ponto decimal.
 * @param texto a string a verificar
 * @param i a posição atual sendo checada
 * @return 1 se todos forem dígito ou ponto, 0 caso contrário
 */
int soDigitoOuPontoRec(char* texto, int i){
    if (i == minhaStrlen(texto)) {
        return 1;
    }
    char c = texto[i];
    if (!((c >= '0' && c <= '9') || c == '.')) {
        return 0;
    }
    return soDigitoOuPontoRec(texto, i + 1);
}

int ehReal(char* texto){
    if (minhaStrlen(texto) == 0) {
        return 0;
    }
    return contarPontos(texto, 0) == 1 && soDigitoOuPontoRec(texto, 0);
}

int main(){
    char linha[1000];
    while(fgets(linha, 1000, stdin) != NULL){
        int tamanho = minhaStrlen(linha);
        if(linha[tamanho - 1] == '\n'){
            linha[tamanho - 1] = '\0';
        }

        printf("%s ", somenteVogais(linha) ? "SIM" : "NAO");
        printf("%s ", somenteConsoantes(linha) ? "SIM" : "NAO");
        printf("%s ", ehInteiro(linha) ? "SIM" : "NAO");
        printf("%s\n", ehReal(linha) ? "SIM" : "NAO");
    }
    return 0;
}