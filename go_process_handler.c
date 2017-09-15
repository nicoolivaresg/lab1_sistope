#include "process_handler.h"
#include <math.h>


int main(int  argc, char ** argv){
	int iflag = 0;//Flag nombre de archivo de entrada
	int nflag = 0;//Flag numero procesos de comparardor
	int cflag = 0;//Flag cantidad de caracteres en una linea del archivo
	int pflag = 0;//Flag cadena a buscar
	int dflag = 0;//Flag mostrar resultados por pantalla
	char * input_file = NULL;
	int numero_procesos_comparador = 0;
	int cantidad_caracteres_en_linea = 0;
	char * cadena_a_buscar = NULL;
	int c;
	opterr=0;
	while((c = getopt(argc,argv,"i:n:c:p:d")) != -1){
		switch(c){
			case 'i':
				iflag = 1;
				input_file = malloc(strlen(optarg)+1);
				strcpy(input_file,optarg);
				break;
			case 'n':
				nflag = 1;
				sscanf(optarg, "%d", &numero_procesos_comparador);
				//numero_procesos_comparador = atoi(optarg);
				break;
			case 'c':
				cflag = 1;
				sscanf(optarg, "%d", &cantidad_caracteres_en_linea);
				//cantidad_caracteres_en_linea =atoi(optarg);
				break;
			case 'p':
				pflag = 1;
				cadena_a_buscar = malloc(strlen(optarg)+1);
				strcpy(cadena_a_buscar,optarg);
				break;
			case 'd':
				dflag = 1;
				break;
			case '?':
				if(optopt == 'i'){
					fprintf(stderr, "Opcion -%c requiere un argumento.\n", optopt);
				}else if(optopt == 'n'){
					fprintf(stderr, "Opcion -%c requiere un argumento.\n", optopt);
				}else if(optopt == 'c'){
					fprintf(stderr, "Opcion -%c requiere un argumento.\n", optopt);
				}else if(optopt == 'p'){
					fprintf(stderr, "Opcion -%c requiere un argumento.\n", optopt);
				}else if(isprint(optopt)){
					fprintf(stderr, "Opcion desconocida '-%c'.\n", optopt);
				}else{
					fprintf(stderr, "Opcion con caracter desconocido '\\x%x'.\n", optopt);
				}
				return 1;
			default:
				abort();
		}
	}
	/*
		Prueba de paso de argumentos por línea de comandos
	*/
	printf("iflag = %d, nflag = %d, cflag = %d, pflag = %d, dflag = %d\n", iflag, nflag, cflag, pflag, dflag);
	printf("Archivo de entrada: %s\nNumero de procesos ha crear: %d\nCantidad de caracteres por linea: %d\nCadena ha comparar: %s\nImprime por pantalla: %s\n", 
		input_file,
		numero_procesos_comparador,
		cantidad_caracteres_en_linea,
		cadena_a_buscar,
		dflag ? "Si":"No"
		);
	/* 
		Hasta acá 
	*/
	/*
		Procesamiento
	*/
	FILE* archivo = fopen(input_file, "r");
	if(archivo == NULL) {
		printf("El archivo %s no existe, ejecute el programa con un archivo existente\n", input_file);
	}
	char ch;
	int i;
	int lineas_totales, lineas_por_proceso, lineas_restantes, posicion_cursor = 0;
	lineas_totales = calcularLineas(archivo, cantidad_caracteres_en_linea);
	lineas_por_proceso = (int)ceil((float)lineas_totales / numero_procesos_comparador);
	lineas_restantes = lineas_totales;

	fseek(archivo, 0, SEEK_SET);
	for (int i = 0; i < numero_procesos_comparador; ++i)
	{
		int lineas_proceso = lineas_por_proceso;
		if(lineas_restantes - lineas_proceso < 0) {
			lineas_proceso = lineas_restantes;
		}

		createProcess(i+1, input_file, posicion_cursor, lineas_proceso, cadena_a_buscar);

		lineas_restantes -= lineas_proceso;
		printf("%d\n", lineas_restantes);
		if(lineas_restantes == 0) {
			break;
		}

		// obtener la siguiente posicion del cursor en el archivo.
		int lineas_aux = 0;
		while((ch = (char)getc(archivo)) != EOF) {
			if(ch == '\n') {
				lineas_aux++;
			}
			if(lineas_aux == lineas_proceso) {
				break;
			}
		}
		posicion_cursor = ftell(archivo);
	}

	/*
		Escribir resultados en un archivo.
	*/




	free(input_file);
	free(cadena_a_buscar);
	return 0;
}

