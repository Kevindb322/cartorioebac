#include <stdio.h>																									//biblioteca de comunica��o com o usu�rio
#include <stdlib.h>	
#include <stdbool.h>																								//Aloca��o de espa�o na mem�ria
#include <locale.h>																									//Biblioteca de aloca��o de texto por regi�o
#include <string.h>																									//Biblioteca responsavel por cuidar das strings

int titulo()
{
	printf("++++++    +++++++++ \n");
	printf("+         +   +   + \n");
	printf("++++      +   +   + \n");
	printf("+         +   +   + \n");
	printf("++++++     + + + +                     ######################################\n");
	printf("                                       #########  Cartorio da EBAC  #########\n");
	printf("+++               +                    ######################################\n");
	printf("   ++         + \n");
	printf("    ++    +   +\n");
	printf("   ++         +\n");
	printf("+++               + \n\n");	
}


int login()
{
	char usuario[20];
	char senha[20];
	char usuarioc[] = "admin";
	char senhac[] = "admin";
	bool ver = false;
	while (ver == false)	
	{
		printf ("Digite o nome do usuário:\n");
		scanf ("%s", usuario);

		printf ("Digite a senha:\n");
		scanf ("%s", senha);

		if (strcmp(usuario,usuarioc) == 0 && strcmp(senha, senhac) == 0)
		{
			system("cls");
			ver = true;
			printf ("Usuario logado com sucesso.");
			system("pause");
			system ("cls");
		}
		else
		{
			system("cls");
			ver = false;
			printf ("Falha ao autenticar usuario, por favor cheque novamente.");
			system("pause");
			system("cls");
		}
	}
}

int menuP()
{
	printf("Escolha a opcao desejada:\n\n");
	printf("\t1 - Registrar nomes.\n");																				// o \t da um tab
	printf("\t2 - Consultar nomes.\n");
	printf("\t3 - Deletar nomes.\n");
	printf("\t0 - Sair do programa.\n");	
}

int registro()
{
//Variaveis
	char arquivo[40];
	char cpf[11];
	char nome[40];
	char sobrenome[40];
	char cargo[40];
	int loop = 0;																										//Loop da fun��o registro
	int loop_Cadastrar = 0;																								//Repete a pergunta se deseja realizar mais algum cadastro
	int op = 0;																											//Op��o do usuario de cadastrar mais algum individuo
	
//Inicio
	while (loop != 2)
	{
//Aparencia	
		titulo();

//Cadastro CPF
		printf("Opcao de cadastro selecionado:\n\n");
		printf("Por favor digite o CPF do usuario:\n");
		scanf("%s", cpf);
	
		strcpy(arquivo, cpf);																							//Copia o valor das strings

//criando arquivo e adicionando cpf	
		FILE *file;																										//Cria o arquivo
		file = fopen(arquivo, "w");																						//Escreve no arquivo
		fprintf(file, cpf);																								//Salva o valor da vari�vel
		fclose(file);																									//Fecha o arquivo

//Adicionando espaco
		file = fopen(arquivo, "a");
		fprintf(file, "\n");
		fclose(file);

//Cadastro do nome
		printf("Digite o nome do usuario:\n");
		scanf("%s", nome);

//Adicionando nome no arquivo
		file = fopen(arquivo, "a");
		fprintf(file,"Nome: %s ", nome);

//Cadastro do sobrenome
		printf("Digite o sobrenome do usuario:\n");
		scanf("%s", sobrenome);

//Adicionando sobrenome no arquivo
		fprintf(file,"%s.\n", sobrenome);


//Cadastro do cargo
		printf("Digite o cargo do usuario:\n");
		scanf("%s", cargo);

//Adicionando cargo no arquivo
		fprintf(file,"Cargo: %s.", cargo);
		
//Fechando o arquivo
		fclose(file);

		system("cls");
		printf("Cadastro Realizado com Sucesso!!!\n");
	
		system("pause");
		system("cls");

		if (repeticao_menu(1) == 0)
		{
			loop = 2;
			system("cls");
		}
	}
			
}

int consulta()
{
//Variaveis
	char cpf[40];
	char conteudo[200];
	int loop = 0;

//Inicio	
	while (loop != 2)
	{
//Apareencia
		titulo();
		printf("Consultar nomes selecionado:\n");
		printf("Digite o CPF a ser consultado:\n");
		scanf("%s", cpf);

//Abrir Arquivo		
		FILE *file;
		file = fopen(cpf, "r");
	
		if (file == NULL)
		{
			printf("Arquivo nao localizado.\n");
			system("cls");
		}
		else
		{
			printf("As informacoes do usuario:\n");
			printf("CPF: ");
		
			while(fgets(conteudo, 200, file) != NULL)
			{
				printf("%s", conteudo);		
			}
			printf("\n");
			fclose(file);
			system("pause");
			system("cls");
		}
		if (repeticao_menu(2) == 0)
		{
			loop = 2;
			system("cls");
		}
	}
}

