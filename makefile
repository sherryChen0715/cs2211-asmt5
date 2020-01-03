all: main.c datatype.c datatype.h bst.c bst.h matrix.c matrix.h
	gcc -o mymatrix main.c datatype.c datatype.h bst.c bst.h matrix.c matrix.h
	./mymatrix
clean:
	rm mymatrix
