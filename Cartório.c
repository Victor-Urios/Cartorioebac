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
    
    printf("Gostaria de registrar mais pessoas?\n\n:");
    
    getchar();      //função para coletar a entrada de usuario > apenas caracteres < 
    
    char opcao; // criando variavel opção a partir de caracteres
    opcao = getchar();  // definindo quais opções estão disponiveis para a getchar, no caso s,S ou n,N
    
    if ( opcao == 's' || opcao == 'S') // aqui tanto faz se é um s minusculo ou maiúsculo
    {
        printf("Vamos lá para mais um registro!\n\n");
        registro();

	}
	
    else if (opcao == 'n' || opcao =='N') // ele vai funcionar com o if de cima
    {
    	printf("Volte ao menu principal.\n");
    	system("pause");
    	paineladm();
	}
		
	else // caso o cpf esteja invalido, este else vai para o primeiro if acima do remove
	{
		printf("\nOpção nao existente, volte ao menu por padrão!\n\n");
		system("pause");
		paineladm();
	}
    
    
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
    	
	}
    fclose(file);

    printf("\n\n\n\nGostaria de consultar mais pessoas?");
    getchar();      //função para coletar a entrada de usuario > apenas caracteres < 
    
    char opcao; // criando variavel opção a partir de caracteres
    opcao = getchar();  // definindo quais opções estão disponiveis para a getchar, no caso s,S ou n,N
    
    if ( opcao == 's' || opcao == 'S') // aqui tanto faz se é um s minusculo ou maiúsculo
    {
        printf("Vamos lá para mais uma consulta!\n\n");
        consulta();
	}
	
    else if (opcao == 'n' || opcao =='N') // ele vai funcionar com o if de cima
    {
    	printf("Volte ao menu principal.\n");
    	system("pause");
    	paineladm();
	}
		
	else // se colocar outra coisa alem de s ou n ele vai jogar pro menu principal direto.
	{
		printf("\nOpção nao existente, volte ao menu por padrão!\n\n");
		system("pause");
	    paineladm();
	}
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
    	printf(" Cpf deletado!\n\n\n ");
    	printf("\n\nGostaria de deletar mais pessoas?:");
    	getchar();
    	char opcao;
    	opcao = getchar();
    	if ( opcao == 's' || opcao == 'S')
    {
    	deletar();
	}
	else if (opcao == 'n' || opcao == 'N')
	{
		printf("Volte ao menu principal.\n");
		paineladm();
	}
	else
	{
		printf("Opção inexistente, volte ao menu por padrão");
		system("pause");
		paineladm();
	}
	}
}
    else if (opcao == 'n' || opcao =='N') // ele vai funcionar com o if de cima
    {
    	printf("Volte ao menu principal.\n");
    	system("pause");
    	paineladm();
	}
		
	else //se colocar outra coisa alem de s ou n ele vai jogar pro menu principal direto.
	{
		printf("\nCpf nao encontrado\n\n");
		system("pause");
		paineladm();
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
    setlocale(LC_ALL, "Portuguese");	
	char logindigitado[10]="a";
	char senhadigitada[10]="a";
	int login;
	int senha;
	
	system("cls");
	printf("> Cartório da EBAC <\n\n");
	printf("Digite o login administrativo:");
	scanf("%s", logindigitado);
	login = strcmp(logindigitado,  "admin");
	
    if(login == 0)
    {
	
	printf("> Cartório da EBAC <\n\n");
	printf("Login de Admin\n\nDigite a sua senha:");
	scanf("%s", senhadigitada);
	senha = strcmp(senhadigitada,  "admin");
	
	if(senha == 0) // If comparativo ou qualquer outro que vá encaixar um else > NÃO, VAI. PONTO E VIRGULA <  então sempre que for fazer um if else, nao ponha ponto e virgula no final do parenteses
	                    // assim o código não quebra, foi o meu erro em uma das aulas               
	{
	printf("\nSeja bem vindo administrador!\n\n");
	system("pause");
	paineladm();
	        
   }
      	else          // funciona com o if de comparação
		printf("\nSenha incorreta!\n\n");
		system("pause");
		main();
}
        else // teste
        printf("\nLogin não reconhecido, volte ao menu\n\n");
        system("pause");
        main();
}
int paineladm()
{
	int opcao=0; //definindo variáveis
	int laco=1;
	setlocale(LC_ALL, "Portuguese");
    	for(laco=1;laco=1;)
         { 
       
           system("cls");
	
    	    setlocale(LC_ALL, "Portuguese"); //Definição de Linguagem
 		
        	printf("> Cartório da EBAC <\n\n");  // menu
        	printf("Escolha a opção desejada pro menu:\n\n\n");
        	printf("\t1 - Registrar nome\n");
        	printf("\t2 - Consultar nome\n");
        	printf("\t3 - Deletar nomes\n");
        	printf("\t4 - Sair do programa\n");
        	printf("\t5 - Voltar ao menu de login?\n\n\n\n");
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
	    	    
	    	    case 5:
				printf("\nObrigado pelo serviço, adiministrador!\n");
				system("pause");
	    	    main();
	    	    break;
	    	    
	        	default:
	    	    printf("\nOpção indisponivel no momento\n");
	    	    system("pause");
	    	    break;
            
	    		}	
        } 
}



