import java.io.FileWriter;
import java.io.IOException;
import java.io.PrintWriter;
import java.util.Scanner;

public class App {
    public static void main(String[] args) throws IOException{
        FileWriter arquivo = new FileWriter("alunos.csv");
        PrintWriter gravarArq = new PrintWriter(arquivo);

        gravarArq.printf("Alunos\n");

        Scanner scan = new Scanner(System.in);
        Turma turma = new Turma();
        String nomeAluno;
        double nota1,nota2,nota3;
        
        int qtdAlunosTurma = scan.nextInt();
        Aluno[] alunos = new Aluno[qtdAlunosTurma];
        turma.setQtdAlunoTurma(qtdAlunosTurma);
        turma.setSomaMedias();
        
        

        for(int i=0; i < qtdAlunosTurma; i++){
            Aluno aluno = new Aluno();
            nomeAluno = scan.next();
            nota1 = scan.nextDouble();
            nota2 = scan.nextDouble();
            nota3 = scan.nextDouble();

            aluno.setNomeAluno(nomeAluno);
            aluno.setNota1(nota1);
            aluno.setNota2(nota2);
            aluno.setNota3(nota3);
            aluno.calculaMediaAluno();
            alunos[i] = aluno;
            System.out.println("Aluno: " + aluno.getNomeAluno() + " - Media: " + aluno.getMediaAluno());
            
        }
        turma.setAlunosTurma(alunos);
        turma.somaMedias();
        double media = turma.calculaMediaTurma();
        turma.setMediaTurma(media); 

        System.out.println("Media da turma: " + turma.getMediaTurma());
        for(int i=0;i < turma.getQtdAlunosTurma();i++){
            gravarArq.printf(turma.getAlunosTurma()[i].getNomeAluno()+ " ");
            gravarArq.print(turma.getAlunosTurma()[i].getMediaAluno() + " ");
            if(turma.getAlunosTurma()[i].getMediaAluno() >= 7){
                System.out.print("Aprovado ");
                gravarArq.printf("Aprovado ");

            }else{
                System.out.print("Prova Final ");
                gravarArq.printf("Prova final ");

            }

            if(turma.getAlunosTurma()[i].getMediaAluno() > turma.getMediaTurma()){
                System.out.println("Acima");
                gravarArq.printf("Acima\n");

            }else if(turma.getAlunosTurma()[i].getMediaAluno() == turma.getMediaTurma()){
                System.out.println("Na media da turma");
                gravarArq.printf("Na media da turma\n");

            }else{
                System.out.println("Abaixo");
                gravarArq.printf("Abaixo\n");
            }
        }

        arquivo.close();
    }
}
