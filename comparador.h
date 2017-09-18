/*
	HEADERS DE FUNCIONES PARA COMPARADOR
*/
#ifndef _COMPARADOR_H
#define _COMPARADOR_H

#include "util.h"
#include <unistd.h>

int checkLine(FILE* input_file, char* dna_chain);

void writeResults(int* results, char* output_file_name, FILE* input_file, int offset, int lines);

#endif