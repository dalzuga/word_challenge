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

int main(void)
{
	WordList *word;
	char c = '\0';
	char buf[BUFFER] = "";
	/* char *str; */
	int i = 0, n = 0;

	word = malloc(sizeof(WordList));

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

		printf("%s\n", word->str);
		memset(buf, '\0', n); /* clear the buffer */
	}
	
	return 0;
}
