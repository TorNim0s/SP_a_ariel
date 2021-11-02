CC = gcc
AR=ar
CFLAGS = -Wall -g
LOOPOBJ = basic.o advencedClassificationLoop.o
RECUSIVEOBJ = basic.o advencedClassificationRecursion.o

all: loops, recursives, recursived, loopd, mains, maindloop, maindrec

main.o: main.c NumClass.h
    $(CC) $(CFLAGS) -c main.c
basicClassification.o: basicClassification.c NumClass.h
    $(CC) $(CFLAGS) -lm -c basicClassification.c
advencedClassificationLoop.o: advencedClassificationLoop.c NumClass.h
    $(CC) $(CFLAGS) -lm -c advencedClassificationLoop.c
advencedClassificationRecursion.o: advencedClassificationRecursion.c NumClass.h
    $(CC) $(CFLAGS) -lm -c advencedClassificationRecursion.c 

loops: libclassloops.a

libclassloops.a: $(LOOPOBJ)
    $(AR) -rcs libclassloops.a $(LOOPOBJ)

recursives: libclassrec.a

libclassrec.a: $(RECUSIVEOBJ)
    $(AR) -rcs libclassrec.a $(RECUSIVEOBJ)    

loopd: libclassloops.so

libclassloops.so: $(LOOPOBJ)
    $(CC) -shared -o libclassloops.so $(LOOPOBJ)

recursived: libclassrec.so

libclassrec.so: $(RECUSIVEOBJ)
    $(CC) -shared -o libclassrec.so $(RECUSIVEOBJ)

mains: main.o libclassrec.a
    $(CC) $(FLAGS) -o mains main.o libclassrec.a

maindloop: main.o libclassloops.so
    $(CC) $(FLAGS) -o maindloop main.o ./libclassloops.so

maindrec: main.o libclassrec.so
    $(CC) $(FLAGS) -o maindrec main.o ./libclassrec.so

.PHONY: clean all loops loopd recursives recursived
clean:
    rm -f *.o *.a *.so mains maindloop maindrec
