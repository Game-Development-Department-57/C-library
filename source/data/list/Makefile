all: list.o list_basic.o list_base.o
	ar rcs liblist.a list.o list_basic.o list_base.o

list.o: list.c
	gcc -c -O2 -Wall -fsanitize=address list.c

list_basic.o: list_basic.c
	gcc -c -O2 -Wall -fsanitize=address list_basic.c

list.o: list_base.c
	gcc -c -O2 -Wall -fsanitize=address list_base.c

clear:
  del *.a
  del *.o