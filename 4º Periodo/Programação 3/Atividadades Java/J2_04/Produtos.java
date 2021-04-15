public class Produtos {
    private String nome;
    private double preco;

    Produtos(String nome, double preco){
        this.setNome(nome);
        this.setPreco(preco);
    }

    public void setNome(String nome){
        this.nome = nome;
    }

    public String getNome(){
        return this.nome;
    }
    public void setPreco(double nome){
        this.preco = nome;
    }

    public double getPreco(){
        return this.preco;
    }

    public String toString(){
        String r = this.nome + " " + String.format("(R$ %.2f) - ",this.preco );
        
        return r;
    }
}
