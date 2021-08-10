/// Júlia Gomes RA:20052387
/// Lais Lahoud RA:

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#define MAX 20
#define max_nome 30
#define max_ra 6

typedef struct DISCIPLINAS{
    char nome[max_nome], codigo[max_ra];
}DISCIPLINAS;

typedef struct ALUNOS{
    char nome[max_nome], ra[max_ra];
    DISCIPLINAS disciplinas[MAX];
}ALUNOS;

typedef struct PROFESSORES{
    char nome[max_nome], codigo[max_ra];
    DISCIPLINAS disciplinas[MAX];
}PROFESSORES;

int menu(){
    int acao;
    printf("\n\t\t\tMENU\n=========================================================\n");
    printf("\nESCOLHA UMA DAS \265REAS:\n");
    printf("1.Aluno\n");
    printf("2.Professor\n");
    printf("3.Disciplina\n");
    printf("4.Sair\n\n");
    do{
        printf("\265rea escolhida: ");
        fflush(stdin);
        scanf("%d",&acao);
    }while(acao<1 || acao>4);
    return acao;
}

int menu_aluno(){
    int acao;
    printf("\n\t\t\tALUNO\n=========================================================\n");
    printf("\nESCOLHA UMA DAS A\200\345ES ABAIXO:\n");
    printf("1.Cadastrar aluno(s)\n");
    printf("2.Matricular aluno(s) em disciplina(s)\n");
    printf("3.Cancelar matricula do(s) aluno(s) em uma(s) disciplina(s)\n");
    printf("4.Lista de alunos\n");
    printf("5.Lista de disciplinas de um aluno\n");
    printf("6.Voltar\n\n");
    do{
        printf("A\207\306o escolhida: ");
        fflush(stdin);
        scanf("%d",&acao);
    }while(acao<1 || acao>6);
    return acao;
}

int menu_professor(){
    int acao;
    printf("\n\t\t\tPROFESSOR\n=========================================================\n");
    printf("\nESCOLHA UMA DAS A\200\345ES ABAIXO:\n");
    printf("1.Cadastrar professor(es)\n");
    printf("2.Vincular professor(es) a disciplina(s)\n");
    printf("3.Remover vinculo do(s) professor(es) em disciplina(s)\n");
    printf("4.Lista de professores\n");
    printf("5.Lista de disciplinas ministradas pelo professor\n");
    printf("6.Voltar\n\n");
    do{
        printf("A\207\306o escolhida: ");
        fflush(stdin);
        scanf("%d",&acao);
    }while(acao<1 || acao>6);
    return acao;
}

int menu_disciplina(){
    int acao;
    printf("\n\t\t\tDISCIPLINA\n=========================================================\n");
    printf("\nESCOLHA UMA DAS A\200\345ES ABAIXO:\n");
    printf("1.Cadastrar disciplina(s)\n");
    printf("2.Lista de disciplinas\n");
    printf("3.Lista de alunos em uma disciplina\n");
    printf("4.Lista de professores vinculados a uma disciplina\n");
    printf("5.Voltar\n\n");
    do{
        printf("A\207\306o escolhida: ");
        fflush(stdin);
        scanf("%d",&acao);
    }while(acao<1 || acao>5);
    return acao;
}

void lista_alunos(ALUNOS alunos[], int n_alunos){
    int i;
    printf("\nLISTA DE ALUNOS\n=====================================");
        for(i=0;i<n_alunos;i++)
            printf("\n-> %-30s %s",alunos[i].nome,alunos[i].ra);
        printf("\n\n");
}

void lista_prof(PROFESSORES professores[], int n_prof){
    int i;
    printf("\nLISTA DE PROFESSORES\n=====================================");
        for(i=0;i<n_prof;i++)
            printf("\n-> %-30s %s",professores[i].nome,professores[i].codigo);
        printf("\n\n");
}

void lista_disc(DISCIPLINAS disciplinas[], int n_disc){
    int i;
    printf("\nLISTA DE DISCIPLINAS\n=====================================");
        for(i=0;i<n_disc;i++)
            printf("\n-> %-30s %s",disciplinas[i].nome,disciplinas[i].codigo);
        printf("\n\n");
}

