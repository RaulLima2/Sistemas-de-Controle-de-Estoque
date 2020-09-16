#ifndef LINKED_LIST_H
#define LINKED_LIST_H

typedef struct list LP;

LP* crear_list(char* nome_do_produto, char* local_do_produto, int quantidade_do_produto);

void inserir_lista_produto(LP** lista_produto, char* nome_do_produto, char* local_do_produto, int quantidade_do_produto);

LP* atualizar_lista(LP* lista_produto);

LP* vender(LP* lista_produto);

LP* remove_produto(LP* lista_produto);

void pesquisa_por_produto(LP* lista_produto, char* key);

void print_lista_produto(LP* lista_produto);

LP* busca(LP* lista_produto, char* key);

#endif