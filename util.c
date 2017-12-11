/*
	IMPLEMENTACION DE FUNCIONES DE UTILIDAD (util.h)
*/
#include "util.h"

int getDigits(int number)
{
	int digits = 1;
	int temp_number = number;
	while(temp_number >= 10) {
		temp_number /= 10;
		digits++;
	}

	return digits;
}

char* intToString(int number)
{
	int digits = getDigits(number);

	char* str = (char*)malloc(digits+1);
	snprintf(str, digits+1, "%d", number);

	return str;
}

char* getRpName(char* dna_chain, int process_number)
{
	// largo del nombre es 8 + largo dna_chain + digitos en el numero de proceso
	char* file_name;
	char* process_id = intToString(process_number);
	int name_length = 8 + strlen(dna_chain) + strlen(process_id) + 1;

	file_name = (char*)malloc(name_length);
	strcpy(file_name, "rp_");
	strcat(file_name, dna_chain);
	strcat(file_name, "_");
	strcat(file_name, process_id);
	strcat(file_name, ".txt");

	return file_name;
}

char* getRcName(char* dna_chain)
{
	// largo del nombre es 7 + largo dna_chain
	char* file_name;
	int name_length = 7 + strlen(dna_chain) + 1;

	file_name = (char*)malloc(name_length);
	strcpy(file_name, "rc_");
	strcat(file_name, dna_chain);
	strcat(file_name, ".txt");

	return file_name;
}