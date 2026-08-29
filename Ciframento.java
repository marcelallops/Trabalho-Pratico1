/*
- Para cada caractere de string, se for letra, desloco 
3 posições para frente no alfabeto.
- Minúsculas: 'a' -> 'd', 'b'-> 'e', 'c' -> 'f'... 
- Maiúsculas: 'A' -> 'D', 'B' -> 'E', 'C' -> 'F'...
- Criar um método iterativo que recebe uma string como parâmetro e retorna
outra contendo a entrada de forma cifrada. 
Tabela ASCII - de 'a' a 'z' = 97 a 122.
             - de 'A' a 'Z' = 65 a 90.
*/

import java.util.Scanner;

public class Ciframento {

    /**
     * Cifra uma string usando o método de César com deslocamento de 3.
     * Letras maiúsculas e minúsculas são tratadas separadamente,
     * enquanto outros caracteres permanecem inalterados.
     * @param texto a string a ser cifrada
     * @return a nova string cifrada
     */
    public static String combinatorio(String texto) {
        String nova = "";

        for (int i = 0; i < texto.length(); i++) {
            char c = texto.charAt(i);
            if (c >= 'a' && c <= 'z') {
                c = (char)((c - 'a' + 3) % 26 + 'a');
            } else if (c >= 'A' && c <= 'Z') {
                c = (char)((c - 'A' + 3) % 26 + 'A');
            }
            nova += c;
        }
        return nova;
    }

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        while (scanner.hasNextLine()) {
            String linha = scanner.nextLine();
            if (linha.length() > 0 && linha.charAt(linha.length() - 1) == '\r') {
                linha = linha.substring(0, linha.length() - 1);
            }
            System.out.println(combinatorio(linha));
        }
    }
}