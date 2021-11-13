#include <stdio.h>
#include <ctype.h>
#include <string.h>

#include "menu.h"
#define MAX 100


struct tipoAluno {
    int RA, ordem_cadastro;
    double media;  
    double P1, P2, T, PO;
    char nome[MAX], state[MAX];
};

void time(int i);
void removerSpacos(char str[]);

void mediaList(tipoAluno &v);
void selectSort(tipoAluno *v, tipoAluno &q, int i);
void insertSort(tipoAluno *v, tipoAluno &q, int i);

void cadastraAluno(tipoAluno &v, int i);
void buscaAluno(tipoAluno *v, int i);
void lerArquivo(tipoAluno *v, int &i);
void geraArquivo(tipoAluno *v, int i, int opt);
void verificaAluno(FILE *pt, tipoAluno *v, int i, char *status);
void encerrarPrograma(tipoAluno *v, int i);
