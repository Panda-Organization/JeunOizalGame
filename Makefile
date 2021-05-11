CC = gcc
EXE = Pouissance4
FLAGS = -Wall

all: compile 
	./$(EXE)

compile: 
	$(CC) $(FLAGS) ./src/*.c -o $(EXE)

clean: 
	rm -rf $(EXE)