void disc_aluno(ALUNOS alunos[],DISCIPLINAS disciplinas[],int n_disc,int n_alunos){
    int i,existe,j,existe_disc;
    char nome[max_nome],valida='s',vazio[max_nome]="vazio";
    printf("\nDISCIPLINAS DE UM ALUNO\n===========================\n");
    while(valida!='n')
    {
        do{
            printf("\nDigite o nome do aluno: ");
            fflush(stdin);
            gets(nome);
            strupr(nome);
        }while(strlen(nome)==0);

        existe=1;
        existe_disc=1;
        for(i=0;i<n_alunos;i++)
            if(strcmp(nome,alunos[i].nome)==0)
            {
                existe=0;
                for(j=0;j<n_disc;j++)
                    if(strlen(alunos[i].disciplinas[j].nome)!=0 && strcmp(alunos[i].disciplinas[j].nome,vazio)!=0)
                    {
                        printf("\n-> %-30s %s",alunos[i].disciplinas[j].nome,alunos[i].disciplinas[j].codigo);
                        existe_disc=0;
                    }
                if(existe_disc==1)
                    printf("\nEsse aluno ainda n\306o est\240 matriculado em nenhuma disciplina!\n");

            }

        if(existe==1)
            printf("\nEsse aluno n\306o est\240 cadastrado!");

        do{
            printf("\n\nDeseja imprimir as disciplinas de outro aluno?(s/n) ");
            fflush(stdin);
            scanf("%c",&valida);
            valida=tolower(valida);
        }while(valida<110 || valida>110 && valida<115 || valida>115);
    }
}

void disc_prof(PROFESSORES professores[],DISCIPLINAS disciplinas[],int n_disc,int n_prof){
    int i,existe,j,existe_disc;
    char nome[max_nome],valida='s',vazio[max_nome]="vazio";
    printf("\nDISCIPLINAS DE UM PROFESSOR\n===============================\n");
    while(valida!='n')
    {
        do{
            printf("\nDigite o nome do professor: ");
            fflush(stdin);
            gets(nome);
            strupr(nome);
        }while(strlen(nome)==0);

        existe=1;
        existe_disc=1;
        for(i=0;i<n_prof;i++)
            if(strcmp(nome,professores[i].nome)==0)
            {
                existe=0;
                for(j=0;j<n_disc;j++)
                    if(strlen(professores[i].disciplinas[j].nome)!=0 && strcmp(professores[i].disciplinas[j].nome,vazio)!=0)
                    {
                        printf("\n-> %-30s %s",professores[i].disciplinas[j].nome,professores[i].disciplinas[j].codigo);
                        existe_disc=0;
                    }
                if(existe_disc==1)
                    printf("\nEsse professor ainda n\306o est\240 vinculado a nenhuma disciplina!\n");

            }

        if(existe==1)
            printf("\nEsse professor n\306o est\240 cadastrado!");

        do{
            printf("\n\nDeseja imprimir as disciplinas ministradas por outro professor?(s/n) ");
            fflush(stdin);
            scanf("%c",&valida);
            valida=tolower(valida);
        }while(valida<110 || valida>110 && valida<115 || valida>115);
    }
}

void alunos_disc(ALUNOS alunos[],DISCIPLINAS disciplinas[],int n_disc,int n_alunos){
    int i,existe,j,existe_aluno;
    char nome[max_nome],valida='s';
    printf("\nALUNOS DE UMA DISCIPLINA\n===========================\n");
    while(valida!='n')
    {
        do{
            printf("\nDigite o nome da disciplina: ");
            fflush(stdin);
            gets(nome);
            strupr(nome);
        }while(strlen(nome)==0);

        existe=1;
        existe_aluno=1;
        for(i=0;i<n_disc;i++)
            if(strcmp(nome,disciplinas[i].nome)==0)
            {
                existe=0;
                for(i=0;i<n_alunos;i++)
                    for(j=0;j<n_disc;j++)
                        if(strcmp(nome,alunos[i].disciplinas[j].nome)==0)
                        {
                            printf("\n-> %-30s %s",alunos[i].nome,alunos[i].ra);
                            existe_aluno=0;
                        }
                if(existe_aluno==1)
                    printf("\nEssa disciplina n\306o tem alunos matriculados!\n");
            }


        if(existe==1)
            printf("\nEssa disciplina ainda n\306o est\240 cadastrada!");

        do{
            printf("\n\nDeseja imprimir alunos de outra disciplina?(s/n) ");
            fflush(stdin);
            scanf("%c",&valida);
            valida=tolower(valida);
        }while(valida<110 || valida>110 && valida<115 || valida>115);
    }
}

