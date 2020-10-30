all: main.o mystruct.o
	gcc -o main main.o mystruct.o
main.o: main.c mystruct.h
	gcc -c main.c
mystruct.o: mystruct.c mystruct.h
	gcc -c mystruct.c
run:
	./main
clean:
	rm *.o
