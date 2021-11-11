#include "menu.h"

int get_size(const char *name) {
    int size;
    FILE *pt = fopen(name, "r");

    if(pt == NULL) {
        return 0;
    }        

    fseek(pt, 0, SEEK_END);
    
    size = ftell(pt);
    fclose(pt);

    return size;
}
void size() {
    if(get_size("atual.txt") == 0) {
        printf("Nenhum arquivo de dados encontrado!!!\n");
    }
    else {
        printf("!!!Existe um arquivo atual.txt com dados salvos nele!!!\n");
    }
}
void sleepClear(){
    struct timespec tim, tim2;
        tim.tv_sec  = 3;
        tim.tv_nsec = 0;
        
        nanosleep(&tim, &tim2);        
        system("cls || clear");
}
void menu(int &option) {
    printf  ("\n=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=\n\n");
    printf  ("1 - Cadastrar novo aluno\n");
    printf  ("2 - Buscar aluno\n");
    printf  ("3 - Ler arquivo com listagem de alunos\n");
    printf  ("4 - Gerar arquivo com alunos aprovados\n");
    printf  ("5 - Gerar arquivo com alunos reprovados\n");
    printf  ("6 - Fechar Programa\n");
    printf  ("\nEscolha a operacao: ");
    scanf   (" %d", &option);
    printf  ("\n=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=\n");
}
