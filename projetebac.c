#include <stdio.h> //biblioteca de comunicação com o usuário
#include <stdlib.h> //biblioteca de alocação de espaço em memória
#include <locale.h> //biblioteca de alocações de texto por região
#include <string.h> //biblioteca responável por cuidar da string

int	registro()//função responsável p/ registrar dados do usuário
{
	char arquivo[40];
	char cpf[40];
	char nome[40];
	char sobrenome[40];
	char cargo[40];
	
	printf("Digite o CPF a ser cadastrado: ");
	scanf("%s", cpf);
	
	strcpy(arquivo, cpf); //função resposável por copiar os valores da string
	
	FILE *file; //entar e criar o arquivo
	file = fopen(arquivo, "w"); //cria o arquivo com o 'w'
	fprintf(file,cpf);//salva o valor da variavel
	fclose(file); //fechar o arquivo
	
	file = fopen(arquivo, "a"); //'a' atualiza os dados do arquivo
	fprintf(file,",");
	fclose(file);
	
	printf("Digite o nome a ser cadastrado: ");
	scanf("%s", nome);
	
	file = fopen(arquivo, "a");
	fprintf(file, nome);
	fclose(file);
	
	file = fopen(arquivo, "a"); 
	fprintf(file,",");
	fclose(file);
	
	printf("Digite o sobrenome a ser cadastrado: ");
	scanf("%s", sobrenome);
	
	file = fopen(arquivo, "a");
	fprintf(file, sobrenome);
	fclose(file);
	
	file = fopen(arquivo, "a");
	fprintf(file,",");
	fclose(file);
	
	printf("Digite o cargo a ser cadastrado: ");
	scanf("%s", cargo);
	
	file = fopen(arquivo, "a");
	fprintf(file, cargo);
	fclose(file);
	
	file = fopen(arquivo, "a");
	fprintf(file,",");
	fclose(file);
}
	

int	consulta()//função responsável p/ consultar dados do usuário
{
	setlocale(LC_ALL, "Portuguese");
	
	char cpf[40];
	char conteudo[200];
	
	printf("Digite o CPF a ser consultado: ");
	scanf("%s", cpf);
	
	FILE *file;
	file = fopen(cpf, "r");
	
	if(file == NULL)
	{
		printf("Não foi localizado o arquivo!.\n");
	}
	
	while(fgets(conteudo, 200, file) != NULL)
	{
		printf("\nEssas são as informações do usuário: ");
		printf("%s", conteudo);
		printf("\n\n");
	}
	
	system("pause");
	
	
}

int	deletar()//função responsável p/ deletar o cpf do usuário
{
	char cpf[40];
	
	printf("Digite o CPF a ser deletado: ");
	scanf("%s", cpf);
	
	remove(cpf);
	
	
	
	FILE *file;
	file = fopen(cpf, "r");
	
	if(file == NULL)
	{
		printf("O usuário não se encontra no sistema!. \n");
		system("pause");
	}
}

int	main()
{
	
	setlocale(LC_ALL, "Portuguese"); //definindo a linguagem
	
	int	opcao = 0;
	int x = 1;

	for (x = 1; x = 1;)
	{
	system ("cls");//responsável por limpar a tela
	
	printf("### Cartório da EBAC ###\n\n");
	printf("Escolha a opção desejadado menu\n\n");
	printf("\t1 - Registrar nomes\n");
	printf("\t2 - Consultar nomes nomes\n");
	printf("\t3 - Deletar nomes\n\n");
	
	scanf("%d", &opcao); //armazenado a escolha do usuário
	
	system("cls");
	
	switch (opcao)
	{
		case 1:
		registro();//chamada de funções
		break;
		
		case 2:
		consulta();
		break;
		
		case 3:
		deletar();
		break;
		
		default:
		printf("Essa opção não está disponível");
		system("pause");	
		
		
	}
	
	
	}
}
	

