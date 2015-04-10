NAME=techShell

RM=rm -f
PROG=./$(NAME)

all: techShell

techShell: techShell.o Parser.o Variable.o Command.o
	gcc -Wall techShell.o Parser.o Variable.o Command.o -o $(NAME) -std=c11

techShell.o: techShell.c
	gcc -c -Wall techShell.c

Parser.o: Parser.c
	gcc -c -Wall Parser.c

Variable.o: Variable.c
	gcc -c -Wall Variable.c

Command.o: Command.c
	gcc -c -Wall Command.c


clean:
	$(RM) $(NAME)
	$(RM) *.o

run:
	$(PROG)