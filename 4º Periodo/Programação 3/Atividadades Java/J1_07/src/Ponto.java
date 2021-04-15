public class Ponto {
    double X;
    double Y;

    void setX(double num){
        this.X = num;
    }
    void setY(double num){
        this.Y = num;
    }
    double getX(){
        return this.X;
    }
    double getY(){
        return this.Y;
    }
    double calculaDistancia(Ponto P1, Ponto P2){
        double distancia = (Math.pow((P1.getX() - P2.getX()),2) + Math.pow((P1.getY() - P2.getY()),2));
        return Math.sqrt(distancia);
    }
}
