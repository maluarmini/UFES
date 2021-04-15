public class CD extends Produtos{
    private int numFaixas;

    CD(String nome, double preco, int numFaixas){
        super(nome,preco);
        this.numFaixas = numFaixas;
    }
    
    public void setNumFaixas(int num){
        this.numFaixas = num;
    }
    
    public int getNumFaixas(){
        return this.numFaixas;
    }

    @Override
    public String toString(){
        String r = super.toString() + this.numFaixas + " faixas";
        return r;
    }

}