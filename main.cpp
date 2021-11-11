/*              Aluno: Rennan Mendes Serenza
                UFMS - FACOM - Sistemas de Informação
                2021 - 2 Periodo - Noturno
*/

#include "menu.h"
#include "alunos.h"

int main() {
    int i = 0, opt = 0;
    tipoAluno alunos[MAX], aluno[MAX];
    
    system("cls");
    size();

    do {    
        menu(opt);        

        // opt == 1 => Cadastrar Aluno.
        if (opt == 1) {
            cadastraAluno(aluno[0], i);
            if (i == 0) {
                alunos[i] = aluno[0];
            }
            else {
                insertOrdenado(alunos, aluno[0], i);
            }
            i++;
        }
        // opt == 2 => Busca por alunos já cadastrados pelo nome.
        else if (opt == 2) {
            buscaAluno(alunos, i);
        }
        // opt == 3 => Cadastrar Aluno à partir de um documento externo.
        else if (opt == 3) {
            lerArquivo(alunos, i);
        }
        // opt == 4 => Gerar arquivo com dados dos alunos aprovados.
        else if (opt == 4) {
            geraArquivo(alunos, i, opt);
        }
        // opt == 5 => Gerar arquivo com dados dos alunos reprovados.
        else if (opt == 5) {
            geraArquivo(alunos, i, opt);
        }
        // opt => 6 => Encerra o programa e gera um arquivo atual.txt com os dados atuais.
        else if (opt == 6) {
            encerrarPrograma(alunos, i);
        }
        else {
            printf("\nO valor inserido nao corresponde a um valor do menu, escolha novamente!!!\n");
        }            
        // Timer para a limpeza de tela após as operações serem realizadas
        sleepClear();

    } while (opt != 6);

    return 0;
}
