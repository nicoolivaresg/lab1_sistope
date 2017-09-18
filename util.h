/*
	HEADERS DE FUNCIONES DE UTILIDAD
	Son funciones que son utilizadas por ambos procesos.
*/
#ifndef _UTIL_H
#define _UTIL_H

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include <math.h>

int digits(int number);

char* intToString(int number);

char* getRpName(char* dna_chain, int processNumber);

char* getRcName(char* dna_chain);

#endif