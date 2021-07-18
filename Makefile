add-nbo : add-nbo.o
	gcc add-nbo.o -o add-nbo
add-nbo.o : add-nbo.c
	gcc -c add-nbo.c
clean :
	rm -f add-nbo.o
