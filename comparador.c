#include "comparador.h"
/*
	IMPLEMENTACIÓN DE FUNCIONES COMPARADOR (comparador.h)
*/

int checkLine(FILE* input_file, char* dna_chain)
{
	char ch;
	int length = strlen(dna_chain);
	int result = 0;
	char* read_string = (char*)malloc(length + 1);
	int chars_read = 0;
	while((ch = (char)getc(input_file)) != EOF) {
		if(ch == '\n') {
			break;
		} else {
			read_string[chars_read % length] = ch;
			chars_read++;
			for (int i = 0; i < length; ++i)
			{
				if(dna_chain[i] != read_string[(chars_read + i) % length]) {
					break;
				}
				// Todas las comparaciones retornan verdadero
				if(i == length - 1) {
					result = 1;
				}
			}
		}
	}

	free(read_string);
	return result;
}

void writeResults(int* results, char* output_file_name, FILE* input_file, int offset, int lines)
{
	FILE* output_file = fopen(output_file_name, "w");
	fseek(input_file, offset, SEEK_SET);
	char ch;
	int currLine = 0;
	while(currLine < lines) {
		if((ch = (char)getc(input_file)) == EOF || ch == '\n') {
			fprintf(output_file, "\t");
			if(results[currLine] == 1) {
				fprintf(output_file, "SI");
			} else if(results[currLine] == 0) {
				fprintf(output_file, "NO");
			}
			fprintf(output_file, "\n");
			currLine++;
		} else {
			fprintf(output_file, "%c", ch);
		}
	}
}