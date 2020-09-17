OBJS	= word.o inteiro.o get_pais.o gerar_cod.o produto.o linked_list.o interface.o main.o
SOURCE	= code/tratamento\ de\ dados/word/word.c code/tratamento\ de\ dados/inteiro/inteiro.c code/tratamento\ de\ dados/get_pais/get_pais.c code/tratamento\ de\ dados/gerar_codigo/gerar_cod.c code/produto.c code/linked_list.c code/interface/interface.c main.c
HEADER	= 
OUT	= main
CC	 = gcc
FLAGS	 = -g3 -c -Wall
LFLAGS	 = 

all: $(OBJS)
	$(CC) -g $(OBJS) -o $(OUT) $(LFLAGS)

main: $(OBJS)
	$(CC) -g $(OBJS) -o $(OUT)

word.o: code/tratamento\ de\ dados/word/word.c
	$(CC) $(FLAGS) code/tratamento\ de\ dados/word/word.c -std=c99

inteiro.o: code/tratamento\ de\ dados/inteiro/inteiro.c
	$(CC) $(FLAGS) code/tratamento\ de\ dados/inteiro/inteiro.c -std=c99

get_pais.o: code/tratamento\ de\ dados/get_pais/get_pais.c
	$(CC) $(FLAGS) code/tratamento\ de\ dados/get_pais/get_pais.c -std=c99

gerar_cod.o: code/tratamento\ de\ dados/gerar_codigo/gerar_cod.c
	$(CC) $(FLAGS) code/tratamento\ de\ dados/gerar_codigo/gerar_cod.c -std=c99

produto.o: code/produto.c
	$(CC) $(FLAGS) code/produto.c -std=c99

linked_list.o: code/linked_list.c
	$(CC) $(FLAGS) code/linked_list.c -std=c99

interface.o: code/interface/interface.c
	$(CC) $(FLAGS) code/interface/interface.c -std=c99

main.o: main.c
	$(CC) $(FLAGS) main.c -std=c99

clean:
	rm -f $(OBJS) $(OUT)

run: $(OUT)
	./$(OUT)

debug: $(OUT)
	valgrind $(OUT)

valgrind: $(OUT)
	valgrind $(OUT)

valgrind_leakcheck: $(OUT)
	valgrind --leak-check=full $(OUT)

valgrind_extreme: $(OUT)
	valgrind --leak-check=full --show-leak-kinds=all --leak-resolution=high --track-origins=yes --vgdb=yes $(OUT)