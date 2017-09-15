/*
	HEADERS DE FUNCIONES PARA MANEJADOR DE PROCESOS
*/

#ifndef _PROCESS_HANDLER_H
#define _PROCESS_HANDLER_H

#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <math.h>

int calcularLineas(FILE* archivo, int letras_en_linea);

pid_t createProcess(int identificador, char* input_file, int offset, int lineas_proceso, char* cadena_a_buscar);

char* int_to_string(int number);

#endif