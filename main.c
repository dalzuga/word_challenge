#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define BUFFER 80

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
		word->str = strtok(line, " ");
		while (word->str != NULL)
		{
			printf("word:\t%s\n", word->str);
			word->str = strtok(NULL, " ");
		}
	}

	/* free(word); */

	return 0;
}
