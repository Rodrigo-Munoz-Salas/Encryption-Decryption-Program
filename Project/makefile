CC=gcc
CFLAGS=-I. -g -w -lm
DEPS= railcipher.utils.h
OBJ = railcipher.o encrypt.o decrypt.o stringManipulation.o
%.o: %.c $(DEPS)
	$(CC) -c -o $@ $< $(CFLAGS)
railcipher: $(OBJ)
	$(CC) -o $@ $^ $(CFLAGS)