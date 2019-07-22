#include <stdio.h>
#include <stdlib.h>
#include "utilities.h"

int main(int argc, char **argv)
{
	char *tx = NULL;
	unsigned char *bytes = NULL;
	size_t bytesSize = 0;
	if (argc < 2) {
		setInput(&tx);
		bytesSize = hexstringToBytes(tx, &bytes);
		free(tx);
	} else {
		bytesSize = hexstringToBytes(argv[1], &bytes);
	}
	for (size_t i = 0; i < bytesSize; i++) {
		printf("%d ", bytes[i]);
	}
	printf("\ntx size: %lu byteSize: %lu\n", strlen(tx), bytesSize);
	unsigned char version[4];
	size_t j = 4;
	for (size_t i = 0; i < 4; i++) {
		version[i] = bytes[--j];
	}
	printf("\nVersion: ");
	for (size_t i = 0; i < 4; i++) {
		printf("%d", version[i]);
	}
	printf("\n");
	free(bytes);
	return 0;
}
