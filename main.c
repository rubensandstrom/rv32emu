#include <stdint.h>
#include <stdlib.h>
#include <stdio.h>
#include "decode.h"
#include "instructions.c"

#define MEMSIZE 1024*1024 * sizeof(uint32_t)
uint32_t *mem = NULL;
uint32_t reg[32];
uint32_t pc;

int main(int argc, char **argv) {
	mem = (uint32_t *)malloc(MEMSIZE); // 4mb memory
	if (memory == NULL) {
		printf("Couldn't allocate memory.");
		return 1;
	}

	free(memory);
	return 0;
	
}
