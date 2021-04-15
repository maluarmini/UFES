import java.io.IOException;
import java.io.FileReader;
import java.util.Arrays;
import java.util.Scanner;

public class Loja{
    public static void main(String [] args) throws IOException{
        String path = "test_3.csv";
        
        Scanner scan = new Scanner(new FileReader(path));
        int n = scan.nextInt();
        scan.nextLine();
        System.out.println(n);
        Produtos produtos[] = new Produtos[n];
        String[] linhaSep = new String[4];

        for (int i=0; i<n;i++){
            linhaSep = scan.nextLine().split(",");

            if(linhaSep[0].equals("L")){
                produtos[i] = new Livro(linhaSep[1],  Double.parseDouble(linhaSep[2]), linhaSep[3]);
            }else if(linhaSep[0].equals("C")){
                produtos[i] = new CD(linhaSep[1],  Double.parseDouble(linhaSep[2]), Integer.parseInt(linhaSep[3]));
            }else if(linhaSep[0].equals("D")){
                produtos[i] = new Dvd(linhaSep[1],  Double.parseDouble(linhaSep[2]), Integer.parseInt(linhaSep[3]));
            }else{
                System.out.println("Indica qtd produtos ou Produto não existe na loja");
            }
        }
        
        for(int i=0; i < n; i++){
            System.out.println(produtos[i].toString());
        }

        System.out.println("\nTestando o compareTo\n");

        Arrays.sort(produtos);
        
        for(int i=0; i < n; i++){
            System.out.println(produtos[i].toString());
        }        
}
}