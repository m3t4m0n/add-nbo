#include <stdint.h> // for uint32_t
#include <netinet/in.h> // for htons
#include <stdlib.h> // for strtol
#include <stdio.h> // for printf

int main(int argc, char *argv[]) {
	uint32_t bin1, bin2;
	int readFP1, readFP2, readSize1, readSize2;
	FILE *fp1 = fopen(argv[1], "rb");
	FILE *fp2 = fopen(argv[2], "rb");
	
	if(argc != 3) {
		printf("example : ./add-nbo argv1 argv2\n");
		exit(1);
	}

	if(fp1 == NULL || fp2 == NULL) {
		printf("fopen error\n");
		exit(1);
	}

	readSize1 = fread(&bin1, sizeof(bin1), 1, fp1);
	readSize2 = fread(&bin2, sizeof(bin2), 1, fp2);
	if(!readSize1 || !readSize2) {
		printf("fread error\n");
		exit(1);
	}
	
	readFP1 = ntohl(bin1);
	readFP2 = ntohl(bin2);	
	printf("%d(0x%x) + %d(0x%x) = %d(0x%x)\n", readFP1, readFP1, readFP2, readFP2, readFP1+readFP2, readFP1+readFP2);

	fclose(fp1);
	fclose(fp2);

	return 0;
}
