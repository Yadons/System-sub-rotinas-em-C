#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <string.h>

//Cria��o de um produto
struct dados {
	char nome[50];
	char cpf[15];
	int atendimento;
};

struct dados dados[1000]; // vari�veis globais.
int cont = 0;

//Mostrar o primeiro menu de op��es
void mostrarMenu(){
	printf("Bem-vindo ao sistema de atendimento\n");
	printf(" 1 - Solicitar Atendimento\n 2 - Listar Atendimentos Registrados\n 3 - Listar Atendimentos por Setor\n 4 - Sair\n");
	fflush(stdin);
}

// Ler o procedimento e retornar o valo da op��o.
int lerMenu(){
	mostrarMenu(); // Chama o menu acima
	int opcao;
	scanf("%d", &opcao);
	return opcao;
}

void registrar(){ // procedimento para registrar o atendimento
	printf(" Op��o - Registrar Atendimento\n");
	printf(" Digite o seu nome \n");
	fflush(stdin);
	gets(dados[cont].nome);
	printf(" Digite o seu CPF \n");
	fflush(stdin);
	gets(dados[cont].cpf);
	printf(" Digite uma das op��es de atendimento\n");
	printf(" 1 - Abertura de Conta \n 2 - Caixa \n 3 - Gerente Pessoa F�sica\n 4 - Gerente Pessoa Jur�dica\n");
	fflush(stdin);
	scanf("%d", &dados[cont].atendimento);
	cont = cont + 1;
}

void listarRegistros(){ // Vai listar todos os registros do sistema
	int i;
	for(i = 0; i < cont ; i++) {
		printf("Nome: %s\n", dados[i].nome);
		fflush(stdin);
		printf("CPF: %s\n", dados[i].cpf);
		fflush(stdin);
		if(dados[i].atendimento == 1){
			printf(" Tipo de atendimento: %d - Abertura de Conta", dados[i].atendimento);
		}else if(dados[i].atendimento == 2){
			printf(" Tipo de atendimento: %d - Caixa", dados[i].atendimento);
		}else if(dados[i].atendimento == 3) {
			printf(" Tipo de atendimento: %d - Gerente Pessoa F�sica", dados[i].atendimento);
		}else if(dados[i].atendimento == 4){
			printf(" Tipo de atendimento: %d - Gerente Pessoa Jur�dica", dados[i].atendimento);
		}
		fflush(stdin);
		printf("\n--------------------------\n");
		printf("--------------------------\n");
	}
}

void atendimentoPorSetor(){
	int por_setor = 0;
	printf(" Digite uma das op��es de atendimento\n");
	printf(" 1 - Abertura de Conta \n 2 - Caixa \n 3 - Gerente Pessoa F�sica\n 4 - Gerente Pessoa Jur�dica\n");
	scanf("%d", &por_setor);
	int j;
	for(j = 0; j < cont; j++) {
	
		if((dados[j].atendimento == por_setor) && (dados[j].atendimento == 1) ) {
			printf("Nome: %s\n", dados[j].nome);
			fflush(stdin);
			printf("CPF: %s\n", dados[j].cpf);
			fflush(stdin);
			printf(" Tipo de atendimento: %d - Abertura de Conta", dados[j].atendimento);
			printf("\n-------------------------------------------\n");
			printf("-------------------------------------------\n");	
		}else if((dados[j].atendimento == por_setor) && (dados[j].atendimento == 2)) {
			printf("Nome: %s\n", dados[j].nome);
			fflush(stdin);
			printf("CPF: %s\n", dados[j].cpf);
			fflush(stdin);
			printf(" Tipo de atendimento: %d - Caixa", dados[j].atendimento);
			printf("\n-------------------------------------------\n");
			printf("-------------------------------------------\n");
		}else if((dados[j].atendimento == por_setor) && (dados[j].atendimento == 3)) {
			printf("Nome: %s\n", dados[j].nome);
			fflush(stdin);
			printf("CPF: %s\n", dados[j].cpf);
			fflush(stdin);
			printf(" Tipo de atendimento: %d - Gerente Pessoa F�sica", dados[j].atendimento);
			printf("\n-------------------------------------------\n");
			printf("-------------------------------------------\n");	
		}else if((dados[j].atendimento == por_setor) && (dados[j].atendimento == 4)) {
			printf("Nome: %s\n", dados[j].nome);
			fflush(stdin);
			printf("CPF: %s\n", dados[j].cpf);
			fflush(stdin);
			printf(" Tipo de atendimento: %d - Gerente Pessoa Jur�dica", dados[j].atendimento);
			printf("\n-------------------------------------------\n");
			printf("-------------------------------------------\n");
		}
	}
}

int main() {
	setlocale(LC_ALL, "Portuguese");	
	int opcao; // Usado para a estrutura de repeti��o abaixo.
	do{
		opcao = lerMenu(); // chamando a op��o de ler menu.
		
		if(opcao != 4){
			switch (opcao){
				case 1:
					system("cls");
					registrar();
					break;
				case 2:
					system("cls");
					listarRegistros();
					break;
				case 3:
					system("cls");
					atendimentoPorSetor();
					break;
				default:
				printf(" Informe um valr que seja v�lido! \n");	
			}
		}
	}while(opcao !=4);
	return 0;
}
