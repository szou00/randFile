all: main.o random.o
	gcc -o testing main.o random.o

functions.o: random.c random.h
	gcc -c random.c

main.o: main.c random.h
	gcc -c main.c

run:
	./testing

clean:
	rm *.o
	rm *~
