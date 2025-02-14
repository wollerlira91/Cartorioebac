#include <stdio.h> //biblioteca de comuninca��o com o usu�rio 
#include <stdlib.h> //biblioteca de aloca��o de espa�o em mem�ria
#include <locale.h> //biblioteca de aloca��es de texto po regi�o
#include <string.h> //biblioteca respons�vel por cuidar das string

int registro()//fun��o responsvel por cadastrar o usu�rio no sistema
{
	//in�cio crai��o de variaveis/sring
	char arquivo[40];
	char cpf[40];
	char nome[40];
	char sobrenome[40];
	char cargo[40];
	//final da cria��o de variaveis/sring

	
	printf("Digite o CPF a ser cadastrado:");//coletando informa��es do usu�rio
	scanf("%s", cpf);//%s referse a strings
	
	strcpy(arquivo,cpf);  //Respons�vel por copiar os valores das string
	
	FILE *file; //cria o arquivo 
	file = fopen(arquivo, "w"); // cria o arquivo
	fprintf(file, cpf); // savlo o valor da vari�vel
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
	
	printf("Digite o CPF a ser consultado");//entrada de informa��o
	scanf("%s",cpf);//informa��o de cfp informado levada para a string
	
	FILE*file; //abestura de aquirvo file
	file = fopen(cpf,"r");//
	
	if(file==NULL)
	
	{
		printf("N�o foi poss�vel abrir o arquivo, n�o localizado!.\n0");
	}
	
	while(fgets(conteudo,200, file)!=NULL)
	{
		printf("\nEssas s�o as infrma��es do usu�rio:");
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
		printf("Usu�rio n�o se encontra no sistem!.\n");
		system("pause");
	}
		
	
}

int main()
{
	int opcao=0;// Definindo as vari�veis.
	int laco=1;
	
	for(laco=1;laco=1;)
	{
	    system("cls");
	    setlocale(LC_ALL, "Portuguese");//Definindo a linguagem.
	 
	     printf("###Cart�rio da EBAC### \n\n");//In�cio do menu.
    	 printf("Escolha a op��o de sejada do menu: \n\n");
    	 printf("\t1 - Registra nomes \n");
    	 printf("\t2 - Consultar os nomes \n");
     	 printf("\t3 - Deletar nomes\n\n");
	     printf("Op��o: ");//Final do menu
	 
	     scanf("%d", &opcao);//Armazenando escolha do usu�rio.
    	
    	  system("cls");
    	  
    	  
    	  switch(opcao)//Processamento de informa��es.
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
    	  	printf("Essa op��o n�o est� dispon�vel\n");
    		system("pause");
    		break;
    	  }//Fim!
	
    }
}
