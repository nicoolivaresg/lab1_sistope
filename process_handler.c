#include "process_handler.h"

/*
	IMPLEMENTACION DE FUNCIONES PARA EL MANEJADOR DE PROCESOS (process_handler.h)
*/
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

	return (int)(caracteres / letras_en_linea);
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
		char* _identificador = int_to_string(identificador);
		char* _offset = int_to_string(offset);
		char* _lineas_proceso = int_to_string(lineas_proceso);

		execlp("./comparador", "comparador", "-d", _identificador, "-i", input_file, "-o", _offset,
				"-l", _lineas_proceso, "-p", cadena_a_buscar, (char *)NULL);
		fprintf(stderr, "Fallo de execl().\n");
		exit(-1);
	}
}

char* int_to_string(int number)
{
	int digits = 1;
	int temp_number = number;
	while(temp_number >= 10) {
		temp_number /= 10;
		digits++;
	}

	char* str = (char*)malloc(digits+1);
	snprintf(str, digits+1, "%d", number);

	return str;
}