CFLAGS= -O2 -Wall

all: gen read

gen: gen.c
	$(CC) $(CFLAGS) -o gen gen.c

read: read.c
	$(CC) $(CFLAGS) -o read read.c

clean:
	rm -f gen read data.bin