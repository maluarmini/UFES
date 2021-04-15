import java.util.Scanner;

public class App {
    public static void main(String[] args){
        Scanner scan = new Scanner(System.in);
        int n = scan.nextInt();
        int i=0;
        String linha = new String();
        String[] linhaSep = new String[4];
        
        Forma formas[] = new Forma[n+1];

        while(i < n){
            linha = scan.next();
            linhaSep = linha.split(",");
            if(linhaSep[0].equals("R")){
                formas[i] = new Retangulo(Double.parseDouble(linhaSep[1]),Double.parseDouble(linhaSep[2]));
            }else if(linhaSep[0].equals("Q")){
                formas[i] = new Quadrado(Double.parseDouble(linhaSep[1]));
            }else if(linhaSep[0].equals("C")){
                formas[i] = new Circulo(Double.parseDouble(linhaSep[1]));
            }else{
                System.out.println("Forma indisponivel");
            }
            i++;
        }
        scan.close();

        i = 0;
        while(i < n){
            System.out.println(formas[i].toString());
            i++;
        }
    }
}
