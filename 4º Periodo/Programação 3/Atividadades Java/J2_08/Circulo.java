public class Circulo implements Forma {
    private double raio;
    private final double PI = 3.14159265359;

    Circulo(double raio){
        this.raio = raio;
    }

    @Override
    public double calculaPerimetro(){
        return 2*PI*raio;
    }
    @Override
   public double calculaArea(){
       return PI*raio*raio;
   }

   @Override
   public String toString(){
       return String.format("Circulo de raio %.2f - perimetro: %.2f; area: %.2f.", this.raio, this.calculaPerimetro(), this.calculaArea()); 
   }
}
