/*
	HEADERS DE FUNCIONES PARA COMPARADOR
*/
#ifndef _COMPARADOR_H
#define _COMPARADOR_H

#include "util.h"
#include <unistd.h>

/**
 * Funcion que revisa (comparando) si es que la string dna_chain
 * se encuentra en la linea en la que se encuetra el archivo.
 *
 * Entradas:
 * 	input_file 	- Puntero a FILE que se encuentra al comienzo de
 * 		alguna linea del archivo de entrada.
 *	dna_chain	- Puntero a una string que posee la cadena de adn
 *		que se quiere encontrar en la linea actual en el archivo.
 *
 * Salida: Retorna 1 en caso de que se encuentra la cadena dna_chain
 *	y 0 en el caso contrario.
 */
int checkLine(FILE* input_file, char* dna_chain);

/**
 * Metodo que escribe los resultados obtenidos al revisar todas
 * las lineas que le corresponde a un proceso en el archivo de
 * resultados parciales.
 *
 * Entradas:
 *	results				- Arreglo de enteros que determinan si es
 *		que se encuentra la cadena que se buscaba en cada línea.
 *	output_file_name	- Nombre del archivo de resultdos parciales,
 *		se obtiene utilizando la funcion getRpName().
 *	input_file			- Archivo de entrada, se utiliza para copiar
 *		los caracteres dentro del archivo de resultados parciales.
 *	offset				- Lugar en donde debe empezar a leer caracteres
 *		del archivo de entrada, se usa fseek para avanzar hasta offset.
 *	lines 				- Cantidad de lineas que las que estuvo encargado
 *		de comparar este proceso.
 */
void writeResults(int* results, char* output_file_name, FILE* input_file, int offset, int lines);

#endif