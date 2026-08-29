/*
- Um método iterativo que recebe uma string e retorna true se a mesma é composta 
somente por vogais (maiúsculas ou minúsculas).
- Segundo método iterativo que recebe uma string e retorna true se a mesma é composta
por consoantes (maiúsculas ou minúsculas).
- Terceiro método iterativo que recebe uma string e retorna true se a mesma é um número inteiro.
- Quarto método iterativo que recebe uma string e retorna true se a mesma é um número real.
- Na sáda padrão, para cada linha de entrada, escrever outra linha de saída da forma: "X1 X2 X3 X4", onde 
cada Xi é um booleano (SIM/NAO) indicando se a string de entrada é composta somente por vogais, consoantes, um número inteiro ou um número real, respectivamente.
*/
import java.util.Scanner;

public class Is {
    /**
     * Verifica se uma string é composta somente por vogais (maiúsculas ou minúsculas).
     * Percorre cada caractere. Se encontrar qualquer um que não seja vogal,
     * o resultado passa a ser false e permanece assim até o fim do laço.
     * @param texto a string a ser verificada
     * @return true se todos os caracteres forem vogais, false caso contrário
     */
    public static boolean somenteVogais(String texto) {
        boolean resultado = true;
        for (int i = 0; i < texto.length(); i++) {
            char c = texto.charAt(i);
            if (!(c=='a' || c=='e' || c=='i' || c=='o' || c=='u' ||
                  c=='A' || c=='E' || c=='I' || c=='O' || c=='U')) {
                resultado = false;
              } 
        }
        return resultado;
    }
    /**
     * Verifica se uma string é composta somente por consoantes (maiúsculas ou minúsculas).
     * Para cada caractere, checa duas condições: se é letra e se não é vogal.
     * Caso o caractere não seja letra, ou seja uma vogal, o resultado vira false.
     * @param texto a string a ser verificada
     * @return true se todos os caracteres forem consoantes, false caso contrário
     */
    public static boolean somenteConsoantes(String texto) {
        boolean resultado = true;
        for (int i = 0; i < texto.length(); i++) {
            char c = texto.charAt(i);
            boolean ehLetra = (c>='a' && c<='z') || (c>='A' && c<='Z');
            // código pra separar as vogais da função
            boolean ehVogal = (c=='a' || c=='e' || c=='i' || c=='o' || c=='u' ||
                               c=='A' || c=='E' || c=='I' || c=='O' || c=='U');
            if (!ehLetra || ehVogal) {
                resultado = false;
            }
        }
        return resultado;
    }
    /**
     * Verifica se uma string representa um número inteiro válido.
     * String vazia é considerada inválida. Cada caractere precisa ser um dígito ('0'a'9');
     * qualquer outro caractere invalida o resultado.
     * @param texto a string a ser verificada
     * @return true se a string for um número inteiro válido, false caso contrário
     */
    public static boolean ehInteiro(String texto) {
        boolean resultado = true;
        if (texto.length() == 0) {
            resultado = false;
        }
        for (int i = 0; i < texto.length(); i++) {
            char c = texto.charAt(i);
            if (!(c>='0' && c<='9')) {
                resultado = false;
            }
        }
       return resultado;
    }
    /**
     * Verifica se uma string representa um número real válido.
     * String vazia é considerada inválida. Cada caractere precisa ser um dígito
     * ou o ponto decimal '.'. Qualquer outro caractere invalida o resultado.
     * Todavia, é necessário haver exatamente um ponto na string (nenhum
     * ou mais de um também invalidam o resultado).
     * @param texto a string a ser verificada
     * @return true se a string for um número real válido, false caso contrário
     */
    public static boolean ehReal(String texto) {
        boolean resultado = true;
        int qtdPontos = 0;
        if (texto.length() == 0) {
            resultado = false;
        }
        for (int i = 0; i < texto.length(); i++) {
            char c = texto.charAt(i);
            if (c=='.') {
                qtdPontos++;
            } else if (!(c>='0' && c<='9')) {
                resultado = false;
            }
            }
            if (qtdPontos != 1) {
                resultado = false;
            }
            return resultado;
        }
    
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        // percorre a entrada linha por linha até o fim do Scanner (sem palavra-chava, como "FIM")
        while (scanner.hasNextLine()) {
            String linha = scanner.nextLine();

            // chamar as 4 funções "X1 X2 X3 X4" (SIM/NAO)
            boolean vogais = somenteVogais(linha);
            boolean consoantes = somenteConsoantes(linha);
            boolean inteiro = ehInteiro(linha);
            boolean real = ehReal (linha);
            

            // converte cada resultado booleano para "SIM" ou "NAO".
            String x1 = vogais ? "SIM" : "NAO"; // Jeito curto (?) de escrever if/else
            String x2 = consoantes ? "SIM" : "NAO"; 
            String x3 = inteiro ? "SIM" : "NAO";
            String x4 = real ? "SIM" : "NAO";

            System.out.println (x1 + " " + x2 + " " + x3 + " " + x4);

        }
    }
}
