#include "comparador.h"


int main(int argc, char * argv[]){
	int identificador = 0, offset = 0, lineas = 0;
	char* input_file = NULL;
	char* cadena_a_buscar = NULL;

	int c;
	opterr=0;
	while((c = getopt(argc,argv,"d:i:o:l:p:")) != -1){
		switch(c){
			case 'd':
				sscanf(optarg, "%d", &identificador);
				break;
			case 'i':
				input_file = malloc(strlen(optarg)+1);
				strcpy(input_file,optarg);
				break;
			case 'o':
				sscanf(optarg, "%d", &offset);
				break;
			case 'l':
				sscanf(optarg, "%d", &lineas);
				break;
			case 'p':
				cadena_a_buscar = malloc(strlen(optarg)+1);
				strcpy(cadena_a_buscar,optarg);
				break;
			case '?':
				if(optopt == 'd'){
					fprintf(stderr, "Opcion -%c requiere un argumento.\n", optopt);
				} else if(optopt == 'i'){
					fprintf(stderr, "Opcion -%c requiere un argumento.\n", optopt);
				} else if(optopt == 'o'){
					fprintf(stderr, "Opcion -%c requiere un argumento.\n", optopt);
				} else if(optopt == 'l'){
					fprintf(stderr, "Opcion -%c requiere un argumento.\n", optopt);
				} else if(optopt == 'p'){
					fprintf(stderr, "Opcion -%c requiere un argumento.\n", optopt);
				} else if(isprint(optopt)){
					fprintf(stderr, "Opcion desconocida '-%c'.\n", optopt);
				} else{
					fprintf(stderr, "Opcion con caracter desconocido '\\x%x'.\n", optopt);
				}
				return 1;
			default:
				abort();
		}
	}
	printf("Identificador: %d\nArchivo de entrada: %s\nOffset: %d\nLineas ha comparar: %d\nCadena ha comparar: %s\n", 
		identificador,
		input_file,
		offset,
		lineas,
		cadena_a_buscar
		);

	printf("%s\n",procesar_archivo("AAAA")?"SI":"NO");

	return 0;
}


