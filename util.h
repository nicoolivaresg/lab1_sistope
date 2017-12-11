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

/**
 * Funcion que obtiene la cantidad de digitos que tiene un numero.
 *
 * Entrada:
 *	number - Numero entero del cual se le quiere contar los digitos.
 *
 * Salida: Cantidad de digitos que tiene number.
 */
int digits(int number);

/**
 * Funcion que transforma un numero entero a string.
 *
 * Entrada:
 *	number - Numero que se quiere convertir.
 *
 * Salida: String de number.
 */
char* intToString(int number);

/**
 * Funcion que obtiene el nombre que debiera tener un archivo
 * que entrega resultados parciales.
 *
 * Entradas:
 *	dna_chain		- Cadena que se busca en este archivo de 
 * 		resultados parciales.
 *	process_number	- Numero identificador del proceso que
 *		obtiene tales resultados parciales.
 *
 * Salida: String con el nombre del archivo de rp.
 */
char* getRpName(char* dna_chain, int process_number);

/**
 * Funcion que obtiene el nombre que debiera tener un archivo
 * que entrega resultados completos.
 *
 * Entradas:
 *	dna_chain		- Cadena que se busca en este archivo de 
 * 		resultados completos.
 *
 * Salida: String con el nombre del archivo de rc.
 */
char* getRcName(char* dna_chain);

#endif