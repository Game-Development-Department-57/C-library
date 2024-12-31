.PHONY: debug

debug: endian.c
	gcc endian.c -c -g3
	ar -rcs libendian.a endian.o

libendian.a: endian.o
	ar -rcs libendian.a endian.o

endian.o: endian.c
	gcc endian.c -c