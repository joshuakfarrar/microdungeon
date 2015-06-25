CFLAGS=-Wall

O_FILES=monster.o room.o map.o

all: ex17

ex17: $(O_FILES)

clean:
	rm -f ex17 $(O_FILES)
