public class DVD extends Produtos {
    private int duracao;

    DVD(String nome, double preco, int duracao){
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
    // @Override
    // public int compareTo(Produtos o){
    //     return 1;
    // }
}
