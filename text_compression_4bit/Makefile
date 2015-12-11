mdc :	main.o func.o
	gcc -o mdc main.o func.o
main.o : main.c
	gcc -c main.c
func.o : func.c
	gcc -c func.c
clean : 
	rm -rf *.o mdc
