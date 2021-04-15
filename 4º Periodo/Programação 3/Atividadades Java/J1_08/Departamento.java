public class Departamento {
    String nomeDep;
    Funcionario[] funcionarios; // um departamento tem muitos funcionario
    int qtdFuncionarios;

    void setNomeDepartamento(String nome){
        this.nomeDep = nome;
    }
    void setFuncionariosDepartamento(Funcionario[] funcionarios){
        this.funcionarios = funcionarios;
    }
    void setQtdFuncionarios(int qtd){
        this.qtdFuncionarios = qtd;
    }
    String getNomeDepartamento(){
        return this.nomeDep;
    }
    Funcionario[] getFuncionariosDepartamento(){
        return this.funcionarios;
    }

    Funcionario retornaFuncionario(int indice){
        return this.getFuncionariosDepartamento()[indice];
    }
    int getQtdFuncionario(){
        return this.qtdFuncionarios;
    }
}