void profs_disc(PROFESSORES professores[],DISCIPLINAS disciplinas[],int n_disc,int n_prof){
    int i,existe,j,existe_prof;
    char nome[max_nome],valida='s';
    printf("\nPROFESSORES DE UMA DISCIPLINA\n=============================\n");
    while(valida!='n')
    {
        do{
            printf("\nDigite o nome da disciplina: ");
            fflush(stdin);
            gets(nome);
            strupr(nome);
        }while(strlen(nome)==0);

        existe=1;
        existe_prof=1;
        for(i=0;i<n_disc;i++)
            if(strcmp(nome,disciplinas[i].nome)==0)
            {
                existe=0;
                for(i=0;i<n_prof;i++)
                    for(j=0;j<n_disc;j++)
                        if(strcmp(nome,professores[i].disciplinas[j].nome)==0)
                        {
                            printf("\n-> %-30s %s",professores[i].nome,professores[i].codigo);
                            existe_prof=0;
                        }
                if(existe_prof==1)
                    printf("\nEssa disciplina n\306o tem professores vinculados!\n");
            }


        if(existe==1)
            printf("\nEssa disciplina ainda n\306o est\240 cadastrada!");

        do{
            printf("\n\nDeseja imprimir os professores de outra disciplina?(s/n) ");
            fflush(stdin);
            scanf("%c",&valida);
            valida=tolower(valida);
        }while(valida<110 || valida>110 && valida<115 || valida>115);
    }
}

int cadastro_aluno(ALUNOS alunos[], int n_alunos){
    int i,existe=0;
    char valida='s',nome[max_nome],ra[max_ra];
    if (n_alunos!=0)
        lista_alunos(alunos,n_alunos);

    while(valida!='n')
    {
        printf("\nCADASTRO NOVO ALUNO\n=========================\n");
        do{
            printf("\nNome do aluno: ");
            fflush(stdin);
            gets(nome);
            strupr(nome);
        }while(strlen(nome)==0);

        do{
            printf("RA do aluno(max 5 digitos): ");
            gets(ra);
        }while(strlen(ra)>5 || strlen(ra)==0);

        if(n_alunos==0) ///verifica se é o primeiro aluno cadastrado
        {
            strcpy(alunos[n_alunos].nome,nome);
            strcpy(alunos[n_alunos].ra,ra);
            n_alunos++;
        }
        else
        {
            for(i=0;i<n_alunos;i++) ///se não, verifica se já existe o aluno cadastrado
                if(tolower(strcmp(ra,alunos[i].ra))==0)
                    existe=1;
            if(existe==1)
            {
                printf("\nEsse aluno j\240 est\240 cadastrado!\n");
                existe=0;
            }
            else
            {
                strcpy(alunos[n_alunos].nome,nome);
                strcpy(alunos[n_alunos].ra,ra);
                n_alunos++;
            }
        }

        do{
            printf("Deseja cadastrar mais um aluno?(s/n) ");
            fflush(stdin);
            scanf("%c",&valida);
            valida=tolower(valida);
        }while(valida<110 || valida>110 && valida<115 || valida>115);
    }
    return n_alunos;
}

int cadastro_disciplina(DISCIPLINAS disciplinas[], int n_disc){
    int i,existe=0;
    char valida='s',nome[max_nome],codigo[max_ra];
    if (n_disc!=0)
        lista_disc(disciplinas,n_disc);

    while(valida!='n')
    {
        printf("\n\nCADASTRO NOVA DISCIPLINA\n=========================\n");
        do{
            printf("\nNome da disciplina: ");
            fflush(stdin);
            gets(nome);
            strupr(nome);
        }while(strlen(nome)==0);

        do{
            printf("C\242digo da disciplina(max 5 digitos): ");
            gets(codigo);
        }while(strlen(codigo)>5 || strlen(codigo)==0);

        if(n_disc==0)
        {
            strcpy(disciplinas[n_disc].nome,nome);
            strcpy(disciplinas[n_disc].codigo,codigo);
            n_disc++;
        }
        else
        {
            for(i=0;i<n_disc;i++)
                if(tolower(strcmp(codigo,disciplinas[i].codigo))==0)
                    existe=1;
            if(existe==1)
            {
                printf("\nEssa disciplina j\240 est\240 cadastrada!\n");
                existe=0;
            }
            else
            {
                strcpy(disciplinas[n_disc].nome,nome);
                strcpy(disciplinas[n_disc].codigo,codigo);
                n_disc++;
            }
        }

        do{
            printf("Deseja cadastrar mais uma disciplina?(s/n) ");
            fflush(stdin);
            scanf("%c",&valida);
            valida=tolower(valida);
        }while(valida<110 || valida>110 && valida<115 || valida>115);
    }
    return n_disc;
}

