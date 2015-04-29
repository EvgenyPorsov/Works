app : main.o a.o
	gcc main.o a.o -o app
main.o : main.c
	gcc -O0 -c main.c
a.o : a.asm
	nasm -f elf a.asm

clean: 
	rm -f *.o
	rm -f asm
