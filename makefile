CC=gcc
CFLAGS=-I.
FLAGS = -Wall -g

# $@ - the file on the left side of the :
# $< - the first name in the dependencies list
# $^ - the right side of :

#$(TARGET): $(OBJ) lib.a
#	$(CC) -o $@ $^ $(CFLAGS)
all: isort txtfind

isort:  main1.o isort.a
	$(CC) $(FLAGS) -o isort main1.o isort.a

txtfind: main2.o txtfind.a
	$(CC) $(FLAGS) -o txtfind main2.o txtfind.a

isort.o: isort.c interface.h
	$(CC) $(FLAGS) -fPIC -c isort.c

txtfind.o: txtfind.c interface.h
	$(CC) $(FLAGS) -fPIC -c txtfind.c

txtfind.a: txtfind.o   # can also add here more objects
	ar rcs $@ $^
isort.a: isort.o   # can also add here more objects
	ar rcs $@ $^
#%.o: %.c $(DEPS)
#	$(CC) -c -o $@ $< $(CFLAGS)

# by convention, it starts with lib and ends with .a


.PHONY: clean all 

clean:
	rm -f *.o *.a isort txtfind