int cadastro_professor(PROFESSORES professores[], int n_prof){
    int i,existe=0;
    char valida='s',nome[max_nome],codigo[max_ra];
    if (n_prof!=0)
        lista_prof(professores,n_prof);

    while(valida!='n')
    {
        printf("\nCADASTRO NOVO PROFESSOR\n=========================\n");
        do{
            printf("\nNome do professor: ");
            fflush(stdin);
            gets(nome);
            strupr(nome);
        }while(strlen(nome)==0);

        do{
            printf("C\242digo do professor(max 5 digitos): ");
            gets(codigo);
        }while(strlen(codigo)>5 || strlen(codigo)==0);

        if(n_prof==0)
        {
            strcpy(professores[n_prof].nome,nome);
            strcpy(professores[n_prof].codigo,codigo);
            n_prof++;
        }
        else
        {
            for(i=0;i<n_prof;i++)
                if(tolower(strcmp(codigo,professores[i].codigo))==0)
                    existe=1;
            if(existe==1)
            {
                printf("\nEsse professor j\240 est\240 cadastrado!\n");
                existe=0;
            }
            else
            {
                strcpy(professores[n_prof].nome,nome);
                strcpy(professores[n_prof].codigo,codigo);
                n_prof++;
            }
        }

        do{
            printf("Deseja cadastrar mais um professor?(s/n) ");
            fflush(stdin);
            scanf("%c",&valida);
            valida=tolower(valida);
        }while(valida<110 || valida>110 && valida<115 || valida>115);
    }
    return n_prof;
}

void matricula_aluno(ALUNOS alunos[],DISCIPLINAS disciplinas[],int n_disc,int n_alunos){
    int i, existe, posicao_aluno[MAX], j=0, aluno=0, z;
    char nome[max_nome],valida='s',vazio[max_nome]="vazio";
    printf("\nMATRICULA ALUNO EM DISCIPLINA\n================================\n");
    lista_alunos(alunos,n_alunos);
    while(valida!='n')
    {
        do{
            printf("\nDigite o nome do aluno: ");
            fflush(stdin);
            gets(nome);
            strupr(nome);
        }while(strlen(nome)==0);

        existe=1;

        for(i=0;i<n_alunos;i++)
            if(strcmp(nome,alunos[i].nome)==0)
            {
                existe=0; ///o aluno esta cadastrado
                aluno++;
                posicao_aluno[j]=i;
                j++;
            }
        if(existe==1)
            printf("\nEsse aluno ainda n\306o est\240 cadastrado!\n");

        do{
            printf("Deseja matricular mais um aluno?(s/n) ");
            fflush(stdin);
            scanf("%c",&valida);
            valida=tolower(valida);
        }while(valida<110 || valida>110 && valida<115 || valida>115);
    }

    valida='s';
    lista_disc(disciplinas,n_disc);
    while(valida!='n')
    {
        do{
            printf("\nDigite o nome da disciplina: ");
            fflush(stdin);
            gets(nome);
            strupr(nome);
        }while(strlen(nome)==0);

        existe=1;
        for(i=0;i<n_disc;i++)
            if(strcmp(nome,disciplinas[i].nome)==0)
            {
                existe=0;  ///a disciplina está cadastrada
                for(j=0;j<aluno;j++)
                    for(z=0;z<n_alunos;z++)
                        if(z==posicao_aluno[j])
                            {
                                strcpy(alunos[z].disciplinas[i].nome,disciplinas[i].nome);
                                strcpy(alunos[z].disciplinas[i].codigo,disciplinas[i].codigo);
                            }
            }
        if(existe==1)
            printf("\nEssa disciplina ainda n\306o est\240 cadastrado\n");

        do{
            printf("Deseja incluir mais uma disciplina?(s/n) ");
            fflush(stdin);
            scanf("%c",&valida);
            valida=tolower(valida);
        }while(valida<110 || valida>110 && valida<115 || valida>115);
    }

}

