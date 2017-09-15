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