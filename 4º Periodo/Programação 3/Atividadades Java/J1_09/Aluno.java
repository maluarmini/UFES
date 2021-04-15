public class Aluno{
    String nomeAluno;
    double nota1;
    double nota2;
    double nota3;
    double mediaAluno;

    void setNomeAluno(String nome){
        this.nomeAluno = nome;
    }
    void setNota1(double nota){
        this.nota1 = nota;
    }
    void setNota2(double nota){
        this.nota2 = nota;
    }
    void setNota3(double nota){
        this.nota3 = nota;
    }

    String getNomeAluno(){
        return this.nomeAluno;
    }
    double getNota1(){
        return this.nota1;
    }
    double getNota2(){
        return this.nota2;
    }
    double getNota3(){
        return this.nota3;
    }

    double calculaMediaAluno(){
        this.mediaAluno = (this.nota1 + this.nota2 + this.nota3)/3;
        return (this.nota1 + this.nota2 + this.nota3)/3;
    }
    double getMediaAluno(){
        return this.mediaAluno;
    }
}