import java.util.Random;
import java.util.Scanner;

public class Aleatorio {
    public int valorRandomGerado;
    private int VALOR_MAXIMO_DEFULT = 100;
    private static Random random;

    static {    
        Scanner scan = new Scanner(System.in);
        long seed = scan.nextLong();
        random = new Random(seed);
        scan.close();   
    }

    Aleatorio(){
        valorRandomGerado = random.nextInt(VALOR_MAXIMO_DEFULT);
    }
    Aleatorio(int num){
        valorRandomGerado = random.nextInt(VALOR_MAXIMO_DEFULT);
    }

    public int getValorRandom(){
        return valorRandomGerado;
    }

    public static void main(String[] args){
        for(int i=0; i < 10; i++){
            Aleatorio aleatorio = new Aleatorio();
            System.out.print(aleatorio.getValorRandom() + " ");
        }
        System.out.println();
    }

}
