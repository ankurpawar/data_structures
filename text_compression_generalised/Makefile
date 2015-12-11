mdc :	main.o func.o
	gcc -g -o mdc main.o func.o
main.o : main.c
	gcc -g -c main.c
func.o : func.c
	gcc -g -c func.c
clean : 
	rm -rf *.o mdc
