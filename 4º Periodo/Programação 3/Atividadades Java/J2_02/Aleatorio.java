import java.util.Random;
import java.util.Scanner;

public class Aleatorio {
    public int valorRandomGerado;
    private int VALOR_MAXIMO_DEFULT = 100;
    private static Random random;


    // a primeira coisa a sr feita.
    static {    
        Scanner scan = new Scanner(System.in);
        long seed = scan.nextLong();
        random = new Random(seed);
        scan.close();   
    }

    public Aleatorio(){
        valorRandomGerado = random.nextInt(VALOR_MAXIMO_DEFULT);
    }
    public Aleatorio(int num){
        valorRandomGerado = random.nextInt(VALOR_MAXIMO_DEFULT);
    }

    public int getValorRandom(){
        return valorRandomGerado;
    }

    public void renova(){
        valorRandomGerado = random.nextInt(VALOR_MAXIMO_DEFULT);
    }

    public static void main(String[] args){
        for(int i=0; i < 5; i++){
            Aleatorio aleatorio = new Aleatorio();
            System.out.print(aleatorio.getValorRandom() + " ");
            aleatorio.renova();
            System.out.print(aleatorio.getValorRandom() + " ");
        }
        System.out.println();
    }

}
