#include "alunos.h"

void time(int i) {
    int time = 0;

    if (i > 0) {
        time = 8;
    }
    else if (i > 10) {
        time = 10;
    }

    sleepClear(time);
}
void removerSpacos(char str[]) {
    int i, j = 1;
    for (i = 1; str[i]; i++) {
        if (str[i] != ' ' || (str[i - 1] != ' ')) {
           str[j] = str[i];
           j++;
        }
    }
    str[j] = '\0';
}

void mediaList(tipoAluno &v) {
    double n1 = v.P1, n2 = v.P2;
    // Verifica se a nota da PO do aluno é maior que a P1 ou que a P2

    if (v.P1 >= v.P2 && v.PO >= v.P2) {
        n1 = v.P1;
        n2 = v.PO;
    }
    else if (v.P2 > v.P1 && v.PO > v.P1 ) {
        n1 = v.PO;
        n2 = v.P2;
    }
    
    v.media = (0.35 * n1) + (0.35 * n2) + (0.3 * v.T);
    
    // Verifica a sitação do estudante
    if (v.media >= 6.00) {
        strcpy(v.state, "Aprovado");
    }
    else {
        strcpy(v.state, "Reprovado");
    }

}
void selectSort(tipoAluno *v, int i) {
    int j, k, min;
    tipoAluno aux;
    
    for (j = 0; j < i - 1; j++) {
        min = j;

        for (k = j + 1; k < i; k++) {
            if (strcmp(v[k].nome, v[min].nome) < 0) {
                min = k;
            }
            else if (strcmp(v[k].nome, v[min].nome) == 0) {
                if (v[min].RA > v[k].RA) {
                    min = k;
                }
                else if (v[min].RA == v[k].RA) {
                    if (v[min].media < v[k].media) {
                        min = k;
                    }
                }
            }

        }

        aux = v[min];
        v[min] = v[j];
        v[j] = aux;

    }
}
void insertSort(tipoAluno *v, tipoAluno &q, int i) {
    int j;
    
    for (j = i - 1; j >= 0 && strcmp(q.nome, v[j].nome) < 0; j--) {
        v[j+1] = v[j];                                                      // strcmp(x, y)  x > y
    }                                                                       // retornando < 0 | x < y
    v[j + 1] = q;                                                           // retornando == 0 | x == y
                                                                            // retornando > 0 | x > y
    printf("Aluno inserido com sucesso!\n");

}


