/*
- Método iterativo que recebe uma string como parâmetro e retorna o 
comprimento da substring mais longa sem caracteres repetidos.
- Na saída padrão, para cada linha de entrada, escrever uma linha de saída 
com o comprimento da substring mais longa sem repetição.
- EXEMPLO: ENTRADA      SAÍDA
           abcabcbb       3    (correspondendo à substring "abc")
*/

import java.util.Scanner;

public class Substring {

    /**
     * Calcula o comprimento da maior substring sem caracteres repetidos.
     * Usa a técnica de janela deslizante: para cada posição inicial i,
     * estende j enquanto não houver repetição dentro da janela [i, j].
     * @param texto a string a ser analisada
     * @return o comprimento da maior substring sem repetição
     */
    public static int maiorSemRepeticao(String texto) {
        int maior = 0; // guarda o maior tamanho de janela encontrado até agora

        for (int i = 0; i < texto.length(); i++) { // i é o início da janela
            int j = i; // j é o fim da janela, começa igual a i
            while (j < texto.length() && !existeRepetido(texto, i, j)) {
                j++; // estende a janela enquanto não achar repetição
            }
            int tamanhoJanela = j - i; // calcula o tamanho da janela atual
            if (tamanhoJanela > maior) {
                maior = tamanhoJanela; // atualiza o maior, se essa janela for maior
            }
        }
        return maior;
    }

    /**
     * Verifica se o caractere na posição j já aparece em alguma posição
     * entre i e j-1 (ou seja, se já existe dentro da janela atual).
     * @param texto a string sendo analisada
     * @param i o início da janela atual
     * @param j a posição do caractere novo, sendo testado
     * @return true se o caractere em j já existir na janela, false caso contrário
     */
    public static boolean existeRepetido(String texto, int i, int j) {
        for (int k = i; k < j; k++) { // percorre cada posição já dentro da janela
            if (texto.charAt(k) == texto.charAt(j)) { // compara com o caractere novo (j)
                return true; // achou repetição, não precisa continuar procurando
            }
        }
        return false; // percorreu tudo sem achar repetição
    }

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        while (scanner.hasNextLine()) { // lê linha por linha até o fim da entrada
            String linha = scanner.nextLine();
            System.out.println(maiorSemRepeticao(linha)); // imprime o resultado da análise
        }
    }
}