// Problemas para pesquisar mais tarde
// scan.nextLine();

import java.util.Scanner;

public class App {
    public static void main(String[] args){
        Scanner scan = new Scanner(System.in);
        String nomeEmpresa = scan.nextLine();
        String cnpjEmpresa = scan.nextLine();
        int qtdDepartamentos = scan.nextInt();
        String nomeDepartamento;
        int qtdFuncionarios,j;
        String nomeFuncionario;
        double salarioFuncionario;
        String dataAdmissaoFuncionario;
        
        Empresa empresa = new Empresa();

        empresa.setNomeEmpresa(nomeEmpresa);
        empresa.setCnpj(cnpjEmpresa);
        
        Departamento[] departamentos = new Departamento[qtdDepartamentos];

        for(int i=0; i<qtdDepartamentos; i++){
            nomeDepartamento = scan.next();
            qtdFuncionarios = scan.nextInt();
            Departamento departamento = new Departamento();
            departamento.setNomeDepartamento(nomeDepartamento);
            departamento.setQtdFuncionarios(qtdFuncionarios);
            Funcionario[] funcionarios = new Funcionario[qtdFuncionarios+1];

            for(j=0; j<qtdFuncionarios; j++){
                Funcionario funcionario = new Funcionario();
                nomeFuncionario = scan.next();
                salarioFuncionario = scan.nextDouble();
                dataAdmissaoFuncionario = scan.next();
                funcionario.setNomeFuncionario(nomeFuncionario);
                funcionario.setSalarioFuncionario(salarioFuncionario);
                funcionario.setDataAdmissao(dataAdmissaoFuncionario);
                funcionarios[j] = funcionario;
            }
            departamento.setFuncionariosDepartamento(funcionarios);
            departamentos[i] = departamento;
        }
        
        empresa.setDepartamentosEmpresa(departamentos);

        
        System.out.println(empresa.getNomeEmpresa());
        System.out.println(empresa.getCnpj());
        for(int i=0;i<qtdDepartamentos;i++){
            System.out.println(empresa.getDepartamentosEmpresa()[i].getNomeDepartamento());   
        }

        System.out.println("Reajuste salarial - 10%");

        for(int i=0; i < empresa.retornaDepartamento(0).getQtdFuncionario();i++){
            System.out.println("Salario anterior: " + empresa.retornaDepartamento(0).retornaFuncionario(i).getSalarioFuncionario());
            empresa.retornaDepartamento(0).retornaFuncionario(i).aumentaSalario();
            System.out.println("Salario posterior: " + empresa.retornaDepartamento(0).retornaFuncionario(i).getSalarioFuncionario());
        }
        
        
        //Transferir o primeiro funcionario do departamento 1 para o departamento 2;
        
    }
}
