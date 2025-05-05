#include <stdio.h> //biblioteca de comunica��o com o usu�rio
#include <stdlib.h> //biblioteca de aloca��o de espa�o em mem�ria
#include <locale.h> // biblioteca de aloca��es de texto por regi�o
#include <string.h> // biblioteca respons�vel por cuidar das strings

int registro()
{
	char arquivo[40];
	char cpf[40]; //instru�oes em colchetes significa que sao string
	char nome[40];
	char sobrenome[40];
	char cargo[40];
	
	printf("Digite o CPF a ser cadastrado: ");
	scanf("%s", cpf); //significa que ir� salvar dentro de uma string 
	
	strcpy(arquivo, cpf); //Responsavel por copiar os valores das strings
	
	FILE *file; //cria o arquivo
	file = fopen(arquivo, "w"); //cria o arquivo do tipo write
	fprintf(file, cpf);// salvo dentro do "file" o valor da variavel, que ser� "cpf"; Esta dando um printf para o arquivo ao inves do usuario
	fclose(file); //fecha o arquivo
	
	file = fopen(arquivo, "a"); //"a" porque queremos atualiazr a informa��o dentro de "arquivo"
	fprintf(file, ",");
	fclose(file);
	
	printf("Digite o nome a ser cadastrado: ");
	scanf("%s", nome);
	
	file = fopen(arquivo, "a");
	fprintf(file, nome);// Salve dentro do arquivo. Qual arquivo? file. Salvar o que? variavel "nome"
	fclose(file);
	
	file = fopen(arquivo, "a");
	fprintf(file, ",");
	fclose(file);
	
	printf("Digite o sobrenome a ser cadastrado: ");
	scanf("%s", sobrenome);
	
	file = fopen(arquivo, "a");
	fprintf(file, sobrenome);
	fclose(file);
	
	file = fopen(arquivo, "a"); 
	fprintf(file, ",");
	fclose(file);
	
	printf("Digite o cargo a ser cadastrado: ");
	scanf("%s", cargo);
	
	file = fopen(arquivo, "a");
	fprintf(file, cargo);
	fclose(file);
	
	system("pause");

}

int consulta()
{
	setlocale(LC_ALL, "Portuguese");
	
	char cpf[40];
	char conteudo[200];
	
	printf("Digite o CPF a ser consultado: ");
	scanf("%s", cpf);
	
	FILE *file; 
	file = fopen(cpf, "r"); // pedindo para abrir o arquivo CPF e ler o arquivo "r" 
	
	if(file==NULL)// NULL � um valor que nao consta no banco de dados
	{
		printf("N�o foi poss�vel localizar o cadastro.\n");
	}
	
	while(fgets(conteudo, 200, file) !=NULL)// fgets significa que esta indo buscar um arquivo
		//enquanto estiver escrevendo na variavel CONTEUDO, at� 200 valores, que est�o dentro do file enquanto for diferente de NULL, ou seja enquanto tiver informa��o
	{
		printf("\nEssas s�o as informa��es do usu�rio: ");
		printf("%s", conteudo);
		printf("\n\n");
	}
	
	fclose(file);
	system("pause");
}

int deletar()
{
	char cpf[40];
	
	printf("Digite o cpf a ser deletado: ");
	scanf("%s",cpf);
	
	
	FILE *file;
	file = fopen(cpf,"r");
	
	if(file == NULL)
	{
		printf("Usu�rio n�o encontrado.\n");
		system("pause");
		
	}	
	
	else 

  {

    fclose(file); // Fecha o arquivo, pois ele existe

    remove(cpf); // Agora voc� pode remover o arquivo

    printf("Usu�rio deletado!\n");

    system("pause");

  }
  
 	 fclose(file);
}


int main()
{
		int opcao=0; //definindo vari�veis
		int x=1;
		
		for (x=1;x=1;)
		{
		setlocale(LC_ALL, "Portuguese"); //significa que o texto da nossa regi�o � portugues e ir� usar a norma de escrita dessa l�ngua
		
			printf("### Cart�rio da EBAC ###\n\n"); //in�cio do menu
			printf("Escolha a op��o desejada abaixo:\n\n");
			printf("\t1 - Registrar nomes\n");
			printf("\t2 - Consultar registros\n");
			printf("\t3 - Deletar registro\n\n"); 
			printf("\t4 - Sair do sistema\n\n""");
			printf("- Op��o: ");//final do menu
		
			scanf("%d", &opcao); //armazenando a escolha do usu�rio na vari�vel
		
			system("cls"); //comando para limpar a tela
			
			
			switch (opcao)
			{
				case 1: //os dois pontos sao usados como uma abertura de chaves
				registro();
				break;	// o break � usado para fechar as chaves que abrimos com os dois pontos
				
				case 2:
				consulta();
				break;
				
				case 3:
				deletar();
				break;
				
				case 4:
				printf("Obrigado por utilizar o sistema!\n");
				return 0;
				break;
				
				default: 
				printf("Comando inv�lido\n");
				system("pause");
				break;
			}
				system("cls");	
	}
}
