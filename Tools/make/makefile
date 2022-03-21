

main.o:
		${GCC} --include="C:/ti/ccs930/ccs/ccs_base/msp430/include_gcc/msp430f1611.h" -c ${SOURCEPATH}/main.c

all: program.out

clean:
		rm -f *.o
		rm -f *.out

program: main.o file1.o file2.o
		$(COMPILER) -o program main.o file1.o file2.o


file1.o: file1.c
		$(COMPILER) -c file1.c

file2.o: fil2.c
		$(COMPILER) -c file2.c
