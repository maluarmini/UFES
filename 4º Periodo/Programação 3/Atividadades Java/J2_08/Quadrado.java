public class Quadrado extends Quadrilatero {
    private double lado;

    Quadrado(double lado){
        super(lado,lado,lado,lado);
        this.lado = lado;
    }

    @Override
    public double calculaArea(){
        return this.lado * this.lado;
    }

    @Override
    public String toString(){
        return String.format("Quadrado de lado %.2f - perimetro: %.2f; area: %.2f.", this.lado, this.calculaPerimetro(), this.calculaArea());
    }
}
