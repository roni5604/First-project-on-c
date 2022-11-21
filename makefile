CC=gcc
AR=ar
OBJECTS_MAIN=main.o
OBJECTS_LOOP=advancedClassificationLoop.o basicClassification.o
OBJECTS_REC=advancedClassificationRecursion.o basicClassification.o
FLAGS= -Wall -g
LM = -lm


all: libclassloops.a libclassrec.a libclassrec.so libclassloops.so mains maindloop maindrec
loops: libclassloops.a 
loopd: libclassloops.so
recursives: libclassrec.a
recursived: libclassrec.so

libclassloops.a : $(OBJECTS_LOOP)
	$(AR) -rcs libclassloops.a $(OBJECTS_LOOP) 
libclassrec.a : $(OBJECTS_REC)
	$(AR) -rcs libclassrec.a $(OBJECTS_REC)
libclassrec.so : $(OBJECTS_REC)
	$(CC) -shared -o libclassrec.so $(OBJECTS_REC) 
libclassloops.so : $(OBJECTS_LOOP)
	$(CC) -shared -o libclassloops.so $(OBJECTS_LOOP) 
mains : $(OBJECTS_MAIN) libclassrec.a
	$(CC) $(FLAGS) -o mains $(OBJECTS_MAIN) libclassrec.a $(LM)
maindloop: $(OBJECTS_MAIN) libclassloops.so
	$(CC) $(FLAGS) -o maindloop $(OBJECTS_MAIN) ./libclassloops.so $(LM)
maindrec: $(OBJECTS_MAIN) libclassrec.so
	$(CC) $(FLAGS) -o maindrec $(OBJECTS_MAIN) ./libclassrec.so $(LM)

main.o: main.c NumClass.h
	$(CC) $(FLAGS) -c main.c 
basicClassification.o: basicClassification.c NumClass.h
	$(CC) $(FLAGS) -c basicClassification.c 
advancedClassificationLoop.o: advancedClassificationLoop.c NumClass.h
	$(CC) $(FLAGS) -c advancedClassificationLoop.c  
advancedClassificationRecursion.o: advancedClassificationRecursion.c NumClass.h
	$(CC) $(FLAGS) -c advancedClassificationRecursion.c 

.PHONY: clean all

clean:
	rm -f *.o *.a *.so mains maindloop maindrec 