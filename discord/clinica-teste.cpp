#include<stdio.h>
#include<string.h>

#define MAX 2

typedef struct
{
    char cod[3]; 
    char nome[120];
    int valido;
} especialidade_t;

typedef struct
{
    char usuario[60];
    char senha[60];
} login_t;

typedef struct 
{
    char crm[10];
    char nome[120];
    especialidade_t especialidade;
    login_t login;
    int valido;
} medico_t;

typedef struct 
{
    char matricula[3];
    char nome[120];
    login_t login;
    int valido;
} funcionario_t;

typedef struct 
{
    char nome[120];
    char cpf[14];
    char telefone[16];
    login_t login;
    int valido;
} paciente_t;

void init(login_t *adm,especialidade_t especialidade_vet[], medico_t medico_vet[],funcionario_t funcionario_vet[], paciente_t paciente_vet[]);

void menu_login(login_t *adm,especialidade_t especialidade_vet[], medico_t medico_vet[],funcionario_t funcionario_vet[], paciente_t paciente_vet[]);
void menu_adm(especialidade_t especialidade_vet[], medico_t medico_vet[],funcionario_t funcionario_vet[], paciente_t paciente_vet[]);
void menu_func(paciente_t paciente_vet[]);


int main(){

    login_t adm;
    especialidade_t especialidade_vet[MAX];    
    medico_t medico_vet[MAX];
    funcionario_t funcionario_vet[MAX];
    paciente_t paciente_vet[MAX];

    init(&adm,especialidade_vet,medico_vet,funcionario_vet,paciente_vet);

    return 0;
}


void init(login_t *adm, especialidade_t especialidade_vet[], medico_t medico_vet[],funcionario_t funcionario_vet[], paciente_t paciente_vet[]){

    strcpy(adm->usuario,"adm");
    strcpy(adm->senha,"123");
    for(int i = 0; i<MAX; i++){
        especialidade_vet[i].valido = 0;
        medico_vet[i].valido = 0;
        funcionario_vet[i].valido = 0;
        paciente_vet[i].valido = 0;
    }
}


void menu_login(login_t *adm,especialidade_t especialidade_vet[], medico_t medico_vet[],funcionario_t funcionario_vet[], paciente_t paciente_vet[]){
    do{
        
        printf("\n1 - ADM");
        printf("\n2 - FUNCIONARIO");
        printf("\n0 - SAIR");

        int opcao;
        printf("\n\nSelecione uma opção:");
        scanf("%d",&op);

        switch (op)
        {
        case 1:
            /* code */
            break;
        
        default:
            break;
        }


    }while (1);
    
}
void menu_adm(especialidade_t especialidade_vet[], medico_t medico_vet[],funcionario_t funcionario_vet[], paciente_t paciente_vet[]){

}
void menu_func(paciente_t paciente_vet[]){

}