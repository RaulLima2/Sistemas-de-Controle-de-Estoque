#ifndef GET_PAIS_H
#define GET_PAIS_H

#include <stdbool.h>

int get_line_country(char* nome_do_pais);

bool check_country(char* name_country);

char* get_abr(char* nome_do_pais);

#endif