void vincula_professor(PROFESSORES professores[],DISCIPLINAS disciplinas[],int n_disc,int n_prof){
    int i, existe, posicao_prof[MAX], j=0, prof=0, z;
    char nome[max_nome],valida='s',vazio[max_nome]="vazio";
    printf("\nVINCULO DE PROFESSOR EM DISCIPLINA\n======================================\n");
    lista_prof(professores,n_prof);
    while(valida!='n')
    {
        do{
            printf("\nDigite o nome do professor: ");
            fflush(stdin);
            gets(nome);
            strupr(nome);
        }while(strlen(nome)==0);

        existe=1;

        for(i=0;i<n_prof;i++)
            if(strcmp(nome,professores[i].nome)==0)
            {
                existe=0;
                prof++;
                posicao_prof[j]=i;
                j++;
            }
        if(existe==1)
            printf("\nEsse professor ainda n\306o est\240 cadastrado!\n");

        do{
            printf("Deseja vincular mais um professor?(s/n) ");
            fflush(stdin);
            scanf("%c",&valida);
            valida=tolower(valida);
        }while(valida<110 || valida>110 && valida<115 || valida>115);
    }

    valida='s';
    lista_disc(disciplinas,n_disc);
    while(valida!='n')
    {
        do{
            printf("\nDigite o nome da disciplina: ");
            fflush(stdin);
            gets(nome);
            strupr(nome);
        }while(strlen(nome)==0);

        existe=1;
        for(i=0;i<n_disc;i++)
            if(strcmp(nome,disciplinas[i].nome)==0)
            {
                existe=0;
                for(j=0;j<prof;j++)
                    for(z=0;z<n_prof;z++)
                        if(z==posicao_prof[j])
                            {
                                strcpy(professores[z].disciplinas[i].nome,disciplinas[i].nome);
                                strcpy(professores[z].disciplinas[i].codigo,disciplinas[i].codigo);
                            }
            }
        if(existe==1)
            printf("\nEssa disciplina ainda n\306o est\240 cadastrado\n");

        do{
            printf("Deseja incluir mais uma disciplina?(s/n) ");
            fflush(stdin);
            scanf("%c",&valida);
            valida=tolower(valida);
        }while(valida<110 || valida>110 && valida<115 || valida>115);
    }
}

void cancela_matricula_aluno(ALUNOS alunos[],DISCIPLINAS disciplinas[],int n_disc,int n_alunos){
    int i,existe,aluno=0,posicao_aluno[MAX],j=0,z;
    char nome[max_nome],valida='s',vazio[max_nome]="vazio";
    printf("\nCANCELAMENTO DE MATRICULA\n============================\n");
    lista_alunos(alunos,n_alunos);
    while(valida!='n')
    {
        do{
            printf("\nDigite o nome do aluno: ");
            fflush(stdin);
            gets(nome);
            strupr(nome);
        }while(strlen(nome)==0);

        existe=1;

        for(i=0;i<n_alunos;i++)
            if(strcmp(nome,alunos[i].nome)==0)
            {
                existe=0;
                aluno++;
                posicao_aluno[j]=i;
                j++;
            }
        if(existe==1)
            printf("\nEsse aluno ainda n\306o est\240 cadastrado!\n");

        do{
            printf("Deseja cancelar matricula de mais um aluno?(s/n) ");
            fflush(stdin);
            scanf("%c",&valida);
            valida=tolower(valida);
        }while(valida<110 || valida>110 && valida<115 || valida>115);
    }

    valida='s';
    lista_disc(disciplinas,n_disc);
    while(valida!='n')
    {
        do{
            printf("\nDigite o nome da disciplina: ");
            fflush(stdin);
            gets(nome);
            strupr(nome);
        }while(strlen(nome)==0);

        existe=1;
        for(i=0;i<n_disc;i++)
            if(strcmp(nome,disciplinas[i].nome)==0)
            {
                existe=0;
                for(j=0;j<aluno;j++)
                    for(z=0;z<n_alunos;z++)
                        if(z==posicao_aluno[j])
                            if(strcmp(disciplinas[i].nome,alunos[z].disciplinas[i].nome)==0)
                            {
                                strcpy(alunos[z].disciplinas[i].nome,vazio);
                                strcpy(alunos[z].disciplinas[i].codigo,vazio);
                            }
            }
        if(existe==1)
            printf("\nEssa disciplina ainda n\306o est\240 cadastrado\n");

        do{
            printf("Deseja incluir mais uma disciplina?(s/n) ");
            fflush(stdin);
            scanf("%c",&valida);
            valida=tolower(valida);
        }while(valida<110 || valida>110 && valida<115 || valida>115);
    }
}

