#include <stdio.h>
#include <stdlib.h>

typedef struct Word {
int n;
char *str;
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

	while (fgets(line,80,stdin) != NULL)
	{
		printf("%s", line);
	}

	free(word);

	return 0;
}
