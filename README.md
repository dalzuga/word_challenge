# scality_challenge
This program takes input from stdin, counts each word,
and displays a sorted list of word frequency.

To feed a sample file to it, please use redirection.

###Example

`make`

`cat testfiles/random.txt | ./main`

###To Do

* Memory isn't freed. Should write a function to free the WordList and the index if this is to be used in another program.

* Hash tables can provide better performance than a WordList (linear for look-up; potentially linear for sorting, if using a smart hash function that takes frequency into account, and smart resizing to make sure there's enough buckets to keep the table sorted)

* For code readability, might be better to use `read()` or `fgets()` rather than `getc()` to obtain an input line, and use `strtok()`
  * Disadvantage:
    * Puts a limit on line length (BUFFER - 1) rather than on word length
  * Advantage:
    * Built-in function `strtok()` handles delimiters (extra whitespace, new lines, etc) so that there is no need to re-code it / document it (faster implementation)
* Add functionality to read directly from a file through `**argv` (command-line arguments) in addition to being able to read from `stdin`
