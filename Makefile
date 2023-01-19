CC=gcc
AR=ar 
FLAGS= -Wall -g
OB_MAIN=main.o
OB_LIB=graph.o

all: lib graph


graph:$(OB_MAIN) graph.a
	$(CC) $(FLAGS) -o graph $(OB_MAIN) graph.a

lib: $(OB_LIB)
	$(AR) -rcs graph.a $(OB_LIB)

main.o:graph.h main.c
	$(CC) $(FLAGS) -c main.c

graph.o:graph.h graph.c
	$(CC) $(FLAGS) -c graph.c


.PHONY: clean all

clean:
	rm -f *.o *.a graph 
