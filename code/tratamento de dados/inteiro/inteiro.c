#include <stdio.h>
#include <stdbool.h>
#include "inteiro.h"

bool check_codigo(int number)
{
  return (number >= 0 && number <= 999) ? true : false;
}

bool check_int(int number, int number_compair)
{
   return (number >= 0 && number <= number_compair) ? true : false;
}