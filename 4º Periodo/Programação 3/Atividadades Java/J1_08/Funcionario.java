public class Funcionario{
    String nome;
    double salario;
    String data;

    void setNomeFuncionario(String nome){
        this.nome = nome;
    }
    void setSalarioFuncionario(double nome){
        this.salario = nome;
    }
    void setDataAdmissao(String nome){
        this.data = nome;
    }

    String getNomeFuncionario(){
        return this.nome;
    }
    double getSalarioFuncionario(){
        return this.salario;
    }
    String getDataAdmissao(){
        return this.data;
    }
    void aumentaSalario(){
        this.salario = this.salario + (this.salario * 0.10);
    }
}