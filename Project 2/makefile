program: main.o product.o
	gcc -o program main.o product.o

main.o: main.c product.h	
	gcc -c main.c

sum.o: product.c product.h	
	gcc -c product.c

clean:	
	rm -f *.o program

