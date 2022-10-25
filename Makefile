CC ?= gcc
CFLAGS += -Wall --pedantic -Werror

all:
	$(CC) $(LDFLAGS) -o jeudedames $(CFLAGS) jeudedames.c main.c

test:
	$(CC) $(LDFLAGS)  -o dames_tests $(CFLAGS) tests/test_main.c dames.c -lcunit

clean:
	rm -f *.o dames_tests jeudedames
