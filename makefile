CC=gcc
route=

all: go_process_handler.o process_handler.o go_comparador.o comparador.o util.o
	@$(CC) go_process_handler.o process_handler.o util.o -o handler -Wall -lm -I.
	@$(CC) go_comparador.o comparador.o util.o -o comparador -Wall -lm -I.
	@rm go_process_handler.o process_handler.o go_comparador.o comparador.o util.o
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

util.o:	$(route)util.c
	@$(CC) -c $(route)util.c