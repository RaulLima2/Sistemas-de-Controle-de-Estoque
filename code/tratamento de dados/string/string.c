#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <ctype.h>
#include "string.h"

bool check_string(char* string)
{
  int i = 0;

  for( i = 0; i < strlen(string); i++)
  {
    if(!isalpha(string[i]))
    {
      return false;
    }
  }

  return true;
}

bool check_string_e_igual(char* string, char* string_compair)
{
  return strncmp(string, string_compair, strlen(string_compair)) == 0 ? true : false;
}