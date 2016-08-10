#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define BUFFER 80

typedef struct WordList {
  int n;
  char *str;
  struct WordList *next;
} WordList;

/**
  * this program takes input from stdin, counts each word,
  * and displays a sorted list of word frequency
 */

int main(void)
{
	WordList *first_word;
	WordList *word;
	char line[BUFFER];

	word = malloc(sizeof(WordList));
	first_word = word;

	word->n = 0;
	word->str = NULL;
	word->next = NULL;

	/* stores words in a Wordlist using strtok */
	if (fgets(line,BUFFER,stdin) == NULL)
	    return 1;
	word->str = strtok(line, "\n"); /* strips the new line */
	word->str = strtok(line, " ");
	while (word->str != NULL)
	{
		word->next = malloc(sizeof(WordList));
		word = word->next;
		word->n = 0;
		word->next = NULL;
		word->str = strtok(NULL, " ");
	}

	word = first_word;

	/* prints */
	while (word->next != NULL)
	{
		printf("%s\n", word->str);
		word = word->next;
	}

	word = first_word;

	free(first_word);

	return 0;
}
