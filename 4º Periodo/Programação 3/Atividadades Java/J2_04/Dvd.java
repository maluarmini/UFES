public class Dvd extends Produtos {
    private int duracao;

    Dvd(String nome, double preco, int duracao){
        super(nome,preco);
        this.duracao = duracao;
    }

    public void setDuracao(int num){
        this.duracao = num;
    }

    public int getDuracao(){
        return this.duracao;
    }

    @Override
    public String toString(){
        String r = super.toString() + this.duracao + "minutos";
        return r;
    }
}
