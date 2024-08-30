#include <stdio.h> //biblioteca de comunicação com o usuário
#include <stdlib.h> //biblioteca de alocação de espaço em memória
#include <locale.h> //biblioteca de alocações de texto por região
#include <string.h> //biblioteca responsável por cuidar das strings 


int registro()
{
  char arquivo[40];
  char cpf[40];
  char nome[40];
  char sobrenome[40];
  char cargo[40];
  

  printf("Digite o CPF a ser cadastrado: ");
  scanf("%s", cpf);
  
  strcpy(arquivo, cpf); //Responsavel por copiar os valores das strings 

  FILE *file; // cria o arquivo 
  file = fopen(arquivo, "w"); // cria o arquivo 
  fprintf(file,cpf); // salva o valor da variavel
  fclose(file); // fecha o arquivo 
  
  file = fopen(arquivo, "a");
  fprintf(file, ",");
  fclose(file);
  
  
  printf("Digite o nome a ser cadastrado: ");
  scanf("%s", nome);
  
  file = fopen(arquivo, "a");
  fprintf(file,nome);
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

  printf("Digite o cargo a ser castrado: ");
  scanf("%s", cargo);
   
  file = fopen(arquivo, "a");
  fprintf(file,cargo);
  fclose(file);

  getchar();
  
  

}
int consultar()
{
   setlocale(LC_ALL, "Portuguese"); //Definindo a linguagem 
   char cpf[40];
   char conteudo[200];

   printf("Digite o CPF aser consultado: ");
   scanf("%s",cpf);
   getchar();

   FILE *file;
   file = fopen(cpf, "r");

   if(file == NULL)
   {
     printf("Não foi possível abrir o arquivo, não localizado! .\n");
   }
    
    while(fgets(conteudo,200, file) != NULL)
    {
        printf("\nEssas são as informações do usuário: ");
        printf("%s", conteudo);
        printf("\n\n");

    }
    
    getchar();
}
int deletar()
{
   char cpf[40];
   printf("Digite o CPF do usuário a ser deletado: ");
   scanf("%s",cpf);
   getchar();

   remove(cpf);

   FILE *file;
   file = fopen(cpf, "r");

   if(file == NULL)
   {
     printf("O usúario não se encontra no sistema!. \n");
     getchar();
   }
}


int main ()
    {

    int opcao=0; //Definindo as variáveis 
    int laco=1;
    

    for(laco=1;laco=1;)
    {

        system("clear");

        setlocale(LC_ALL, "Portuguese"); //Definindo a linguagem 

        printf("###Cartório da EBAC ###\n\n"); //Início do menu
        printf("Escolha a opção desejada do menu:\n\n");
        printf("\t1 - Registrar nomes\n");
        printf("\t2 - Consultar nomes\n");
        printf("\t3 - Deletar nomes\n"); 
        printf("Opção:"); //Fim do menu 

        scanf("%d", &opcao);
        getchar();

        system("clear");

        

        switch(opcao)
        {
            case 1:
            registro();
            break;

            case 2:
            consultar();
            break;

            case 3:
            deletar();
            break;

            default:
            printf("Essa opção não está disponivel!\n");
            getchar();
            break;
        


        }

       
    
        
    }
}
