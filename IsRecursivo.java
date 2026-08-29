/*
- Refaça a questão Is de forma recursiva.
- 4 métodos: verifica se a string é só vogais, só consoantes, um número
  inteiro, ou um número real. Saída: X1 X2 X3 X4 (SIM/NAO).
*/
import java.util.Scanner;

public class IsRecursivo {

    /**
     * Método público que inicia a recursão para verificar se a string
     * é composta somente por vogais.
     * @param texto a string a verificar
     * @return true se todos os caracteres forem vogais
    */

    public static boolean somenteVogais(String texto) {
        return somenteVogaisRec(texto, 0);
    }

    public static boolean somenteVogaisRec(String texto, int i) {
        if (i == texto.length()) { // caso base: fim da string
            return true;
        }
        char c = texto.charAt(i);
        boolean ehVogal = (c=='a'||c=='e'||c=='i'||c=='o'||c=='u'||
                           c=='A'||c=='E'||c=='I'||c=='O'||c=='U');
        if (!ehVogal) {
            return false;
        }
        return somenteVogaisRec(texto, i + 1);
    }

    /**
     * Método público que inicia a recursão para verificar se a string
     * é composta somente por consoantes.
     * @param texto a string a verificar
     * @return true se todos os caracteres forem consoantes
    */

    public static boolean somenteConsoantes(String texto) {
        return somenteConsoantesRec(texto, 0);
    }

    public static boolean somenteConsoantesRec(String texto, int i) {
        if (i == texto.length()) {
            return true;
        }
        char c = texto.charAt(i);
        boolean ehLetra = (c>='a' && c<='z') || (c>='A' && c<='Z');
        boolean ehVogal = (c=='a'||c=='e'||c=='i'||c=='o'||c=='u'||
                           c=='A'||c=='E'||c=='I'||c=='O'||c=='U');
        if (!ehLetra || ehVogal) {
            return false;
        }
        return somenteConsoantesRec(texto, i + 1);
    }

    /**
     * Método público que inicia a recursão para verificar se a string
     * representa um número inteiro válido.
     * @param texto a string a verificar
     * @return true se for um número inteiro válido
    */

    public static boolean ehInteiro(String texto) {
        if (texto.length() == 0) {
            return false;
        }
        return ehInteiroRec(texto, 0);
    }

    public static boolean ehInteiroRec(String texto, int i) {
        if (i == texto.length()) {
            return true;
        }
        char c = texto.charAt(i);
        if (!(c >= '0' && c <= '9')) {
            return false;
        }
        return ehInteiroRec(texto, i + 1);
    }

    /**
     * Método público que verifica se a string representa um número real
     * válido: precisa ter exatamente 1 ponto e o restante só dígitos.
     * @param texto a string a verificar
     * @return true se for um número real válido
    */
   
    public static boolean ehReal(String texto) {
        if (texto.length() == 0) {
            return false;
        }
        return contarPontos(texto, 0) == 1 && soDigitoOuPonto(texto, 0);
    }

    // conta os pontos somando 1 (se achar '.') ou 0 com o resultado do restante da string
    public static int contarPontos(String texto, int i) {
        if (i == texto.length()) {
            return 0;
        }
        int atual = (texto.charAt(i) == '.') ? 1 : 0;
        return atual + contarPontos(texto, i + 1);
    }

    public static boolean soDigitoOuPonto(String texto, int i) {
        if (i == texto.length()) {
            return true;
        }
        char c = texto.charAt(i);
        if (!((c >= '0' && c <= '9') || c == '.')) {
            return false;
        }
        return soDigitoOuPonto(texto, i + 1);
    }

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        while (scanner.hasNextLine()) {
            String linha = scanner.nextLine();
            String x1 = somenteVogais(linha) ? "SIM" : "NAO";
            String x2 = somenteConsoantes(linha) ? "SIM" : "NAO";
            String x3 = ehInteiro(linha) ? "SIM" : "NAO";
            String x4 = ehReal(linha) ? "SIM" : "NAO";
            System.out.println(x1 + " " + x2 + " " + x3 + " " + x4);
        }
    }
}