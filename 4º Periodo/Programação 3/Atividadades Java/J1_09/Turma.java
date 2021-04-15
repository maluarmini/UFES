public class Turma {
    int qtdAlunosTurma;
    double mediaTurma;
    double somaMedias;
    Aluno[] alunos;

    void setQtdAlunoTurma(int qtd){
        this.qtdAlunosTurma = qtd;
    }

    void setMediaTurma(double media){
        this.mediaTurma = media;
    }
    void setSomaMedias(){
        this.mediaTurma = 0;
    }
    void setAlunosTurma(Aluno[] alunos){
        this.alunos = alunos;
    }
    
    int getQtdAlunosTurma(){
        return qtdAlunosTurma;
    }

    double getMediaTurma(){
        return mediaTurma;
    }
    void somaMedias(){
        for(int i=0;i<this.qtdAlunosTurma;i++){
            this.somaMedias += this.getAlunosTurma()[i].getMediaAluno();
        }
    }
    double calculaMediaTurma(){
       return this.mediaTurma = (this.somaMedias / this.qtdAlunosTurma); 
    }

    Aluno[] getAlunosTurma(){
        return alunos;
    }
}
