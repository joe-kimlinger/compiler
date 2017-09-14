CC=			gcc
LD=			gcc
LDFLAGS=	-L.

TARGETS=	cminor

all:		$(TARGETS)

cminor:	scanner.o main.o
	$(LD) $(LDFLAGS) -o $@ $^

scanner.o:	scanner.c tokens.h
	$(CC) -c $< -o $@

main.o:	main.c tokens.h
	$(CC) -c $< -o $@

scanner.c:	scanner.flex
	flex -o $@ $^

clean:
	rm -f $(TARGETS) *.o scanner.c
