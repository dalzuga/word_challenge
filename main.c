#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define BUFFER 10

typedef struct Word {
  int n;
  const char *str;
  struct Word *next;
} Word;

/**
  * this program takes input from stdin, counts each word,
  * and displays a sorted list of word frequency
 */

int main(void)
{
	Word *word;
	char line[BUFFER];

	word = malloc(sizeof(Word));

	word->n = 0;
	word->str = NULL;
	word->next = NULL;

	while (fgets(line,BUFFER,stdin) != NULL)
	{
		printf("line:\t%s\n", line);
		word->str = strtok(line, " ");
		printf("strtok:\t%s\n", word->str);
		word->str = strtok(line, " ");
		printf("strtok:\t%s\n", word->str);
		word->str = strtok(line, " ");
		printf("strtok:\t%s\n", word->str);

		/* while (word->str != NULL) */
		/* { */
		/* 	word->next = malloc(sizeof(Word)); */
		/* 	word->str = strtok(line, " "); */
		/* 	word->n = 0; */
		/* 	printf("------1-------\n"); */
		/* } */
	}

	/* free(word); */

	return 0;
}
