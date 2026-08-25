/*
- Método iterativo que recebe uma string, sorteia duas
letras minúsculas aletórias e troca todas as ocorrências da primeira 
letra pela segunda.
- Código ASCII >= 'a' e <= 'z'
- Na saída padrão, para cada linha de entrada, executar o método desenvolvido e mostrar 
a string retornada como linha de saída.
*/

import java.util.Scanner;
import java.util.Random;


public class Alteracao {
 /**
 * A função sorteia 2 letras minúsculas aleatórias e substitui a primeira 
 * pela segunda na string.
 * Cria uma string nova, sem mexer no parâmetro recebido.
 * @param texto o que a string representa (texto onde a substituição
 * será feita)
 * @param gerador o gerador de números aleatórios
 * @return a string com as letras substituídas (o que é devolvido)
 */
    public static String substituirLetra(String texto, Random gerador) {

    // lógica de substiuirLetra. Ela precisa fazer duas coisas em sequencia: sortear as duas letras, depois substituir.
    char letra1 = (char)('a' + (Math.abs(gerador.nextInt()) %26));
    char letra2 = (char)('a' + (Math.abs(gerador.nextInt()) %26));
    
     // 'for' percorre a string, descide se substitui ou mantém a letra, e vai construindo a string resultado.
        String resultado = "";
        for (int i = 0; i < texto.length(); i++) {
            char c = texto.charAt(i);
            if (c == letra1) {
                resultado += letra2;
            } else {
                resultado +=c;
            }
            }
        
        return resultado;
    }

     

public static void main(String[] args) {
    Scanner scanner = new Scanner(System.in);
    Random gerador = new Random();
    gerador.setSeed(4); // setSeed(4) é fixa (relação com a correção automática)

    String linha = scanner.nextLine();
      while (!linha.equals("FIM")) { // o loop (while) continua lendo as linhas até encontrar a palavra-chave 'FIM', que é a condição definida pelo enunciado pra marcar o fim da entrada.
        // chamar a funcao substituirLetra 
        String resultado = substituirLetra(linha, gerador);
        // imprime o resultado
        System.out.println(resultado);
        linha = scanner.nextLine();
    }
   }
}

