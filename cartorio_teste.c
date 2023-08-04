#include <stdio.h>																									//biblioteca de comunicação com o usuário
#include <stdlib.h>																									//Alocação de espaço na memória
#include <locale.h>																									//Biblioteca de alocação de texto por região
#include <string.h>																									//Biblioteca responsavel por cuidar das strings

int titulo()
{
	printf("++++++    +++++++++ \n");
	printf("+         +   +   + \n");
	printf("++++      +   +   + \n");
	printf("+         +   +   + \n");
	printf("++++++     + + + +                     ######################################\n");
	printf("                                       #########  Cartório da EBAC  #########\n");
	printf("+++               +                    ######################################\n");
	printf("   ++         + \n");
	printf("    ++    +   +\n");
	printf("   ++         +\n");
	printf("+++               + \n\n");	
}

int menuP()
{
	printf("Escolha a opção desejada:\n\n");
	printf("\t1 - Registrar nomes.\n");																				// o \t da um tab
	printf("\t2 - Consultar nomes.\n");
	printf("\t3 - Deletar nomes.\n");
	printf("\t0 - Sair do programa.\n");	
}

int registro()
{
//Variáveis
	char arquivo[40];
	char cpf[11];
	char nome[40];
	char sobrenome[40];
	char cargo[40];
	int loop = 0;																										//Loop da função registro
	int loop_Cadastrar = 0;																								//Repete a pergunta se deseja realizar mais algum cadastro
	int op = 0;																											//Opção do usuario de cadastrar mais algum individuo
	
//Início
	while (loop != 2)
	{
//Aparencia	
		titulo();
//Cadastro CPF
		printf("Opção de cadastro selecionado:\n\n");
		printf("Por favor digite o CPF do usuário:\n");
		scanf("%s", cpf);
	
		strcpy(arquivo, cpf);																							//Copia o valor das strings

//criando arquivo e adicionando cpf	
		FILE *file;																										//Cria o arquivo
		file = fopen(arquivo, "w");																						//Escreve no arquivo
		fprintf(file, cpf);																								//Salva o valor da variável
		fclose(file);																									//Fecha o arquivo

//Adicionando espaço
		file = fopen(arquivo, "a");
		fprintf(file, "\n");
		fclose(file);

//Cadastro do nome
		printf("Digite o nome do usuário:\n");
		scanf("%s", nome);

//Adicionando nome no arquivo
		file = fopen(arquivo, "a");
		fprintf(file,"Nome: %s ", nome);

//Cadastro do sobrenome
		printf("Digite o sobrenome do usuário:\n");
		scanf("%s", sobrenome);

//Adicionando sobrenome no arquivo
		fprintf(file,"%s.\n", sobrenome);


//Cadastro do cargo
		printf("Digite o cargo do usuário:\n");
		scanf("%s", cargo);

//Adicionando cargo no arquivo
		fprintf(file,"Cargo: %s.", cargo);
		
//Fechando o arquivo
		fclose(file);

		system("cls");
		printf("Cadastro Realizado com Sucesso!!!\n");
	
		system("pause");
		system("cls");

		if (repeticao() == 0)
		{
			loop = 2;
			system("cls");
		}
	}
			
}

int consulta()
{
//Variáveis
	char cpf[40];
	char conteudo[200];
	int loop = 0;
//Início	
	while (loop != 2)
	{
		titulo();
		printf("Consultar nomes selecionado:\n");
		printf("Digite o CPF a ser consultado:\n");
		scanf("%s", cpf);
		
		FILE *file;
		file = fopen(cpf, "r");
	
		if (file == NULL)
		{
			printf("Arquivo não localizado.\n");
			system("cls");
		}
		else
		{
			printf("As informações do usuario:\n");
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
		if (repeticao() == 0)
		{
			loop = 2;
			system("cls");
		}
	}
}

int deletar()
{
	titulo();
	printf("Deletar nomes selecionado:\n");

	system("pause");
	system("cls");
	
}

int repeticao()
{
	int op = 0;
	int repetir = 0;
	
	while (repetir != 1)
	{
		titulo();
		printf("Deseja repetir esta operação:\n");
		printf("\t1 - Sim.\n");
		printf("\t2 - Não.\n");
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
				printf("Opção selecionada inválida.\n");
				system("pause");
				system("cls");
			break;
		}
	}
}


int main()
{
//Variáveis
	int opcao = 0;
	int loop = 1;
	
	
	setlocale(LC_ALL, "Portuguese");																				//Seleciona o idioma, trazendo os acentos para o nosso programa

//Início
	while (loop != 2)
	{
		titulo();																									//Chama a função do logo
		menuP();																									//Chama a função do Menu Principal
		printf("Sua opção: ");
		scanf("%d", &opcao);																						//Registra a opção do usuário
		system("cls");																								//Limpa a tela
	 		
		switch (opcao)
		{
			case (0):				
				titulo();																							//Chama a função do logo
				printf("Obrigado por utilizar nosso cartório.\n");
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
				consulta();																							//Chama a função para consultar
			break;
				
			case (3):
				deletar();																							//Chama a função para deletar
			break;
			
			default:
				titulo();
				printf("Opção selecionada inválida.\n");
				system("pause");
				system("cls");
			break;
		}																											//Fim switch case			
	}																												//Fim loop while
}
