CC      = /opt/homebrew/opt/llvm/bin/clang
CFLAGS  = -O3 -fopenmp -L/opt/homebrew/opt/libomp/lib
RM      = rm -f

default: all

all: example1 example2 example3

example1: example1.c
	$(CC) $(CFLAGS) -o example1 example1.c

example2: example2.c
	$(CC) $(CFLAGS) -o example2 example2.c

example3: example3.c
	$(CC) $(CFLAGS) -o example3 example3.c

clean:
	$(RM) example1 example2 example3
