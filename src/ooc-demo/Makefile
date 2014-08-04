CC=gcc
CFLAGS=-I. -g
DEPS = tank.h
OBJ = tank.o tankgame.o 
%.o: %.c $(DEPS)
	$(CC) -c -o $@ $< $(CFLAGS)

tankgame: $(OBJ)
	gcc -o $@ $^ $(CFLAGS)
