CC=gcc
CFLAGS=-Wall -Werror -Wextra -pedantic -g
SOURCES=main.c
OBJECTS=
OBJECTS+=$(SOURCES:.c=.o)
EXECUTABLE=main

all: $(SOURCES) $(EXECUTABLE)

$(EXECUTABLE): $(OBJECTS)
	$(CC) $(OBJECTS) -o $@

.PHONY: clean
clean:
	$(RM) $(EXECUTABLE) $(SOURCES:.c=.o)
