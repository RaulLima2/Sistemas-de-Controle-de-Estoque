#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#include <stdbool.h>
#include "get_pais.h"

int get_line_country(char* nome_do_pais)
{
  int line_found = 1;
  FILE *lista_de_paises;
  char* pais = (char*)calloc(255,sizeof(char));
  
  lista_de_paises = fopen("code/tratamento de dados/get_pais/lista_de_paises.txt", "r+");

  if(lista_de_paises == NULL)
  {
    printf("Not allocated");
  }

  while(fgets(pais, 255, lista_de_paises) != NULL)
  {
		pais[strlen(pais) - 1] = '\0';

    if(strstr(pais, nome_do_pais) != NULL)
    {
      return  line_found;
    }

    line_found++;
  }

  fclose(lista_de_paises);
  free(pais);

  return 0;
}

bool check_country(char* name_country)
{
  int i = 0;

  for(i = 0; i < strlen(name_country) - 1; i ++)
  {
    if(!isalpha(name_country[i]))
    {
			if(!isblank(name_country[i]))
			{
      	return false;
			}
    }

  }

  if(get_line_country(name_country) != 0)
  {
    return true;
  }
  else
  {
    return false;
  }
}

char* get_abr(char* nome_do_pais)
{
  FILE* abr_pais;
  char* pais = (char*)calloc(255,sizeof(char));
  int line_found = get_line_country(nome_do_pais);

  abr_pais = fopen("code/tratamento de dados/get_pais/abr_pais.txt", "r+");

  if(abr_pais == NULL)
  {
    printf("Not allocated ");
  }

  while(fgets(pais,sizeof(pais), abr_pais) != NULL)
  {
    if(line_found == 1)
    {
      return pais;
    }

    line_found--;
  }

  fclose(abr_pais);

  return "\0";
}