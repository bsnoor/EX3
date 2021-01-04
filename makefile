FLAGS = -Wall -g
CC = gcc 
all : isort txtfind
isort :isortd main1.o 
 $(CC) main.o -o  isort
isortd : isort.o 
$(CC) $(FLAGS) -fPIC -c isort.c 
main1.o: main.c universal.h 
$(CC) $(FLAGS) -fPIC -c main1.c
txtfind : txtfind.o 
$(CC) $(FLAGS) -fPic -c txtfind.c
main2.o : main2.o universal.h 
$(CC) $(FLAGS) -fPIC -c main2.o 
.PHONY : clean all
 clean :
 rm -f *.o txtfind isort m*.so 
