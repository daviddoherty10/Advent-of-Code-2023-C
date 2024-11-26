#include <ctype.h>
#include <stdbool.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#define BUFFER_SIZE 256

int parser(char *inputArr) {
	int total = 0;
	int index = 0;
	char *currentLine = malloc((10 + 1) * sizeof(char));
	if (!currentLine) {
		fprintf(stderr, "Memory allocation failed\n");
		return -1;
	}

	size_t inputLength = strlen(inputArr);

	for (int i = 0; i < inputLength; i++) {
		if (isdigit(inputArr[i])) {
			if (index < 10) {  // Avoid buffer overflow
				currentLine[index] = inputArr[i];
				index++;
			}
		} else if (!isdigit(inputArr[i])) {
			switch (inputArr[i]) {
				case 'o':
					if (strncmp(&inputArr[i + 1], "ne", 2) == 0) {
						currentLine[index] = '1';
						index++;
					}
					break;
				case 't':
					if (strncmp(&inputArr[i + 1], "wo", 2) == 0) {
						currentLine[index] = '2';
						index++;
					} else if (strncmp(&inputArr[i + 1], "hree", 4) == 0) {
						currentLine[index] = '3';
						index++;
					}
					break;
				case 'f':
					if (strncmp(&inputArr[i + 1], "our", 3) == 0) {
						currentLine[index] = '4';
						index++;
					} else if (strncmp(&inputArr[i + 1], "ive", 3) == 0) {
						currentLine[index] = '5';
						index++;
					}
					break;
				case 's':
					if (strncmp(&inputArr[i + 1], "ix", 2) == 0) {
						currentLine[index] = '6';
						index++;
					} else if (strncmp(&inputArr[i + 1], "even", 4) == 0) {
						currentLine[index] = '7';
						index++;
					}
					break;
				case 'e':
					if (strncmp(&inputArr[i + 1], "ight", 4) == 0) {
						currentLine[index] = '8';
						index++;
					}
					break;
				case 'n':
					if (strncmp(&inputArr[i + 1], "ine", 3) == 0) {
						currentLine[index] = '9';
						index++;
					}
					break;
			}
		}

		if (inputArr[i] == '\n' && index > 0) {
			currentLine[1] = currentLine[index - 1];
			currentLine[2] = '\0';
			total += atoi(currentLine);
			memset(currentLine, 0, (3 + 1) * sizeof(char));
			index = 0;
		}
	}

	free(currentLine);
	return total;
}

int main(void) {
	clock_t start = clock();
	char *fileName = "dayOneA.txt";
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
