main.out: main.o fun.o
	gcc -o main.out main.o fun.o

main.o: main.c fun.h
	gcc -c main.c

fun.o: fun.c fun.h 
	gcc -c fun.c


clean:	
	rm *.out *.o

run:	
	./main.out
	

