#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

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

WordList *find_word(WordList *first_node, char *s);

int main(void)
{
	WordList *word, *first_node;
	char c = '\0';
	char buf[BUFFER] = "";
	/* char *str; */
	int i = 0, n = 0;

	word = malloc(sizeof(WordList));
	word->str = NULL;
	word->next = NULL;
	word->n = 0;
	first_node = word;

	while (c != EOF)
	{
		i = 0;
		/* while (read(STDIN_FILENO,buf,BUFFER)) */
		while ((c = getc(stdin)) != EOF)
		{
			if (c == ' ' || c == '\n')
				break;
			buf[i] = c;
			i++;
		}

		if (c == EOF)
			break;

		n = i + 1;
		/* printf("n is:\t%d\n", n); */
		word->str = malloc(n);
		strncpy(word->str, buf, n);

		/* for (i = 0; i < n; i++) */
		/* { */
		/* 	printf("str[%d] is:\t%c\n", i, str[i]); */
		/* } */

		/* printf("%s\n", word->str); */
		memset(buf, '\0', n); /* clear the buffer */

		word->next = malloc(sizeof(WordList));
		word = word->next;
		word->str = NULL;
		word->next = NULL;
		word->n = 0;
	}
	
	/* /\* prints *\/ */
	/* word = first_node; */

	/* while (word->next != NULL) */
	/* { */
	/* 	printf("%s\n", word->str); */
	/* 	word = word->next; */
	/* } */

	/* find the word */
	word = find_word(first_node, "hi");

	if (word == NULL)
		printf("Word not found\n");
	else
		printf("The word \"%s\" was found.\n", word->str);

	return 0;
}

/* returns NULL if word does not exist */
WordList *find_word(WordList *first_node, char *s)
{
	WordList *word_ptr;
	word_ptr = first_node;

	while (word_ptr != NULL)
	{
		/* printf("---------------1while---------------\n"); */
		/* printf("%p\n", (void *) word_ptr); */

		if (word_ptr->str == NULL)
		{
			/* printf("---------------2word->str==NULL---------------\n"); */
			return NULL;
		}

		printf("%s\n", word_ptr->str);

		if (strcmp(word_ptr->str, s) == 0)
			return word_ptr;

		word_ptr = word_ptr->next;
	}

	return NULL;
}
