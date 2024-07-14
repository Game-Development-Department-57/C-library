.PHONY: all clean git_push file_set

ROOTPATH := ..\..\..

all: liblist.a
	echo OK

list.o: list.c
	gcc -c -O2 -Wall -fsanitize=address list.c

list_basic.o: list_basic.c
	gcc -c -O2 -Wall -fsanitize=address list_basic.c

list_base.o: list_base.c
	gcc -c -O2 -Wall -fsanitize=address list_base.c

liblist.a: list.o list_basic.o list_base.o
	ar rcs liblist.a list.o list_basic.o list_base.o

git_push:
	git add $(ROOTPATH)
	git status
	git commit -m "update"
	git push

file_set: liblist.a
	copy liblist.a $(ROOTPATH)\lib
	copy *.h $(ROOTPATH)\include\data\list

clean:
	del *.a
	del *.o