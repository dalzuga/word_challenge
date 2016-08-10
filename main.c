#include <stdio.h>
#include <stdlib.h>
#include <string.h>

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
	char line[80];

	word = malloc(sizeof(Word));

	word->n = 0;
	word->str = NULL;
	word->next = NULL;

	while (fgets(line,80,stdin) != NULL)
	{
		word->str = strtok(line, " ");
		while (word->str != NULL)
		{
			word->next = malloc(sizeof(Word));
			word->str = strtok(line, " ");
			word->n = 0;
			printf("------1-------\n");
		}
	}

	free(word);

	return 0;
}
