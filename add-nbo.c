#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <netinet/in.h>

uint32_t add_nbo(const char *filename) {
   	FILE *file;
	uint32_t num;
	
	file = fopen(filename, "rb");
	if (file == NULL) {
		perror("File open error");
		exit(1);
	}
	fread(&num, sizeof(uint32_t), 1, file);
	fclose(file);
	
	return ntohl(num);
}

int main(int argc, char *argv[]){
	if (argc != 3) {
        fprintf(stderr, "syntax : %s <file1> <file2>\n", argv[0]);
        exit(1);
	}

	uint32_t bin[2] = {add_nbo(argv[1]), add_nbo(argv[2])};
	printf("%d(0x%x) + %d(0x%x) = %d(0x%x)\n", bin[0], bin[0], bin[1], bin[1], bin[0] + bin[1], bin[0] + bin[1]);
	
	return 0;
}
