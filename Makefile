CC=			/usr/bin/gcc
CFLAGS=		-g -gdwarf-2 -Wall -std=gnu99
LD=			/usr/bin/gcc
LDFLAGS=	-L.

TARGETS=	cminor

all:		$(TARGETS)

cminor:	parser.tab.o scanner.o main.o
	$(LD) $(LDFLAGS) -o $@ $^

parser.tab.c:	parser.bison
	bison --defines=tokens.h -bparser -v $^ -o $@

parser.tab.o:	parser.tab.c tokens.h
	$(CC) $(CFLAGS) -c $< -o $@

scanner.o:	scanner.c tokens.h parser.tab.c
	$(CC) $(CFLAGS) -c $< -o $@

main.o:	main.c tokens.h parser.tab.c
	$(CC) $(CFLAGS) -c $< -o $@

scanner.c:	scanner.flex
	flex -o $@ $^

clean:
	rm -f $(TARGETS) *.o scanner.c parser.tab.c parser.output
