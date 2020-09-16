#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "gerar_cod.h"

char* gerar_cod(char* abr_nome_pais, unsigned int cod)
{
  char* temp = (char*)calloc(3, sizeof(char));
  char* key = (char*)calloc(9,sizeof(char));

  if(cod < 10)
  {
    strncpy(temp,"00", 2);
  }
  else
  {
    if(cod < 100)
    {
      strncpy(temp,"0", 1);
    }
  }

  abr_nome_pais[strlen(abr_nome_pais) - 1] = '\0';

  sprintf(key,"%s%s%s%d",abr_nome_pais,"IFB",temp,cod);

  return key;
}