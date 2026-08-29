/*
- Refaça a questão Soma de Dígitos de forma recursiva.
- Recebe um número inteiro, retorna a soma dos dígitos.
- Exemplo: 12345 -> 15
*/
import java.util.Scanner;

public class SomaRecursiva {

    /**
     * Calcula, recursivamente, a soma dos dígitos de um número inteiro.
     * O próprio número, diminuindo a cada chamada (n/10), já serve
     * como controle da recursão, sem precisar de contador extra.
     * @param n o número cujos dígitos serão somados
     * @return a soma dos dígitos de n
    */
   
    public static int somaDigitos(int n) {
        if (n < 10) { // caso base: número de 1 dígito só
            return n;
        }
        return (n % 10) + somaDigitos(n / 10); // último dígito + soma do resto
    }

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        while (scanner.hasNextInt()) {
            int n = scanner.nextInt();
            System.out.println(somaDigitos(n));
        }
    }
}
