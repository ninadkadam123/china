main.out: main.o emp.o functions.o
	gcc -o main.out main.o emp.o functions.o

main.o: main.c emp.h functions.h
	gcc -c main.c

emp.0: emp.c emp.h
	gcc -c emp.c

functions.o: functions.c functions.h emp.h
	gcc -c functions.c

clean:
	rm *.o *.out

run:
	./main.out


