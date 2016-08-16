# scality_challenge
This program takes input from stdin, counts each word,
and displays a sorted list of word frequency.

To feed a sample file to it, please use redirection.

###Example

`make`

`cat testfiles/random.txt | ./main`

###To Do

* Memory isn't freed. Should write a function to free the WordList and the index.

* Hash tables with a good hash function can provide better performance

* For code readability, might be better to use `read()` or `fgets` to obtain new line, and use `strtok()`
  * Disadvantage:
    * Puts a limit on line length (BUFFER - 1)
  * Advantage:
    * Built-in function `strtok()` handles delimiters (extra whitespace, new lines, etc) so that there is no need to re-code it / document it
