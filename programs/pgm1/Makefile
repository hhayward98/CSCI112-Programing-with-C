pgm: ReadGrades.o CalculateLetterGrade.o PrintGrade.o main.o 
	gcc -o pgm -lm ReadGrades.o CalculateLetterGrade.o PrintGrade.o main.o

ReadGrades.o: ReadGrades.c pgm1.h
	gcc -c ReadGrades.c

CalculateLetterGrade.o: CalculateLetterGrade.c pgm1.h
	gcc -c CalculateLetterGrade.c

PrintGrade.o: PrintGrade.c pgm1.h
	gcc -c PrintGrade.c

main.o: main.c pgm1.h
	gcc -c main.c


