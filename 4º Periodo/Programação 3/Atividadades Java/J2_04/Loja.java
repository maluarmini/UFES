import java.io.IOException;
import java.io.BufferedReader;
import java.io.FileReader;

public class Loja{
    public static void main(String [] args) throws IOException{
        String path = "test_3.csv";
        BufferedReader buffRead = new BufferedReader(new FileReader(path));
		String linha = buffRead.readLine();

        String[] linhaSep = new String[4];

        int i = 0, n = 0;
        n = Integer.parseInt(linha);
        System.out.println("Numero de produtos: " + n);

        Produtos produtos[] = new Produtos[n + 1];

		while (true) {
			if (linha != null) {
				// System.out.println(linha);
                
                linhaSep = linha.split(",");
                if(linhaSep[0].equals("L")){
                    produtos[i] = new Livro(linhaSep[1],  Double.parseDouble(linhaSep[2]), linhaSep[3]);
                }else if(linhaSep[0].equals("C")){
                    produtos[i] = new CD(linhaSep[1],  Double.parseDouble(linhaSep[2]), Integer.parseInt(linhaSep[3]));
                }else if(linhaSep[0].equals("D")){
                    produtos[i] = new Dvd(linhaSep[1],  Double.parseDouble(linhaSep[2]), Integer.parseInt(linhaSep[3]));
                }else{
                    System.out.println("Indica qtd produtos ou Produto não existe na loja");
                }
			} else
				break;
			linha = buffRead.readLine();
            i++;
		}
		buffRead.close();

        i = 1;
        while(i < n + 1){
            System.out.println(produtos[i].toString());
            i++;
        }
}
}