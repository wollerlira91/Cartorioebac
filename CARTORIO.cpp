#include <stdio.h> //biblioteca de comunincação com o usuário 
#include <stdlib.h> //biblioteca de alocação de espaço em memória
#include <locale.h> //biblioteca de alocações de texto po região
#include <string.h> //biblioteca responsável por cuidar das string

int registro()//função responsvel por cadastrar o usuário no sistema
{
	//início craição de variaveis/sring
	char arquivo[40];
	char cpf[40];
	char nome[40];
	char sobrenome[40];
	char cargo[40];
	//final da criação de variaveis/sring

	
	printf("Digite o CPF a ser cadastrado:");//coletando informações do usuário
	scanf("%s", cpf);//%s referse a strings
	
	strcpy(arquivo,cpf);  //Responsável por copiar os valores das string
	
	FILE *file; //cria o arquivo 
	file = fopen(arquivo, "w"); // cria o arquivo
	fprintf(file, cpf); // savlo o valor da variável
	fclose(file); // fecha o arquivo
	
	file= fopen(arquivo, "a");
	fprintf(file,",");
	fclose(file);	
	
	printf("Digite o nome a ser cadastrado:");
	scanf("%s", nome);
	
	file= fopen(arquivo, "a");
	fprintf(file,nome);
	fclose(file);
	
    file= fopen(arquivo, "a");
	fprintf(file,",");
	fclose(file);
		
	printf("Digite o sobrenome a ser cadastrado:");
	scanf("%s", sobrenome);
	
	file= fopen(arquivo, "a");
	fprintf(file,sobrenome);
	fclose(file);
	
	file= fopen(arquivo, "a");
	fprintf(file,",");
	fclose(file);
		
	printf("Digite o cargo a ser cadastrado:");
	scanf("%s", cargo);	
	
	file= fopen(arquivo, "a");
	fprintf(file,cargo);
	fclose(file);
	
	system("pause");
		
	
	
	
}
	
	
int consulta()	
{
	 setlocale(LC_ALL, "Portuguese");//Definindo a linguagem.
	
	char cpf[40];//variavel de consulta
	char conteudo[200];//variavel de consulta
	
	printf("Digite o CPF a ser consultado");//entrada de informação
	scanf("%s",cpf);//informação de cfp informado levada para a string
	
	FILE*file; //abestura de aquirvo file
	file = fopen(cpf,"r");//
	
	if(file==NULL)
	
	{
		printf("Não foi possível abrir o arquivo, não localizado!.\n0");
	}
	
	while(fgets(conteudo,200, file)!=NULL)
	{
		printf("\nEssas são as infrmações do usuário:");
		printf("%s", conteudo);
		printf("\n\n");
	}
	
	system("pause");
	
}

int deletar()
{
	setlocale(LC_ALL, "Portuguese");//Definindo a linguagem.
	
	char cpf[40];//variavel de consulta
	
	printf("Digite o CPF a ser deletado:");
	scanf("%s",cpf);
	
	remove(cpf);
	
	FILE *file;
	file = fopen(cpf,"r");
	
	if(file == NULL)
	{
		printf("Usuário não se encontra no sistem!.\n");
		system("pause");
	}
		
	
}

int main()
{
	int opcao=0;// Definindo as variáveis.
	int laco=1;
	
	for(laco=1;laco=1;)
	{
	    system("cls");
	    setlocale(LC_ALL, "Portuguese");//Definindo a linguagem.
	 
	     printf("###Cartório da EBAC### \n\n");//Início do menu.
    	 printf("Escolha a opção de sejada do menu: \n\n");
    	 printf("\t1 - Registra nomes \n");
    	 printf("\t2 - Consultar os nomes \n");
     	 printf("\t3 - Deletar nomes\n\n");
	     printf("Opção: ");//Final do menu
	 
	     scanf("%d", &opcao);//Armazenando escolha do usuário.
    	
    	  system("cls");
    	  
    	  
    	  switch(opcao)//Processamento de informações.
    	  {
		  
    	    case 1:
    	  	registro();
     	  	break;
    	  	
    	  	case 2:
    	  	consulta();
    	  	break;
    	  	
    	  	case 3:
    	  	deletar();
    	  	break;
    	  	
    	  	
    	  	default:
    	  	printf("Essa opção não está disponível\n");
    		system("pause");
    		break;
    	  }//Fim!
	
    }
}
