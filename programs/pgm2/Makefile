pgm: ReadGrades.o CalculateLetterGrade.o PrintGrade.o sort.o LinkedList.o main.o
	gcc -o pgm2 -lm ReadGrades.o CalculateLetterGrade.o PrintGrade.o sort.o LinkedList.o main.o	


ReadGrades.o: ReadGrades.c pgm2.h
	gcc -c ReadGrades.c

CalculateLetterGrade.o: CalculateLetterGrade.c pgm2.h
	gcc -c CalculateLetterGrade.c

PrintGrade.o: PrintGrade.c pgm2.h
	gcc -c PrintGrade.c

sort.o: sort.o pgm2.h
	gcc -c sort.c

LinkedList.o: LinkedList.c pgm2.h
	gcc -c LinkedList.c

main.o: main.c pgm2.h
	gcc -c main.c

