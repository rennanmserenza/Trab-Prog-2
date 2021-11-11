#include <stdio.h>
#include <string.h>

#define MAX 100


struct tipoAluno {
    int RA, ordem_cadastro;
    double media;  
    double P1, P2, T, PO;
    char nome[MAX], state[MAX];
};

void removerSpacos(char str[]);

void mediaList(tipoAluno &v);
void insertOrdenado(tipoAluno *v, tipoAluno &q, int i);

void cadastraAluno(tipoAluno &v, int i);
void buscaAluno(tipoAluno *v, int i);
void lerArquivo(tipoAluno *v, int &i);
void geraArquivo(tipoAluno *v, int i, int opt);
void verificaAluno(FILE *pt, tipoAluno *v, int i, char *status);
void encerrarPrograma(tipoAluno *v, int i);