#include "utilities.h"

void setInput(char **s)
{
	printf("Please supply a transaction in raw hex format.\n");
	char *line = NULL;
	size_t len = 0;
	getline(&line, &len, stdin);
	
	// Get rid of newline
	line[strcspn(line, "\n")] = 0; 
	*s = malloc(strlen(line) + 1);
	strcpy(*s, line);
	free(line);

}

int hexDigitToInt(char digit)
{
	digit = tolower(digit);
	if (digit >= '0' && digit <='9')
	       return (int)(digit - '0');
	else if (digit >= 'a' && digit <= 'f') {
		return (int)(digit - '1' - '0') + 10; 
	}	
	return -1;
}

int hexstringToBytes(const char *hexstring, unsigned char **result)
{
	if (strlen(hexstring) % 2) {
		fprintf(stderr, "The hexstring is not an even number of characters.\n");
		exit(EXIT_FAILURE);
	}
	
	size_t resultLength = strlen(hexstring) / 2;
	*result = realloc(*result, resultLength);
	size_t i, j = 0;
	for (i = 0; i < strlen(hexstring); i++) {
		if (i % 2)
			continue;
		int sixteens = hexDigitToInt(hexstring[i]);
		int units = hexDigitToInt(hexstring[i + 1]);
		int num = (sixteens * 16) + units;
		*(*result + j) = num;
		j++;
	}

	return resultLength;

}
