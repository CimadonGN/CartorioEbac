#include <stdio.h> //biblioteca de comunicação com o usuário
#include <stdlib.h> //biblioteca de alocação de espaço em memória
#include <locale.h> // biblioteca de alocações de texto por região
#include <string.h> // biblioteca responsável por cuidar das strings

int registro()
{
	char arquivo[40];
	char cpf[40]; //instruçoes em colchetes significa que sao string
	char nome[40];
	char sobrenome[40];
	char cargo[40];
	
	printf("Digite o CPF a ser cadastrado: ");
	scanf("%s", cpf); //significa que irá salvar dentro de uma string 
	
	strcpy(arquivo, cpf); //Responsavel por copiar os valores das strings
	
	FILE *file; //cria o arquivo
	file = fopen(arquivo, "w"); //cria o arquivo do tipo write
	fprintf(file, cpf);// salvo dentro do "file" o valor da variavel, que será "cpf"; Esta dando um printf para o arquivo ao inves do usuario
	fclose(file); //fecha o arquivo
	
	file = fopen(arquivo, "a"); //"a" porque queremos atualiazr a informação dentro de "arquivo"
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
	
	if(file==NULL)// NULL é um valor que nao consta no banco de dados
	{
		printf("Não foi possível localizar o cadastro.\n");
	}
	
	while(fgets(conteudo, 200, file) !=NULL)// fgets significa que esta indo buscar um arquivo
		//enquanto estiver escrevendo na variavel CONTEUDO, até 200 valores, que estão dentro do file enquanto for diferente de NULL, ou seja enquanto tiver informação
	{
		printf("\nEssas são as informações do usuário: ");
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
		printf("Usuário não encontrado.\n");
		system("pause");
		
	}	
	
	else 

  {

    fclose(file); // Fecha o arquivo, pois ele existe

    remove(cpf); // Agora você pode remover o arquivo

    printf("Usuário deletado!\n");

    system("pause");

  }
  
 	 fclose(file);
}


int main()
{
		int opcao=0; //definindo variáveis
		int x=1;
		
		for (x=1;x=1;)
		{
		setlocale(LC_ALL, "Portuguese"); //significa que o texto da nossa região é portugues e irá usar a norma de escrita dessa língua
		
			printf("### Cartório da EBAC ###\n\n"); //início do menu
			printf("Escolha a opção desejada abaixo:\n\n");
			printf("\t1 - Registrar nomes\n");
			printf("\t2 - Consultar registros\n");
			printf("\t3 - Deletar registro\n\n"); 
			printf("\t4 - Sair do sistema\n\n""");
			printf("- Opção: ");//final do menu
		
			scanf("%d", &opcao); //armazenando a escolha do usuário na variável
		
			system("cls"); //comando para limpar a tela
			
			
			switch (opcao)
			{
				case 1: //os dois pontos sao usados como uma abertura de chaves
				registro();
				break;	// o break é usado para fechar as chaves que abrimos com os dois pontos
				
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
				printf("Comando inválido\n");
				system("pause");
				break;
			}
				system("cls");	
	}
}