void cancela_vinculo_prof(PROFESSORES professores[],DISCIPLINAS disciplinas[],int n_disc,int n_prof){
    int i,existe,prof=0,posicao_prof[MAX],j=0,z;
    char nome[max_nome],valida='s',vazio[max_nome]="vazio";
    printf("\nREMO\200\307O DE VINCULO\n============================\n");
    lista_prof(professores,n_prof);
    while(valida!='n')
    {
        do{
            printf("\nDigite o nome do professor: ");
            fflush(stdin);
            gets(nome);
            strupr(nome);
        }while(strlen(nome)==0);

        existe=1;

        for(i=0;i<n_prof;i++)
            if(strcmp(nome,professores[i].nome)==0)
            {
                existe=0;
                prof++;
                posicao_prof[j]=i;
                j++;
            }
        if(existe==1)
            printf("\nEsse professor ainda n\306o est\240 cadastrado!\n");

        do{
            printf("Deseja remover vinculo de mais um professor?(s/n) ");
            fflush(stdin);
            scanf("%c",&valida);
            valida=tolower(valida);
        }while(valida<110 || valida>110 && valida<115 || valida>115);
    }

    valida='s';
    lista_disc(disciplinas,n_disc);
    while(valida!='n')
    {
        do{
            printf("\nDigite o nome da disciplina: ");
            fflush(stdin);
            gets(nome);
            strupr(nome);
        }while(strlen(nome)==0);

        existe=1;
        for(i=0;i<n_disc;i++)
            if(strcmp(nome,disciplinas[i].nome)==0)
            {
                existe=0;
                for(j=0;j<prof;j++)
                    for(z=0;z<n_prof;z++)
                        if(z==posicao_prof[j])
                            if(strcmp(disciplinas[i].nome,professores[z].disciplinas[i].nome)==0)
                            {
                                strcpy(professores[z].disciplinas[i].nome,vazio);
                                strcpy(professores[z].disciplinas[i].codigo,vazio);
                            }
            }
        if(existe==1)
            printf("\nEssa disciplina ainda n\306o est\240 cadastrado\n");

        do{
            printf("Deseja incluir mais uma disciplina?(s/n) ");
            fflush(stdin);
            scanf("%c",&valida);
            valida=tolower(valida);
        }while(valida<110 || valida>110 && valida<115 || valida>115);
    }
}

int main()
{
    int acao;
    int n_alunos=0, n_prof=0, n_disc=0;
    ALUNOS alunos[MAX];
    DISCIPLINAS disciplinas[MAX];
    PROFESSORES professores[MAX];

    while(acao!=4)
    {
        system("cls");
        acao=menu();
        system("cls");
        switch(acao)
        {
            case 1: acao=menu_aluno();
                system("cls");
                switch(acao)
                {
                    case 1: n_alunos=cadastro_aluno(alunos,n_alunos); break;
                    case 2: matricula_aluno(alunos,disciplinas,n_disc,n_alunos); break;
                    case 3: cancela_matricula_aluno(alunos,disciplinas,n_disc,n_alunos); break;
                    case 4: lista_alunos(alunos,n_alunos); acao=0; system("pause"); break;
                    case 5: disc_aluno(alunos,disciplinas,n_disc,n_alunos); break;
                    case 6: break;
                    default: printf("A\207\306o inv\240lida!");
                }
                break;


            case 2: acao=menu_professor();
                system("cls");
                switch(acao)
                {
                    case 1: n_prof=cadastro_professor(professores,n_prof); break;
                    case 2: vincula_professor(professores,disciplinas,n_disc,n_prof); break;
                    case 3: cancela_vinculo_prof(professores,disciplinas,n_disc,n_prof); break;
                    case 4: lista_prof(professores,n_prof); acao=0; system("pause"); break;
                    case 5: disc_prof(professores,disciplinas,n_disc,n_prof); break;
                    case 6: break;
                    default: printf("A\207\306o inv\240lida!");
                }
                break;


            case 3: acao=menu_disciplina();
                system("cls");
                switch(acao)
                {
                    case 1: n_disc=cadastro_disciplina(disciplinas,n_disc); break;
                    case 2: lista_disc(disciplinas,n_disc); system("pause"); break;
                    case 3: alunos_disc(alunos,disciplinas,n_disc,n_alunos); break;
                    case 4: profs_disc(professores,disciplinas,n_disc,n_prof); acao=0; break;
                    case 5: break;
                    default: printf("A\207\306o inv\240lida!");
                }

            case 4: break;

            default: printf("A\207\306o inv\240lida!");
        }
    }

    return 0;
}

