/*
	IMPLEMENTACION DE FUNCIONES PARA EL MANEJADOR DE PROCESOS (process_handler.h)
*/
#include "process_handler.h"

int calcularLineas(FILE* archivo, int letras_en_linea)
{
	long int caracteres = 0;
	char letter = 0;
	fseek(archivo, 0, SEEK_SET);
	while(fscanf(archivo, "%c", &letter) == 1) {
		if(letter != '\n') {
			caracteres++;
		}
	}

	fseek(archivo, 0, SEEK_SET);
	return (int)(caracteres / letras_en_linea);
}

int calcularCaracteresRealesEnLinea(FILE* archivo)
{
	long int caracteres = 0;
	char letter = 0;
	fseek(archivo, 0, SEEK_SET);
	while(fscanf(archivo, "%c", &letter) == 1) {
		if(letter != '\n') {
			caracteres++;
		}else{
			fseek(archivo, 0, SEEK_SET);
			return (int)caracteres;
		}
	}

	fseek(archivo, 0, SEEK_SET);
	return (int)caracteres;
}

pid_t createProcess(int identificador, char* input_file, int offset, int lineas_proceso, char* cadena_a_buscar)
{
	pid_t pid = fork();
	if(pid == -1) {
		fprintf(stderr, "Fallo de fork().\n");
		exit(-1);
	} else if(pid > 0) {
		return pid;
	} else {
		char* _identificador = intToString(identificador);
		char* _offset = intToString(offset);
		char* _lineas_proceso = intToString(lineas_proceso);

		execlp("./comparador", "comparador", "-d", _identificador, "-i", input_file, "-o", _offset,
				"-l", _lineas_proceso, "-p", cadena_a_buscar, (char *)NULL);
		fprintf(stderr, "Fallo de execl().\n");
		exit(-1);
	}
}

