CFLAGS= -O2 -Wall

all: libadd.so prog1 prog2

prog1: main1.c
	$(CC) $(CFLAGS) -o prog1 main1.c ./libadd.so

prog2: main2.c
	$(CC) $(CFLAGS) -o prog2 main2.c ./libadd.so

libadd.so: add.c
	$(CC) $(CFLAGS) -fPIC -shared -o libadd.so add.c

clean:
	rm -f *.o *.so prog1 prog2