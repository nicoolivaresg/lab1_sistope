/*
	HEADERS DE FUNCIONES PARA MANEJADOR DE PROCESOS
*/

#ifndef _PROCESS_HANDLER_H
#define _PROCESS_HANDLER_H

#include "util.h"
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

/**
 * Funcion que obtiene la cantidad de lineas que tiene un archivo
 * de cadenas de adn de acuerdo a la cantidad de caracteres que hay
 * en cada linea.
 *
 * Entrada:
 * 	archivo			- Archivo abierto con las cadenas de adn.
 * 	letras_en_linea	- Numero entero que dice cuantos caracteres hay
 *		en cada linea del archivo.
 *
 * Salida: Cantidad de lineas en el archivo, se usa para despues poder
 * 	calcular cuantas lineas deberia comparar cada proceso.
 */
int calcularLineas(FILE* archivo, int letras_en_linea);

/**
 * Funcion que obtiene la cantidad real de caracteres que contiene una linea de un archivo
 * de cadenas de adn
 *
 * Entrada:
 * 	archivo			- Archivo abierto con las cadenas de adn.
 *
 * Salida: Cantidad de caracteres reales en cada linea del archivo de cadenas de adn
 */
int calcularCaracteresRealesEnLinea(FILE* archivo);

/**
 * Funcion que crea un nuevo proceso comparador.
 *
 * Entradas:
 * 	identificador	- Numero que identifica al nuevo proceso.
 *	input_file		- Nombre del archivo de entrada que debe utilizar
 *		el nuevo proceso.
 *	offset			- Lugar en donde debe empezar a leer caracteres el
 *		nuevo proceso, se usa fseek para avanzar hasta offset.
 *	lineas_proceso	- Cuantas lineas se debe encargar de comparar el
 *		nuevo proceso (empezando desde offset).
 *	cadena_a_buscar - Cadena que debe comparar y buscar el nuevo proceso,
 *		dentro de las lineas que tiene bajo su cargo.
 *
 * Salida: ID del proceso creado.
 */
pid_t createProcess(int identificador, char* input_file, int offset, int lineas_proceso, char* cadena_a_buscar);

#endif