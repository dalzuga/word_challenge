#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#define BUFFER 80		/* maximum word size */

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
void print_wordlist(WordList *first_node);
int compare_word_freq(const void *a, const void *b);

int main(void)
{
	WordList *word, *first_node, *tmp_word;
	char c = '\0';
	char buf[BUFFER] = "";
	char *str;
	int i = 0, n;

	word = malloc(sizeof(WordList));
	word->str = NULL;
	word->next = NULL;
	word->n = 1;
	first_node = word;
	tmp_word = NULL;

	while (c != EOF)
	{
		i = 0;
		while ((c = getc(stdin)) != EOF)
		{
			if (c == ' ' || c == '\n') /* split text by space or newline */
				break;
			buf[i] = c;
			i++;
		}

		if (c == EOF)
			break;

		n = i + 1;

		str = malloc(n);
		strncpy(str, buf, n);

		if ((tmp_word = find_word(first_node, str)) == NULL) /* check if new word */
		{
			word->str = str;
			word->next = malloc(sizeof(WordList));
			word = word->next;
			word->str = NULL;
			word->next = NULL;
			word->n = 1; /* init count to 1 */
		}
		else		/* word exists */
			(tmp_word->n)++; /* increment the count for this word */

		memset(buf, '\0', n); /* clear the buffer to read next word */
	}
	
	print_wordlist(first_node);

	return 0;
}

/* check if the word exists in the WordList chain */
WordList *find_word(WordList *first_node, char *s)
{
	WordList *word_ptr;
	word_ptr = first_node;

	while (word_ptr != NULL)
	{
		if (word_ptr->str == NULL)
		{
			return NULL;
		}

		if (strcmp(word_ptr->str, s) == 0)
			return word_ptr;

		word_ptr = word_ptr->next;
	}

	return NULL;
}

/* prints all the words in the WordList */
void print_wordlist(WordList *first_node)
{
	WordList *word;
	int i = 0, n;
	WordList **index = NULL;

	int (*cmp_ptr)(const void *, const void *); /* function pointer variable 'cmp' */
	cmp_ptr = &compare_word_freq;		    /* point to the function */

	word = first_node;

	while (word->next != NULL)
	{
		i++;
		word = word->next;
	}

	n = i;

	index = malloc(sizeof(WordList *) * n);

	word = first_node;
	for (i = 0; word->next != NULL; i++)
	{
		index[i] = word;
		word = word->next;
	}

	qsort(index, n, sizeof(WordList *), cmp_ptr); /* sorts the words by their frequency */

	for (i = 0; i < n; i++)
	{
		printf("%d\t%s\n", index[i]->n, index[i]->str); /* prints */
	}
}

/**
 * compare function to be used by qsort built-in
 */
int compare_word_freq(const void *a, const void *b)
{
	WordList *word_a, *word_b;

	word_a = *((WordList **) a);
	word_b = *((WordList **) b);

	if (word_a->n < word_b->n)
		return 1;
	if (word_a->n == word_b->n)
		return 0;

	return -1;
}
