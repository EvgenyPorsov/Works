CC := gcc

CFLAGS := -std=c99 -Wall -Werror -pedantic

db.exe : main.o menu.o holidays.o
	$(CC) $(CFLAGS) $^ -o $@
	
%.o : %.c *.h
	$(CC) $(CFLAGS) -c $<
	
clean :
	$(RM) *.o *.exe
