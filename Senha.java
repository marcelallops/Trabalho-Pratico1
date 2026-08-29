/*
- Método iterativo que recebe uma string como parâmetro e retorna true se a 
string é uma saída válida, ou false caso contrário.
- Uma senha é válida se contém pelo menos 8 carcteres, incluindo uma letra
maiúscula, uma letra minúscula, um número e um carctere especial, no mínimo
- Na saída padrão, para cada linha de entrada, escreva uma de saída com SIM/NAO
indicando se a senha é válida ou não. 
- EXEMPLO:  ENTRADA      SAÍDA
            Senha123!     SIM
*/

/*
- Método iterativo que recebe uma string como parâmetro e retorna true se a 
string é uma saída válida, ou false caso contrário.
- Uma senha é válida se contém pelo menos 8 carcteres, incluindo uma letra
maiúscula, uma letra minúscula, um número e um carctere especial, no mínimo
- Na saída padrão, para cada linha de entrada, escreva uma de saída com SIM/NAO
indicando se a senha é válida ou não. 
- EXEMPLO:  ENTRADA      SAÍDA
            Senha123!     SIM
*/

import java.util.Scanner;

public class Senha {

    /**
     * Verifica se uma string é uma senha válida: tem pelo menos 8 caracteres
     * e contém ao menos uma letra maiúscula, uma minúscula, um número e um
     * caractere especial (qualquer um que não seja letra nem número).
     * @param texto a string a ser validada
     * @return true se a senha for válida, false caso contrário
    */
   
    public static boolean senhaValida(String texto){
        // 4 "flags" que começam falsas e viram true assim que o tipo correspondente for encontrado
        boolean temMaiuscula = false;
        boolean temMinuscula = false;
        boolean temNumero    = false;
        boolean temEspecial  = false;

        for(int i = 0; i < texto.length(); i++){ // percorre cada caractere da senha, uma única vez
            char c = texto.charAt(i);
            if(c >= 'A' && c <= 'Z') {
                temMaiuscula = true; // achou uma letra maiúscula
            } else if (c >= 'a' && c <= 'z'){
                temMinuscula = true; // achou uma letra minúscula
            } else if (c >= '0' && c <= '9') {
                temNumero = true; // achou um dígito
            } else {
                temEspecial = true; // não é letra nem número, conta como caractere especial
            }
        }

        // válida somente se tiver 8+ caracteres E todas as 4 flags forem true
        return texto.length() >= 8 && temMaiuscula && temMinuscula && temNumero && temEspecial;
    }

    public static void main(String[] args){
        Scanner scanner = new Scanner(System.in);
        while (scanner.hasNextLine()) { // lê linha por linha até o fim da entrada
            String linha = scanner.nextLine();
            if (senhaValida(linha)) {
                System.out.println("SIM");
            } else {
                System.out.println("NAO");
            }
        }
    }
}
        
    

