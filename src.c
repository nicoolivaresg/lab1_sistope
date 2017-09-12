#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>


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
				numero_procesos_comparador = atoi(optarg);
				break;
			case 'c':
				cflag = 1;
				cantidad_caracteres_en_linea =atoi(optarg);
				break;
			case 'p':
				pflag = 1;
				cadena_a_buscar = malloc(strlen(optarg)+1);
				strcpy(cadena_a_buscar,optarg);
				break;
			case 'd':
				dflag = 1;
				break;
			/*	
			case 'b':
				nflag =1;
				sscanf(optarg,"%d",&bflag);
				fprintf(stderr, "%s\n", optarg);
				break;
			case 'c':
				cvalue = optarg;
				break;
			*/
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
	free(input_file);
	free(cadena_a_buscar);
	return 0;
}