int deletar()
{
// Variaveis
	char cpf[40];
	int loop = 0;
	
// Inicio	
	while (loop != 2)
	{
		titulo();
		printf("Deletar nomes selecionado:\n");
		printf("Por favor, digite o CPF do usuario a ser deletado:\n");
		scanf("%s", cpf);
		
		FILE *file;
		file = fopen(cpf, "r");
	
		if (file == NULL)
		{
			printf("Usuario inexistente!!!\n"); 
			printf("Por favor verifique o CPF digitado e tente novamente.\n");
			system("pause");
			system("cls");
			fclose(file);
		}
		else
		{
			if(repeticao_delete(cpf) == 1)
			{
				titulo();
				printf("Deletar nomes selecionado:\n");
				printf("Usuario removido com sucesso!!!\n");
				system("pause");
				fclose(file);
				remove(cpf);
			}
			else
			{
				titulo();
				printf("Tudo bem, usuario nao deletado.\n");
				system("pause");
				fclose(file);
			}
			
		}
		
		
		if (repeticao_menu(3) == 0)
		{
			loop = 2;
		}		
	}
}

int repeticao_delete(char cpf[40])
{
// Variaveis
	int op = 0;
	int repetir = 0;

//Inicio
	while (repetir != 1)
	{
		system("cls");
		titulo();
		printf("O CPF: %s esta prestes a ser deletado do sistema.\n", cpf);
		printf("Tem certeza que deseja deletar este usuario?\n");
		printf("\t1 - Sim.\n");
		printf("\t2 - Nao.\n");
		scanf("%d", &op);
		switch(op)
		{
			case (1):
				system("cls");
				return 1;
			break;
			
			case (2):
				system("cls");
				return 0;				
			break;
			
			default:
				printf("Opcao selecionada invalida.\n");
				system("pause");
				system("cls");
			break;
		}
	}
}

int repeticao_menu(int menu)
{
// Variaveis
	int op = 0;
	int repetir = 0;

// Inicio	
	while (repetir != 1)
	{
		system("cls");
		titulo();
		switch(menu)
		{
			case (1):
				printf("A opcao selecionada e a de registrar usuarios.\n");
				break;
			case (2):
				printf("A opcao selecionada e a de consultar usuarios.\n");
				break;
			case (3):
				printf("A opcao selecionada e a de deletar usuarios.\n");
				break;
		}
		printf("Deseja repetir esta operacao:\n");
		printf("\t1 - Sim.\n");
		printf("\t2 - Nao.\n");
		scanf("%d", &op);
		switch(op)
		{
			case (1):
				system("cls");
				return 1;
			break;
			
			case (2):
				system("cls");
				return 0;				
			break;
			
			default:
				printf("Opcao selecionada invalida.\n");
				system("pause");
				system("cls");
			break;
		}
	}
}

// FUNCAO PRINCIPAL
int main()
{
//Variaveis
	int opcao = 0;
	int loop = 1;

		
//Seleciona o idioma, trazendo os acentos para o nosso programa	
    setlocale(LC_ALL, "Portuguese");

//Inicio
	login();

	while (loop != 2)
	{
		titulo();																									//Chama a fun��o do logo
		menuP();																									//Chama a fun��o do Menu Principal
		printf("Sua opcao: ");
		scanf("%d", &opcao);																						//Registra a op��o do usu�rio
		system("cls");																								//Limpa a tela
	 		
		switch (opcao)
		{
			case (0):				
				titulo();																							//Chama a fun��o do logo
				printf("Obrigado por utilizar nosso cartorio.\n");
				system("pause");		
				system("cls");
				printf("Programa finalizado!!! Aperte qualquer tecla para sair.\n");
				system("pause");		
				loop = 2;
			break;
			
			case (1):
				registro();								
			break;
			
			case (2):
				consulta();																							//Chama a fun��o para consultar
			break;
				
			case (3):
				deletar();																							//Chama a fun��o para deletar
			break;
			
			default:
				titulo();
				printf("Opcao selecionada invalida.\n");
				system("pause");
				system("cls");
			break;
		}				    																						//Fim switch case			
	}																												//Fim loop while
}