void cadastraAluno(tipoAluno &v, int i) {

    printf("\n%d alunos cadastrados ate o momento!\n", i);
    printf("Cadastre a seguir em ordem Nome do aluno, RA, P1, P2, T e PO.\n");
    
    printf("Aluno numero %d: ", (i + 1));
    
    scanf(" %[^0123456789\t]", v.nome);
    removerSpacos(v.nome);
    
    scanf(" %d %lf %lf %lf %lf", &v.RA, &v.P1, &v.P2, &v.T, &v.PO);
    mediaList(v);
    v.ordem_cadastro = i + 1;

    printf("\nAluno cadastrado!\n");

}
void buscaAluno(tipoAluno *v, int i) {
    int j, x, y,  T = 0;
    char lowerBusca, lowerAluno;
    int resultadosEncontrados = 0;
    char nomeBusca[MAX], nomeAluno[MAX];
    int tamNomeAlunoBusca, tamNomeAlunoLista;

    printf("\nDigite o nome que deseja pesquisar: ");
    
    scanf(" %[^\n]", nomeBusca);
    tamNomeAlunoBusca = strlen(nomeBusca);

    for (j = 0; j < i; j++) {
        x = 0;

        tamNomeAlunoLista = strlen(v[j].nome);
        strcpy(nomeAluno, v[j].nome);

        while (x < tamNomeAlunoLista - tamNomeAlunoBusca) {
            if (T == 0) {
                y = 0;
            }

            while (y < tamNomeAlunoBusca) {
                lowerAluno = tolower(nomeAluno[x + y]);
                lowerBusca = tolower(nomeBusca[y]);

                if (lowerAluno == lowerBusca) {
                    T = 1;
                    y++;    
                }
                else {
                    break;
                }
            }

            if (y == tamNomeAlunoBusca && T == 1) {
                printf("\nNome: %-35s\tMedia: %4.2lf Estado: %s", v[j].nome, v[j].media, v[j].state);
                resultadosEncontrados++;
                break;
            }
            
            x++;
        }    
    }

    printf("\nForam encontrados: %d resultados compativeis.\n", resultadosEncontrados);
    
    time(resultadosEncontrados);
}
void lerArquivo(tipoAluno *v, int &i) {
    
    FILE *ptrarq;
    char nomeArquivo[MAX];
    int in, cadastrados = 0;
    
    // abrindo um arquivo para leitura
    printf("\nInforme o nome do arquivo que deseja ler: ");

    scanf(" %[^\n]", nomeArquivo);
    
    ptrarq = fopen(nomeArquivo, "r");

    if (ptrarq == NULL) {
        printf("\n!!!Erro na abertura do arquivo!!!\n");
    }
    else {
        
        in = fscanf(ptrarq, " %[^0123456789\t]", v[i].nome);
        removerSpacos(v[i].nome);

        while (in != EOF) {
            
            fscanf(ptrarq, " %d %lf %lf %lf %lf", &v[i].RA, &v[i].P1, &v[i].P2, &v[i].T, &v[i].PO);

            mediaList(v[i]);
            v[i].ordem_cadastro = i + 1;

            cadastrados++;
            i++;

            in = fscanf(ptrarq, " %[^0123456789\t]", v[i].nome);
            removerSpacos(v[i].nome);

        }
                    
        fclose(ptrarq);
        selectSort(v, i);

        printf("\nO Arquivo %s foi aberto e lido e ordenado com sucesso!!\nForam cadastrados %d novos alunos.\n", nomeArquivo, cadastrados);
    }

}
void geraArquivo(tipoAluno *v, int i, int opt) {
    FILE *pt;
    char status[20];    

    if (opt == 4) {
        strcpy(status, "Aprovado");
        pt = fopen("aprovados.txt", "w+");
    }
    else {
        strcpy(status, "Reprovado");
        pt = fopen("reprovados.txt", "w+");
    }    
    
    verificaAluno(pt, v, i, status);
    
    fclose(pt);

    printf("\nArquivo gerado com sucesso!!\n");
}
void verificaAluno(FILE *pt, tipoAluno *v, int i, char *status) {
    int j, k = 0;

    fprintf(pt, "\t\t\t\tNome\t\t\t\t\t\t\tRA\t\t\tMEDIA FINAL \t\tNUMERO DE INSERCAO NA LISTA\n");

    for (j = 0; j < i; j++) {
        if (strcmp(status, v[j].state) == 0) {
            fprintf(pt, "%-35s \t\t%9d \t\t\t%4.2lf \t\t\t%13d \n",
            v[j].nome, v[j].RA, v[j].media, v[j].ordem_cadastro);
            k++;
        }
    }

    fprintf(pt, "\nTotal de %d alunos %s.", k, status);
}
void encerrarPrograma(tipoAluno *v, int i) {
    int j;
    FILE *pt;

    pt = fopen("atual.txt", "w+");

    printf("\nInserindo dados no arquivo atual.txt.");

    for (j = 0; j < i; j++) {
        fprintf(pt, "%-30s \t\t%d \t\t%.2f \t\t%.2f \t\t%.2f \t\t%.2f\n",
         v[j].nome, v[j].RA, v[j].P1, v[j].P2, v[j].T, v[j].PO);
    }

    fclose(pt);

    printf("\nSessao salva no arquvio atual.txt.\n");
}
