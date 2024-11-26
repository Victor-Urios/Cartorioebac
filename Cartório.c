#include <stdio.h> //biblioteca de comunicação com o usuário
#include <stdlib.h> //alocação de espaços de memoria
#include <locale.h> //biblioteca de alocações de texto regional
#include <string.h> //biblioteca das strings strengz
// /t serve pra dar um espaço mais pro lado direito do comando
// /n é pra dar um enter e jogar baixo 
//pra ficar espaçado a de baixo com a de cima
// o /n tem que estar presente na de cima

int registro() 
{ 
    //variaveis ex: char, string ex [40]
    char arquivo[40];
    char cpf[40];
    char nome[40];
    char sobrenome[40];
    char cargo[40];
    
    printf("Digite o cpf para o registro:");
    scanf("%s", cpf); // Coleta informação do usuário
    
    strcpy(arquivo, cpf); //ele copia o valor das strings por ex, o arquivo tera o mesmo nome dos caracteres escritos no CPF
    
    FILE *file; //cria o arquivo no banco de dados
    file = fopen(arquivo, "w"); // cria o arquivo
    fprintf(file,cpf); //salvo o valor do cpf
    fclose(file); // fecha o arquivo
    
    file = fopen(arquivo, "a");
    fprintf(file,"\n");
    fclose(file);
    
    printf("Digite o nome a ser cadastrado: ");
    scanf("%s",nome);
    
    file = fopen(arquivo, "a");
    fprintf(file,nome);
    fclose(file);
    
    file = fopen(arquivo, "a");
    fprintf(file,"\n");
    fclose(file);
    
    printf("Digite o sobrenome a ser cadastrado: ");
    scanf("%s",sobrenome);
    
    file = fopen(arquivo, "a");
    fprintf(file,sobrenome);
    fclose(file);
    
    file = fopen(arquivo, "a");
    fprintf(file,"\n");
    fclose(file);
    
    printf("Digite o cargo a ser cadastrado: ");
    scanf("%s",cargo);
    
    file = fopen(arquivo, "a");
    fprintf(file,cargo);
    fclose(file);
    
    system("pause");
    
}

int consulta() //função de consultar, fclose no final é importantissimo.
{
	setlocale(LC_ALL, "Portuguese");
    char cpf[40];
    char conteudo[200];
    
    printf("Digite o cpf a ser consultado: ");
    scanf("%s",cpf);
    
    FILE *file;
    file = fopen(cpf,"r");
    
    if(file == NULL)
    {
    	printf("CPF Não encontrado.\n\n");
	}
    
    while(fgets(conteudo, 200, file) != NULL) //ele vai ficar rodando até pegar todo conteudo, quando parar no null ele vai parar e é isso ai.
    {
    	printf("Essas são as informações do usuário: ");
    	printf("%s", conteudo);
    	printf("\n\n");
	}
    fclose(file);
    system("pause");

	
}

int deletar() //função de deletar
{

    char cpf[40];
    printf("digite o cpf a ser deletado:");
    scanf("%s", cpf);
    
    FILE *file;
    file = fopen(cpf,"r");
    fclose(file);
    
    if (file == NULL) // Se o arquivo não existir:
    {
    	printf ("\n\nO cpf digitado nao foi encontrado\n");
    	system("pause");
	}
    
    printf(" Deseja deletar este CPF do sistema? ");
    printf("%s",cpf);
    printf("\nDigite s para deletar ou n para não\n\n");
    
    getchar();      //função para coletar a entrada de usuario > apenas caracteres < 
    
    char opcao; // criando variavel opção a partir de caracteres
    opcao = getchar();  // definindo quais opções estão disponiveis para a getchar, no caso s,S ou n,N
    
    if ( opcao == 's' || opcao == 'S') // aqui tanto faz se é um s minusculo ou maiúsculo
    {
    if (remove(cpf) == 0) // se ele digitou S o programa vai remover o arquivo
    {
    	printf(" Cpf deletado! ");
	}
	    system("pause");
	}
	
    else if (opcao == 'n' || opcao =='N') // ele vai funcionar com o if de cima
    {
    	printf("Volte ao menu principal.\n");
    	system("pause");
	}
		
	else // caso o cpf esteja invalido, este else vai para o primeiro if acima do remove
	{
		printf("\nCpf nao encontrado\n\n");
		system("pause");
	}
}
int fechar()
{
	printf("\nObrigado por usar o cartório da ebac!\n\n");
	system("pause");
	exit(0);
}
int main()
    {
	int opcao=0; //definindo variáveis
	int laco=1;
	
	for(laco=1;laco=1;)
    { 
       
       system("cls");
	
	    setlocale(LC_ALL, "Portuguese"); //Definição de Linguagem
		
    	printf("> Cartório da EBAC <\n\n");  // menu
    	printf("Escolha a opção desejada pro menu:\n\n\n");
    	printf("\t1 - Registrar nome\n");
    	printf("\t2 - Consultar nome\n");
    	printf("\t3 - Deletar nomes\n");
    	printf("\t4 - Sair do programa\n\n\n\n");
    	printf("Opção: "); //fim do menu
	
    	scanf("%d", &opcao); //Armazenamento da escolha do usuario
	
    	system("cls");
	    
	    switch(opcao) //codigo fica mais limpo e mais leve
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
	    	
	    	case 4:
	    	fechar();
	    	break;
	    	
	    	default:
		    printf("Opção indisponivel no momento\n");
		    system("pause");
		    break;
            
			}	
}
}

