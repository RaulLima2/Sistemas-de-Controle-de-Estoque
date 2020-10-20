#ifndef PRODUTO_H
#define PRODUTO_H

#include <stdbool.h>

typedef struct produto P;

P* crear_produto(char* nome, char* local, int quantidade, int cod);

P* atualiza_produto(P* produto);

P* atualiza_produto_nome(P* produto, char* nome_produto);

P* atualiza_produto_quantidade(P* produto, int quantidade_produto);

P* atualiza_produto_origem(P* produto, char* origem_produto);

bool confirma_pesquia_codigo(P* produto, char* key);

P* vender_produto(P* produto);

int count_name_iqual(P* now, char* nome_produto);

void remover_produto(P* produto);

void print_quantidade_em_produto(P* produto);

void print_produto(P* produto);

#endif