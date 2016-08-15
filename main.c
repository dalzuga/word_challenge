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

		str = malloc(n);
		strncpy(str, buf, n);

		if ((tmp_word = find_word(first_node, str)) == NULL)
		{
			word->str = str;
			word->next = malloc(sizeof(WordList));
			word = word->next;
			word->str = NULL;
			word->next = NULL;
			word->n = 1;
		}
		else
			(tmp_word->n)++;

		memset(buf, '\0', n); /* clear the buffer */
	}
	
	print_wordlist(first_node);

	/* find the word */
	/* word = find_word(first_node, "hi"); */

	/* if (word == NULL) */
	/* 	printf("Word not found\n"); */
	/* else */
	/* 	printf("The word \"%s\" was found.\n", word->str); */

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

		/* printf("%s\n", word_ptr->str); */

		if (strcmp(word_ptr->str, s) == 0)
			return word_ptr;

		word_ptr = word_ptr->next;
	}

	return NULL;
}

/* prints */
void print_wordlist(WordList *first_node)
{
	WordList *word;
	int i = 0, n;
	WordList **index = NULL;

	int (*cmp_ptr)(const void *, const void *);
	cmp_ptr = &compare_word_freq;

	word = first_node;

	while (word->next != NULL)
	{
		i++;
		word = word->next;
	}

	n = i;

	/* printf("-----------------print-----------------\n"); */
	/* printf("The number of words is:\t\t%d\n", n); */

	index = malloc(sizeof(WordList *) * n);

	/* printf("Sizeof():\t%lu\n", sizeof(WordList *) * n); */

	word = first_node;
	for (i = 0; word->next != NULL; i++)
	{
		index[i] = word;
		/* printf("i:\t%d\t&index[%d]:\t%p\n", i, i, (void *) &(index[i])); */
		/* printf("%d\t%s\n", word->n, word->str); */
		word = word->next;
	}

	/* printf("------------ordered print--------------\n"); */
	/* printf("The number of words is:\t\t%d\n", n); */

	qsort(index, n, sizeof(WordList *), cmp_ptr);

	/* cmp_ptr(index[0], index[1]); */
	/* cmp_ptr(index[1], index[2]); */
	/* cmp_ptr(index[2], index[3]); */
	/* cmp_ptr(index[3], index[4]); */

	for (i = 0; i < n; i++)
	{
		printf("%d\t%s\n", index[i]->n, index[i]->str);
	}

	/* for (i = 0; i < n; i++) */
	/* { */
	/* 	printf("a[%d] =\t%d\n", i, array_freq[i]); */
	/* } */

}

int compare_word_freq(const void *a, const void *b)
{
	WordList *word_a, *word_b;
	WordList **word_a_dp, **word_b_dp;

	word_a_dp = (WordList **) a;
	word_b_dp = (WordList **) b;

	word_a = (WordList *) *word_a_dp;
	word_b = (WordList *) *word_b_dp;

	/* printf("----------Memory addresses----------\n"); */
	/* printf("const void *a:\t%p\n", a); */
	/* printf("const void *b:\t%p\n", b); */

	/* printf("Comparing:\t%s to \t%s\n", word_a->str, word_b->str); */

	if (word_a->n < word_b->n)
		return 1;
	if (word_a->n == word_b->n)
		return 0;

	return -1;
}
