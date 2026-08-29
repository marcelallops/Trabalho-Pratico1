/*
- Para cada caractere de string, se for letra, desloco 
3 posições para frente no alfabeto.
- Minúsculas: 'a' -> 'd', 'b'-> 'e', 'c' -> 'f'... 
- Maiúsculas: 'A' -> 'D', 'B' -> 'E', 'C' -> 'F'...
- Criar um iterativo que recebe uma string como parâmetro e retorna a
outra contendo a entrada de forma cifrada. 
Tabela ASCII - de 'a' a 'z' = 97 a 122.
             - de 'A' a 'Z' = 65 a 90.

*/

#include <stdio.h>
#include <stdlib.h>

/**
 * Calcula o comprimento de uma string, contando os caracteres até
 * encontrar o caractere nulo '\0'. Reimplementação própria porque
 * strlen() de string.h não é permitido neste trabalho.
 * @param s a string cujo tamanho será calculado
 * @return o número de caracteres antes do '\0'
 */
int minhaStrlen(char*s){
    int contador = 0; // inicializa o contador de caracteres 
    while(s[contador] != '\0'){ // enquanto não encontrar o caractere nulo, incrementa o contador.
        contador++;
    }
    return contador;
}

/**
 * Função que recebe uma string e retorna uma nova string cifrada, 
 * deslocando cada letra 3 posições para frente no alfabeto. 
 * Letras maiúsculas e minúsculas são tratadas separadamente, 
 * enquanto outros caracteres permanecem inalterados.
 * @param string a string que será cifrada.
 * @return nova string cifrada.
 */
char* combinatorio(char* string){
    int i;
    char* nova;
    int tamanho;

    // descobre o tamanho de string (o parâmetro recebido).
    tamanho = minhaStrlen(string);

    //aloca memória para nova, que terá o mesmo tamanho de string + 1 para o '\0'.
    nova = (char*) malloc((tamanho + 1) * sizeof(char));

    // 'for' de cifragem de cada caractere da string, com base na tabela ASCII.
    for(i = 0; i < tamanho; i++){
        if(string[i] >= 'a' && string[i] <= 'z'){
            nova[i] = (string[i] - 'a' + 3) % 26 + 'a';

        } else if(string[i] >= 'A' && string[i] <= 'Z') {
            nova[i] = (string[i] - 'A' + 3) %26 + 'A';
        }
        else {
            nova[i] = string[i];
        }
    }
    nova[i] = '\0';
    return nova;
}

int main ()
{
    char linha [1000]; 
    while(fgets(linha, 1000, stdin) !=NULL)
    {

     // mede o tamanho da string lida e remove o '\n' do final, se houver.
     int tamanho;
     tamanho = minhaStrlen(linha);
     if (linha[tamanho - 1] == '\n') {
        (linha[tamanho - 1] = '\0');
     }
     
     // chamar a função de cifragem e armazena o resultado em uma variável.
     char* resultado = combinatorio(linha);
    
     // imprimir o resultado
     printf("%s\n", resultado); 

     // devolve a memoria alocada para o sistema
     free(resultado); 
    }
    return 0;
}
