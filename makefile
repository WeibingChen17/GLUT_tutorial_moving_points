OS := $(shell uname -s)
ifeq ($(OS), Linux)
    CC=g++
endif
ifeq ($(OS), Darwin)
    CC=clang++
LIBGLUT=-lglut
LIBGL=-lGL

.PHONY: all
all: movinglp3d movinglp triangle cube point linepoint

%.o: %.cc
	$(CC) -c -o $@ $<

triangle: triangle.o
	$(CC) triangle.o $(LIBGLUT) $(LIBGL) -o triangle

cube: cube.o
	$(CC) cube.o $(LIBGLUT) $(LIBGL) -o cube

point: point.o
	$(CC) point.o $(LIBGLUT) $(LIBGL) -o point

linepoint: linepoint.o
	$(CC) linepoint.o $(LIBGLUT) $(LIBGL) -o linepoint

movinglp: movinglp.o
	$(CC) movinglp.o $(LIBGLUT) $(LIBGL) -o movinglp

movinglp3d: movinglp3d.o
	$(CC) movinglp3d.o $(LIBGLUT) $(LIBGL) -o movinglp3d

.PHONY: clean

clean: 
	rm -f *.o triangle cube
