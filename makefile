CC=gcc
route=

all: go_process_handler.o process_handler.o go_comparador.o comparador.o
	@$(CC) go_process_handler.o process_handler.o -o handler -Wall -lm -I.
	@$(CC) go_comparador.o comparador.o -o comparador -Wall -lm -I.
	@rm go_process_handler.o process_handler.o go_comparador.o comparador.o
	@clear
	@echo "Compilación terminada"

go_process_handler.o: $(route)go_process_handler.c
	@$(CC) -c $(route)go_process_handler.c

process_handler.o: $(route)process_handler.c
	@$(CC) -c $(route)process_handler.c

go_comparador.o: $(route)go_comparador.c
	@$(CC) -c $(route)go_comparador.c

comparador.o: $(route)comparador.c
	@$(CC) -c $(route)comparador.c