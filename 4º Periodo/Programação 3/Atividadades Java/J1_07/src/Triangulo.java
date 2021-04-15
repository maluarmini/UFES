public class Triangulo {
    Ponto V1;
    Ponto V2;
    Ponto V3;

    void setTriagulo(Ponto V1, Ponto V2, Ponto V3){
        this.V1 = V1;
        this.V2 = V2;
        this.V3 = V3;
    }


    double calculaPerimetro(){
        double d1 = V1.calculaDistancia(V1,V2);
        double d2 = V1.calculaDistancia(V2,V3);
        double d3 = V1.calculaDistancia(V1,V3);
        double perimetro = d1 + d2 + d3;
        return perimetro;
    }
}
