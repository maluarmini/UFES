import java.util.Scanner;

public class Cliente{
    private String nome;
    private String cpf;

    public Cliente(){
        this.cpf = "";
        this.nome = "";
    }

    public void setNome(String nome){
        this.nome = nome;
    }

    public void setCpf(String nome){
        if(this.verificarCPF(nome)){
            this.cpf = nome;
        }else{
            System.out.println("CPF invalido.");
        }
    }

    public String getNome(){
        return this.nome;
    }

    public String getCpf(){
        return this.cpf;
    }

    private static boolean verificarCPF(String cpf) {
        // Nao verifica nulos e valores vazios.
        if (cpf == null || cpf.length() == 0) return false;
        // Considera apenas os digitos do CPF, colocando-os num string builder.
        StringBuilder builder = new StringBuilder();
        for (int i = 0; i < cpf.length(); i++) {
        char c = cpf.charAt(i);
        if (c >= '0' && c <= '9') builder.append(c);
        }
        // Um CPF valido tem 11 digitos.
        if (builder.length() != 11) return false;
        // Calcula o primeiro digito verificador e confere com o digito fornecido.
        int digito = calcularDigitoVerificador(builder, 9);
        if (digito != builder.charAt(9) - '0') return false;
        // Faz o mesmo com o segundo digito verificador.
        digito = calcularDigitoVerificador(builder, 10);
        if (digito != builder.charAt(10) - '0') return false;
        // Se tudo deu certo, retorna OK.
        return true;
        }
        private static int calcularDigitoVerificador(StringBuilder builder, int indice) {
        int soma = 0, peso = indice + 1, digito;
        for (int i = 0; i < indice; i++, peso--) {
        digito = builder.charAt(i) - '0';
        soma += digito * peso;
        }
        digito = 11 - (soma % 11);
        if (digito > 9) digito = 0;
        return digito;
        }

    public static void main(String[] args){
        Scanner scan = new Scanner(System.in);
        String str = "\0";
        while(!str.equals(".")){
            str = scan.next();
            Cliente cliente = new Cliente();
            cliente.setNome(str);
            while(str != "." || str != "+"){
                str = scan.next();
                if(str.equals("+") || str.equals(".")){
                    break;
                }
                cliente.setCpf(str);
            }
            System.out.println(cliente.getNome() + " " + cliente.getCpf());
        }
        scan.close();
    }
}
