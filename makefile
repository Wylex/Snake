CC=g++
CFLAGS=-lsfml-graphics -lsfml-window -lsfml-system

OBJECTS = .main.o .World.o .Command.o .InputHandler.o .Collisions.o .Food.o .FPS.o .Snake.o .Trampa.o .Marcador.o 

start: $(OBJECTS)   
	$(CC) -std=c++11 .*.o $(CFLAGS)

.main.o: main.cpp World.h
	$(CC) -std=c++11 -o $@ -c main.cpp

.World.o: World.cpp World.h Snake.h Collisions.h InputHandler.h Command.h Food.h Trampa.h FPS.h
	$(CC) -std=c++11 -o $@ -c World.cpp

.Command.o: Command.cpp Command.h Snake.h
	$(CC) -std=c++11 -o $@ -c Command.cpp

.InputHandler.o: InputHandler.cpp InputHandler.h Command.h
	$(CC) -std=c++11 -o $@ -c InputHandler.cpp

.Collisions.o: Collisions.cpp Collisions.h Entidad.h
	$(CC) -std=c++11 -o $@ -c Collisions.cpp

.Food.o: Food.cpp Food.h Entidad.h Trampa.h Snake.h Objeto.h
	$(CC) -std=c++11 -o $@ -c Food.cpp

.FPS.o: FPS.cpp FPS.h
	$(CC) -std=c++11 -o $@ -c FPS.cpp

.Snake.o: Snake.cpp Snake.h Entidad.h Food.h Trampa.h Marcador.h
	$(CC) -std=c++11 -o $@ -c Snake.cpp

.Trampa.o: Trampa.cpp Trampa.h Entidad.h Snake.h
	$(CC) -std=c++11 -o $@ -c Trampa.cpp

.Marcador.o: Marcador.cpp Marcador.h
	$(CC) -std=c++11 -o $@ -c Marcador.cpp
