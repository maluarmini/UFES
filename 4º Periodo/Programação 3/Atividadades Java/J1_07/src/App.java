import java.util.Scanner;

public class App {
    public static void main(String[] args) throws Exception {
        Scanner scan = new Scanner(System.in);
        double num1 = scan.nextDouble();
        double num2 = scan.nextDouble();
        double num3 = scan.nextDouble();
        double num4 = scan.nextDouble();
        double num5 = scan.nextDouble();
        double num6 = scan.nextDouble();

        Ponto P1 = new Ponto();
        P1.setX(num1);
        P1.setY(num2);
        Ponto P2 = new Ponto();
        P2.setX(num3);
        P2.setY(num4);
        Ponto P3 = new Ponto();
        P3.setX(num5);
        P3.setY(num6);

        Triangulo triangulo = new Triangulo();
        triangulo.setTriagulo(P1, P2, P3);

        double perimetro = triangulo.calculaPerimetro();
        System.out.println(perimetro);
    }
}
