#include <time.h>
#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

const char ADN[] = {'A', 'C', 'G', 'T'};

int main(int argc, char ** argv)
{
	srand(time(NULL));
	int lines, lineLength, c;
	char* outputFile = NULL;
	opterr = 0;
	while( (c = getopt (argc, argv, "o:l:n:")) != -1 ) {
		switch(c) {
			case 'o':
				outputFile = (char*)malloc(strlen(optarg)+1);
				strcpy(outputFile,optarg);
				break;
			case 'l': 
				sscanf(optarg, "%d", &lines);
				break;
			case 'n':
				sscanf(optarg, "%d", &lineLength);
				break;
			case '?':
				if (optopt == 'o') {
					fprintf(stderr, "Opcion -%c requiere un argumento.\n", optopt);
				} else if(isprint(optopt)) {
					fprintf(stderr, "Opcion desconocida '-%c'.\n", optopt);
				} else {
					fprintf(stderr, "Opcion con caracter desconocido '\\x%x'.\n", optopt);
				}
				return 1;
			default:
				abort();
		}
	}


	FILE* output = fopen(outputFile, "w");
	char newline = '\n';
	for (int i = 0; i < lines; ++i)
	{
		for (int j = 0; j < lineLength; ++j)
		{
			char letter = ADN[rand()%4];
			fprintf(output, "%c", letter);

		}
		if(i < lines - 1) fprintf(output, "\n");
	}
	fclose(output);
	free(outputFile);

	return 0;
}