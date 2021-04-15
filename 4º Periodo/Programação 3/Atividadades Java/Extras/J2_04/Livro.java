public class Livro extends Produtos{
    private String autor;

    Livro(String nome, double preco, String autor){
        super(nome,preco);
        this.autor = autor;
    }

    public void setAutor(String autor){
        this.autor = autor;
    }

    public String getAutor(){
        return this.autor;
    }

    @Override
    public String toString(){
        String r = super.toString() + this.autor;
        return r;
    }
    // @Override
    // public int compareTo(Produtos p){
    //     return 1;
    // }
}
