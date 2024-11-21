#include <ctype.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#define BUFFER_SIZE 256

int parser(char *inputArr) {
	int total = 0;
	int index = 0;
	char *currentLine = malloc((3 + 1) * sizeof(char));
	if (!currentLine) {
		fprintf(stderr, "Memory allocation failed\n");
		return -1;
	}

	size_t inputLength = strlen(inputArr);

	for (int i = 0; i < inputLength; i++) {
		if (isdigit(inputArr[i])) {
			currentLine[index] = inputArr[i];
			index++;
		} else if (!isdigit(inputArr[i])) {
			switch (inputArr[i]) {
				case 'o':
					char *result = strstr(inputArr, "ne");
			}

		} else if (inputArr[i] == '\n') {
			if (index > 0) {
				currentLine[1] = currentLine[index - 1];
			} else {
				currentLine[1] = currentLine[0];
			}
			currentLine[2] = '\0';
			total += atoi(currentLine);
			memset(currentLine, 0, (3 + 1) * sizeof(char));
			index = 0;
		} else {
			continue;
		}
	}

	free(currentLine);
	return total;
}

int main(void) {
	clock_t start = clock();
	char *fileName = "inputData.txt";
	FILE *fp = fopen(fileName, "r");
	if (fp == NULL) {
		printf("Could Not Open File %s\n.", fileName);
		return 1;
	}

	char buffer[BUFFER_SIZE];
	int total = 0;

	while (fgets(buffer, BUFFER_SIZE, fp)) {
		total += parser(buffer);
	}

	printf("Total: %d\n\nTime Taken: %lf\n", total, (double)(clock() - start) / CLOCKS_PER_SEC);

	fclose(fp);
	return 0;
}
