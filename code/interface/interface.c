#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include "../produto.h"
#include "../linked_list.h"

void interface()
{
  LP* new = NULL;
  int quantidade_produto;
  char* nome_produto = (char*)calloc(50,sizeof(char));
  char* origem = (char*)calloc(50,sizeof(char));
  char* key = (char*)calloc(9, sizeof(char));

  int i = 0;
  int escolha;
  bool control = true;
  const char* restrict __format = {"Selecione a opção desejada:\n"};
  const char* restrict input[] = {
    "+---------------------------------------------------+\n",
    "|  CONTROLE DE ESTOQUE ALI-IFB                      |\n",
    "|                                                   |\n",
    "| %d - Cadastrar novo alimento;                      |\n",
    "| %d - Atualizar informações de um produto;          |\n",
    "| %d - Vender produto;                               |\n",
    "| %d - Consultar informações de um produto;          |\n",
    "| %d - Consultar quantidade de todos os produtos;    |\n",
    "| %d - Finalizar programa;                           |\n",
    "+---------------------------------------------------+\n",
    "Insira o nome do produto:\n",
    "Insira o nome da origem do produto:\n",
    "Insira a quantidade do produto:\n",
    "Insira o código do produto:\n"
  };
  

  while(control)
  {
    for(i = 0; i < 10; i++)
    {
      printf(input[i], i - 2);
    }
    
    printf("%s", __format);
    scanf("%d", &escolha);

    if(escolha == 1)
    {
      printf("%s", input[10]);
      getchar();
      fgets(nome_produto, 50, stdin);
      nome_produto[strlen(nome_produto) - 1] = '\0';

      printf("%s", input[11]);
      getchar();
      fgets(origem, 50, stdin);
      origem[strlen(origem) - 1] = '\0';

      printf("%s",input[12]);
      scanf("%d", &quantidade_produto);

      if(new == NULL)
      {
        new = crear_list(nome_produto, origem, quantidade_produto);
      }
      else
      {
        inserir_lista_produto(&new, nome_produto, origem, quantidade_produto);
      }
    }
    else if(escolha == 2)
    {
      atualizar_lista(new);
    }
    else if(escolha == 3)
    {
      vender(new);
    }
    else if(escolha == 4)
    {
      printf("%s", input[13]);
      getchar();
      fgets(key, 50, stdin);
      key[strlen(key) - 1] = '\0';

      pesquisa_por_produto(new, key);
    }
    else if(escolha == 5)
    {
      print_lista_produto(new);
    }
    else if(escolha == 6)
    {
      exit(EXIT_SUCCESS);
    }
    else
    {
      printf("DADADA DA DA DA-DA-DA! DADADA DA DA DA-DA-DA! DADADA DA DA DA-DA-DA!\n");
    }
  }
}