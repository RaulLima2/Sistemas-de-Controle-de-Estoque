#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "produto.h"
#include "linked_list.h"
#include "tratamento de dados/word/word.h"
#include "tratamento de dados/inteiro/inteiro.h"

struct list
{
  int codigo;
  P*    info;
  LP*   after;
  LP*   before;
};

LP* crear_list(char* nome_do_produto, char* local_do_produto, int quantidade_do_produto)
{
  LP* new = (LP*)malloc(sizeof(LP));
  
  if(new == NULL)
  {
    printf("Error: Não Allocado \n");
    exit(EXIT_FAILURE);
  }

  if(check_string(nome_do_produto))
  {
    new->codigo = 0;
    new->info = crear_produto(nome_do_produto, local_do_produto, quantidade_do_produto, 0);
    new->after = NULL;
    new->before = NULL;
  }
  else
  {
    printf("Insira um nome de prduto válido\n");
    exit(EXIT_FAILURE);
  }

  return new;
}

void inserir_lista_produto(LP** lista_produto, char* nome_do_produto, char* local_do_produto, int quantidade_do_produto)
{
  LP* new = (LP*)malloc(sizeof(LP));

  bool check = ((!check_codigo((*lista_produto)->codigo)) || (!check_string(nome_do_produto))); 
  
  if(new == NULL)
  {
    printf("Error: Não Allocado \n");
    exit(EXIT_FAILURE);
  }

  if(check)
  {
    printf("Error: códio inválido ou nome do produto inválido\n");
    exit(EXIT_FAILURE);
  }

  if(count_name(*lista_produto) == 20)
  {
    printf("Não é possível adicionar mais produtos no estoque\n");
    return;
  }
  


  new->codigo = (*lista_produto)->codigo + 1;

  new->info = crear_produto(nome_do_produto, local_do_produto, quantidade_do_produto, new->codigo);
  new->after = *lista_produto;
  new->before = NULL;

  if((*lista_produto) != NULL)
  {
    (*lista_produto)->before = new;
  }

  *lista_produto = new;
}

LP* atualizar_lista(LP* lista_produto)
{
  lista_produto->info = atualiza_produto(lista_produto->info);

  return lista_produto;
}


LP* vender(LP* lista_produto)
{
  LP* i;
  P* temp;
  char* codigo_produto = (char*)calloc(50,sizeof(char));

  printf("Insira o código a ser procurado:\n");
  fgets(codigo_produto, 50, stdin);
  codigo_produto[strlen(codigo_produto) - 1] = '\0';

  i = busca(lista_produto, codigo_produto);

  if(i == NULL)
  {
    printf("“Código inválido! \n");
  }
  else
  {
    temp = vender_produto(i->info);
  }

  if(temp == NULL)
  {
    remove_produto(i);
  }

  return lista_produto;
}

int count_name(LP* lista_produto)
{
  int sum = 0;
  int comparar_n_nome_de_produtos = 0;
  LP* i = lista_produto;

  for( i = lista_produto; i != NULL; i = i->after)
  {
    if(comparar_n_nome_de_produtos < 20)
    {
      sum += count_name_iqual(i->info, i->after->info);
    }

    comparar_n_nome_de_produtos++;
  }

  return sum;
}

LP* remove_produto(LP* lista_produto)
{
  LP* i = lista_produto;

  if(i == NULL)
  {
    return lista_produto;
  }

  if(i->before == NULL)
  {
    lista_produto = i->after;
  }
  else
  {
    i->before->after = i->after;
  }

  free(i);

  return lista_produto;
}

void pesquisa_por_produto(LP* lista_produto, char* key)
{
  LP* i = busca(lista_produto, key);

  if(i == NULL)
  {
    printf("“Código inválido! \n");
  }
  else
  {
    print_produto(i->info);
  }
}

void print_lista_produto(LP* lista_produto)
{
  LP* i = lista_produto;

  for(i = lista_produto; i != NULL; i = i->after)
  {
    print_quantidade_em_produto(i->info);
  }
}

LP* busca(LP* lista_produto, char* key)
{
  LP* i = lista_produto;

  for(i = lista_produto; i != NULL; i = i->after)
  {
    if(confirma_pesquia_codigo(i->info, key))
    {
      return i;
    }
  }

  return NULL;
}