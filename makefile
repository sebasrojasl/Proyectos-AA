# change application name here (executable output name)
TARGET=object
 
# compiler
CC=gcc
# debug
DEBUG=-g
# optimisation
OPT=-O0
# warnings
WARN=-Wall
 
PTHREAD=-pthread
 
CCFLAGS=$(DEBUG) $(OPT) $(WARN) $(PTHREAD) -pipe

 
# linker
LD=gcc
LDFLAGS=$(PTHREAD) $(GTKLIB) -export-dynamic -lm
 
OBJS=    main.o
 
all: $(OBJS)
	$(LD) -o $(TARGET) $(OBJS) $(LDFLAGS)
    
proyecto0.o: main.c
	$(CC) -c $(CCFLAGS) main.c $(GTKLIB) -o main.o -lm
    
clean:
	rm -f *.o $(TARGET)
