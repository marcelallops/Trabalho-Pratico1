/*
- Refazer a questão Inversão de String de forma recursiva.
- Recebe uma string, retorna ela invertida.
- Exemplo: "abcde" -> "edcba"
*/
import java.util.Scanner;

public class InversaoRecursiva {

    /**
     * Método público que inicia a recursão a partir da posição 0.
     * @param texto a string a ser invertida
     * @return a string invertida
    */

    public static String inverter(String texto) {
        return inverterRec(texto, 0);
    }

    /**
     * Inverte recursivamente a string a partir da posição i.
     * Cada chamada processa o restante primeiro, depois cola o
     * caractere da posição i no final do resultado.
     * @param texto a string a ser invertida
     * @param i a posição atual sendo processada
     * @return a string invertida a partir da posição i
    */
   
    public static String inverterRec(String texto, int i) {
        if (i == texto.length()) { // caso base: fim da string
            return "";
        }
        return inverterRec(texto, i + 1) + texto.charAt(i); // resto invertido + caractere atual no final
    }

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        while (scanner.hasNextLine()) {
            String linha = scanner.nextLine();
            System.out.println(inverter(linha));
        }
    }
}
