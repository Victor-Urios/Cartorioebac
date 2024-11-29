#include <stdio.h> //biblioteca de comunica��o com o usu�rio
#include <stdlib.h> //aloca��o de espa�os de memoria
#include <locale.h> //biblioteca de aloca��es de texto regional
#include <string.h> //biblioteca das strings strengz
// /t serve pra dar um espa�o mais pro lado direito do comando
// /n � pra dar um enter e jogar baixo 
//pra ficar espa�ado a de baixo com a de cima
// o /n tem que estar presente na de cima

int registro() 
{ 
    setlocale(LC_ALL, "Portuguese");
    //variaveis ex: char, string ex [40]
    char arquivo[200];
    char cpf[200];
    char nome[200];
    char sobrenome[200];
    char cargo[200];
    system("CLS");
    //fim da cria��o de variaveis

    
    printf("Digite o cpf para o registro: ");
    scanf("%s", cpf); // Coleta informa��o do usu�rio
    
    strcpy(arquivo, cpf); //ele copia o valor das strings por ex, o arquivo tera o mesmo nome dos caracteres escritos no CPF
    
    FILE *file; //cria o arquivo no banco de dados
    file = fopen(arquivo, "w"); // cria o arquivo o "w" significa esrever.
    fprintf(file,"CPF: "); //salvo o valor do cpf
    fprintf(file,cpf); // salvando o valor da variavel ( no caso o nome do arquivo � o mesmo do cpf )
    fclose(file); // fecha o arquivo
    
    file = fopen(arquivo, "a");
    fprintf(file,"\n");
    fclose(file);
    
    printf("Digite o nome a ser cadastrado: ");
    scanf("%s",nome);
    
    file = fopen(arquivo, "a");
    fprintf(file,"Nome: ");
    fprintf(file,nome);
    fclose(file);
    
    file = fopen(arquivo, "a");
    fprintf(file,"\n");
    fclose(file);
    
    printf("Digite o sobrenome a ser cadastrado: ");
    scanf("%s",sobrenome);
    
    file = fopen(arquivo, "a");
    fprintf(file,"Sobrenome: ");
    fprintf(file,sobrenome);
    fclose(file);
    
    file = fopen(arquivo, "a");
    fprintf(file,"\n");
    fclose(file);
    
    printf("Digite o cargo a ser cadastrado: ");
    scanf("%s",cargo);
    
    file = fopen(arquivo, "a");
	fprintf(file,"Cargo: ");
    fprintf(file,cargo);
    fclose(file);
    
    file = fopen(arquivo, "a");
    fprintf(file,"\n");
    fclose(file);
    
    printf("\n\nUsu�rio cadastrado com sucesso!\n\n");
    printf("Gostaria de registrar mais pessoas?\n\n:");
    
    getchar();      //fun��o para coletar a entrada de usuario > apenas caracteres < 
    char opcao; // criando variavel op��o a partir de caracteres
    opcao = getchar();  // definindo quais op��es est�o disponiveis para a getchar, no caso s,S ou n,N
    
    if ( opcao == 's' || opcao == 'S') // aqui tanto faz se � um s minusculo ou mai�sculo
    {
        printf("\nVamos l� para mais um registro!\n\n");
        system("pause");
        registro();

	}
	
    else if (opcao == 'n' || opcao =='N') // ele vai funcionar com o if de cima
    {
    	printf("Volte ao menu principal.\n");
    	system("pause");
    	paineladm();
	}
		
	else if (opcao == 0) // caso n�o escolha nenhuma
	{
		printf("\nOp��o nao existente, volte ao menu por padr�o!\n\n");
		system("pause");
		paineladm();
	}
	
	else // caso n�o escolha nenhuma
	{
		printf("\nOp��o nao existente, volte ao menu por padr�o!\n\n");
		system("pause");
		paineladm();
	}
    
    
}

