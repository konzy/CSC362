// Assignment1.cpp : Defines the entry point for the console application.
//
#include "stdafx.h"
#include <stdio.h>
#include <ctype.h>

int main()
{
	FILE *file;
	char FILE_NAME[] = "C:\\Users\\konzy\\VisualProjects\\CSC362\\Asst1\\input1.txt";
	char NEWLINE = '\n';
	float HUNDRED = 100.0;
	file = fopen(FILE_NAME, "r");

	int c;
	int isNewSentence = 1;
	int lookForLower = 0;
	int totalCount = 1;
	int printedCount = 1;


	if (file) {
		while ((c = getc(file)) != EOF) {
			totalCount += 1;
			if (isNewSentence == 1 && isupper(c)) {
				putchar(c);
				isNewSentence = 0;
				lookForLower = 1;
				printedCount += 1;
			}
			else if (isNewSentence == 0 && lookForLower == 1 && islower(c)) {
				putchar(c);
				lookForLower = 0;
				isNewSentence = 0;
				printedCount += 1;
			}
			else if (isNewSentence == 0 && lookForLower == 0 && isupper(c)) {
				putchar(tolower(c));
				lookForLower = 1;
				isNewSentence = 0;
				printedCount += 1;
			}
			else if (c >= 32 && c <= 44 || c == NEWLINE) {
				putchar(c);
				printedCount += 1;
			}
			else if (c == 46) {
				putchar(c);
				isNewSentence = 1;
				printedCount += 1;
			}
		}
		fclose(file);
		printf("\n");
		printf("Input file C:\\Users\\konzy\\VisualProjects\\CSC362\\Asst1\\input1.txt\n");
		printf("Output file C:\\Users\\konzy\\VisualProjects\\CSC362\\Asst1\\input1.txt\n");
		printf("Total Count %i\n", totalCount);
		printf("Printed Count %i\n", printedCount);
		float percentReduction = HUNDRED * (1 - (float)printedCount / (float)totalCount);
		printf("Precent reduction in output %.2f%%\n", percentReduction);
	}

	return 0;
}

