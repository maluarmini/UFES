public class Empresa {
    String nomeEmpresa;
    String cnpj;
    Departamento[] departamentos; // uma empresa tem muitos departamentos

    void setNomeEmpresa(String nome){
        this.nomeEmpresa = nome;
    }
    void setCnpj(String nome){
        this.cnpj = nome;
    }
    void setDepartamentosEmpresa(Departamento[] departamentos){
        this.departamentos = departamentos;
    }
    String getNomeEmpresa(){
        return this.nomeEmpresa;
    }
    String getCnpj(){
        return this.cnpj;
    }
    Departamento[] getDepartamentosEmpresa(){
        return this.departamentos;
    }
    Departamento retornaDepartamento(int indice){
        return this.getDepartamentosEmpresa()[0];
    }      
}