int consulta() //fun��o de consultar, fclose no final � importantissimo.
{
	setlocale(LC_ALL, "Portuguese");
    char cpf[40];
    char conteudo[200];
    system("CLS");
    
    printf("Digite o cpf a ser consultado: "); // qual usuario esta sendo consultado
    scanf("%s",cpf);
    
    FILE *file;
    file = fopen(cpf,"r");
    
    if(file == NULL)
    {
    	printf("CPF N�o encontrado.\n\n");
    	system("pause");
    	consulta();
	}
    
    while(fgets(conteudo, 200, file) != NULL) //ele vai ficar rodando at� pegar todo conteudo, quando parar no null ele vai parar e � isso ai.
    {
    	printf("%s", conteudo);   	
	}
    fclose(file);
    system("pause");

    printf("\n\n\n\nGostaria de consultar mais pessoas?");
    getchar();      //fun��o para coletar a entrada de usuario > apenas caracteres < 
    
    char opcao; // criando variavel op��o a partir de caracteres
    opcao = getchar();  // definindo quais op��es est�o disponiveis para a getchar, no caso s,S ou n,N
    
    if ( opcao == 's' || opcao == 'S') // aqui tanto faz se � um s minusculo ou mai�sculo
    {
        printf("Vamos l� para mais uma consulta!\n\n");
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
		printf("\nOp��o nao existente, volte ao menu por padr�o!\n\n");
		system("pause");
	    paineladm();
	}
}
	

int deletar() //fun��o de deletar
{

    char cpf[40];
    system("CLS");
    printf("digite o cpf a ser deletado:");
    scanf("%s", cpf);
    
    FILE *file;
    file = fopen(cpf,"r");
    fclose(file);
    
    if (file == NULL) // Se o arquivo n�o existir:
    {
    	printf ("\n\nO cpf digitado nao foi encontrado\n");
    	system("pause");
	}
    
    printf(" Deseja deletar este CPF do sistema? ");
    printf("%s",cpf);
    printf("\nDigite s para deletar ou n para n�o\n\n");
    
    getchar();      //fun��o para coletar a entrada de usuario > apenas caracteres < 
    
    char opcao; // criando variavel op��o a partir de caracteres
    opcao = getchar();  // definindo quais op��es est�o disponiveis para a getchar, no caso s,S ou n,N
    
    if ( opcao == 's' || opcao == 'S') // aqui tanto faz se � um s minusculo ou mai�sculo
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
		system("pause");
		paineladm();
	}
	else
	{
		printf("Op��o inexistente, volte ao menu por padr�o");
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
int main()
    {
    setlocale(LC_ALL, "Portuguese");	
	char logindigitado[10]="a";
	char senhadigitada[10]="a";
	int login;
	int senha;
	
	system("cls");
	printf("> Cart�rio da EBAC <\n\n");
	printf("Digite o login administrativo:");
	scanf("%s", logindigitado);
	login = strcmp(logindigitado, "admin");
	
    if(login == 0)
    {
	
	printf("> Cart�rio da EBAC <\n\n");
	printf("Login de Admin\n\nDigite a sua senha:");
	scanf("%s", senhadigitada);
	senha = strcmp(senhadigitada, "admin");
	
	if(senha == 0) // If comparativo ou qualquer outro que v� encaixar um else > N�O, VAI. PONTO E VIRGULA <  ent�o sempre que for fazer um if else, nao ponha ponto e virgula no final do parenteses
	                    // assim o c�digo n�o quebra, foi o meu erro em uma das aulas               
	{
	printf("\nSeja bem vindo administrador!\n\n");
	system("pause");
	paineladm();
	        
   }
      	else          // funciona com o if de compara��o
		printf("\nSenha incorreta!\n\n");
		system("pause");
		main();
}
        else // caso nao digite admin ele te joga pra tela de login dnv
        printf("\nLogin n�o reconhecido, volte ao menu\n\n");
        system("pause");
        main();
}
int paineladm() //criei essa int exclusiva pro painel de adm, no main ele n funciona um looping bonitinho, agora com uma int separada ele tem um loop mais consiso, mt melhor que ficar colocando login e senha a cada segundo.
{
	int opcao=0; //definindo vari�veis
	setlocale(LC_ALL, "Portuguese");
         { 
       
            system("cls");
        	printf("> Cart�rio da EBAC <\n\n");  // menu
        	printf("Escolha a op��o desejada pro menu:\n\n\n");
        	printf("\t1 - Registrar nome\n");
        	printf("\t2 - Consultar nome\n");
        	printf("\t3 - Deletar nomes\n");
        	printf("\t4 - Voltar ao menu de login?\n");
           	printf("\t5 - Sair do programa\n\n\n\n");     	
        	printf("Op��o: "); //fim do menu
	
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
				printf("\nObrigado pelo servi�o, adiministrador!\n");
				system("pause");
	    	    main();
	        	break;
	    	    
	    	    case 5:
            	printf("\nObrigado por usar o cart�rio da ebac!\n\n");
            	system("pause");
             	exit(0);
	    	    break;
	    	    
	        	default:
	    	    printf("\nOp��o indisponivel no momento\n");
	    	    system("pause");
	    	    break;
            
	    		}	
        } 
}



