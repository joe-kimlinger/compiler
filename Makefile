CC=			gcc
CFLAGS=		-g -gdwarf-2 -Wall -std=gnu99
LD=			gcc
LDFLAGS=	-L.

TARGETS=	cminor

all:		$(TARGETS)

cminor:	parser.tab.o scanner.o main.o decl.o expr.o param_list.o stmt.o type.o
	$(LD) $(LDFLAGS) -o $@ $^

parser.tab.c:	parser.bison
	bison --defines=tokens.h -bparser -v $^ -o $@

parser.tab.o:	parser.tab.c tokens.h
	$(CC) $(CFLAGS) -c $< -o $@

scanner.o:	scanner.c tokens.h parser.tab.c
	$(CC) $(CFLAGS) -c $< -o $@

main.o:	main.c tokens.h parser.tab.c
	$(CC) $(CFLAGS) -c $< -o $@

decl.o: decl.c decl.h
	$(CC) $(CFLAGS) -c $< -o $@

expr.o: expr.c expr.h
	$(CC) $(CFLAGS) -c $< -o $@

param_list.o: param_list.c param_list.h
	$(CC) $(CFLAGS) -c $< -o $@

stmt.o: stmt.c stmt.h
	$(CC) $(CFLAGS) -c $< -o $@

type.o: type.c type.h
	$(CC) $(CFLAGS) -c $< -o $@

scanner.c:	scanner.flex
	flex -o $@ $^

clean:
	rm -f $(TARGETS) *.o scanner.c parser.tab.c parser.output tokens.h *.out
