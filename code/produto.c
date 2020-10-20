#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>

#include "tratamento de dados/inteiro/inteiro.h"
#include "tratamento de dados/get_pais/get_pais.h"
#include "tratamento de dados/gerar_codigo/gerar_cod.h"
#include "produto.h"

struct produto
{
  char* key;
  int cod; 
  char* nome_produto;
  char* pais_produto;
  int qtd_items;
};

P* crear_produto(char* nome, char* local, int quantidade, int cod)
{
  int i = 0;

  bool country_check = check_country(local);

  P* new = (P*)malloc(sizeof(P));

  new->key = (char*)calloc(9, sizeof(char));
  new->nome_produto = (char*)calloc(50, sizeof(char));
  new->pais_produto = (char*)calloc(50, sizeof(char));
  
  new->qtd_items = quantidade;
  new->cod = cod;
  
  if(country_check == true)
  {
    strncpy(new->nome_produto, nome, strlen(nome));
    strncpy(new->pais_produto, local, strlen(local));

    strncpy(new->key, gerar_cod(get_abr(new->pais_produto), new->cod), strlen(gerar_cod(get_abr(new->pais_produto), new->cod)));
  }
  else
  {
    char* error[] = {
      ">> Error: problema em registra o produto",
      ">> Tente inserir um pais existente."
      };
    
    for(i = 0; i < 2; i++)
    {
      printf("%s\n", error[i]);
    }

		return NULL;
  }

  return new;
}

P* atualiza_produto(P* produto)
{
  int temp_chose;
  int temp_item;
  char* temp = (char*)calloc(50, sizeof(char));

  const char* restrict __format[] = {
    "Atualizar as informações de um produto:\n\n",
    "%-4d - Alterar o nome;\n",
    "%-4d - Alterar o País de origem;\n",
    "%-4d - Adcionar mais itens;\n",
		"Insira o código do produto:\n"
  };

  for(int i = 0; i < 4; i++)
  {
    printf(__format[i], i);
  }
  scanf("%d", &temp_chose);

	printf("%s", __format[4]);
  getchar();

  if(temp_chose == 1)
  {
    fgets(temp, 50, stdin);
    temp[strlen(temp) - 1] = '\0';

    atualiza_produto_nome(produto, temp);
  }
  else if(temp_chose == 2)
  {
    fgets(temp, 50, stdin);
    temp[strlen(temp) - 1] = '\0';

    atualiza_produto_origem(produto, temp);
  }
  else if(temp_chose == 3)
  {
    scanf("%u", &temp_item);

    atualiza_produto_quantidade(produto, temp_item);
  }
  else
  {
    printf("God help you now! \n");
  }

  return produto;
}

P* atualiza_produto_nome(P* produto, char* nome_produto)
{
  strcpy(produto->nome_produto, nome_produto);

  return produto;
}

P* atualiza_produto_quantidade(P* produto, int quantidade_produto)
{
  produto->qtd_items = produto->qtd_items + quantidade_produto;

  return produto;
}

P* atualiza_produto_origem(P* produto, char* origem_produto)
{
  if(check_country(origem_produto))
  {
    strcpy(produto->pais_produto, origem_produto);
    strncpy(produto->key, gerar_cod(get_abr(origem_produto), produto->cod), strlen(gerar_cod(get_abr(origem_produto), produto->cod)));

  }

  return produto;
}


bool confirma_pesquia_codigo(P* produto, char* key)
{
  return strcmp(produto->key, key) == 0 ? true : false;
}

void remover_produto(P* produto)
{
  free(produto);
}

P* vender_produto(P* produto)
{
  int sell_size = 0;

  printf("Insira a quantidade a ser vendida:\n");
  scanf("%d", &sell_size);
  
  if(check_int(sell_size, produto->qtd_items))
  {
    produto = atualiza_produto_quantidade(produto, (-1)*sell_size);

    if(produto->qtd_items == 0)
    {
      remover_produto(produto);
      return NULL;
    }
  }
  else
  {
    printf("Valor inválido, digite novamente\n");
    return vender_produto(produto);
  }

  return produto;
}

int count_name_iqual(P* now, char* nome_produto)
{
  if(now != NULL)
  {
    if(strstr(now->nome_produto, nome_produto) == NULL)
    {
      return 1;
    }
    else
    {
      return 0;
    }
  }
	
	return 1;
}

void print_quantidade_em_produto(P* produto)
{
  const char* restrict __format = {"%s %-4d \n"};

  printf(__format, produto->key, produto->qtd_items);
}

void print_produto(P* produto)
{
  const char* restrict __format[] = {
    "Código do produto: %s \n \n",
    "Nome do Produto: %s\n",
    "País de Origem: %s\n",
    "Quantidade de Itens: %d\n",
    "Código: %s\n"
  };

	if(produto != NULL)
	{
		printf(__format[0], produto->key);
		printf(__format[1], produto->nome_produto);
		printf(__format[2], produto->pais_produto);
		printf(__format[3], produto->qtd_items);
		printf(__format[4], produto->key);
	}
}