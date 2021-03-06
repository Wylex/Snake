CC=g++
CFLAGS= -lsfml-graphics -lsfml-window -lsfml-system

OBJECTS = .main.o .World.o .InputHandler.o .Collisions.o .Food.o .FPS.o .Snake.o .Trampa.o .Marcador.o .Modificador.o .Wall.o .Command.o .Subject.o

start: $(OBJECTS)   
	$(CC) -std=c++11 .*.o $(CFLAGS)

.main.o: main.cpp World.h
	$(CC) -std=c++11 -o $@ -c main.cpp

.World.o: World.cpp World.h Snake.h Collisions.h InputHandler.h Command.h Food.h Trampa.h FPS.h Modificador.h Wall.h
	$(CC) -std=c++11 -o $@ -c World.cpp

.Command.o: Command.cpp Command.h Snake.h
	$(CC) -std=c++11 -o $@ -c Command.cpp

.InputHandler.o: InputHandler.cpp InputHandler.h Command.h
	$(CC) -std=c++11 -o $@ -c InputHandler.cpp

.Collisions.o: Collisions.cpp Collisions.h Subject.h
	$(CC) -std=c++11 -o $@ -c Collisions.cpp

.Food.o: Food.cpp Food.h Trampa.h Snake.h Objeto.h
	$(CC) -std=c++11 -o $@ -c Food.cpp

.FPS.o: FPS.cpp FPS.h
	$(CC) -std=c++11 -o $@ -c FPS.cpp

.Snake.o: Snake.cpp Snake.h Entidad.h Food.h Trampa.h Marcador.h
	$(CC) -std=c++11 -o $@ -c Snake.cpp

.Trampa.o: Trampa.cpp Trampa.h Objeto.h
	$(CC) -std=c++11 -o $@ -c Trampa.cpp

.Marcador.o: Marcador.cpp Marcador.h
	$(CC) -std=c++11 -o $@ -c Marcador.cpp

.Modificador.o: Modificador.cpp Modificador.h Objeto.h Snake.h Trampa.h Food.h
	$(CC) -std=c++11 -o $@ -c Modificador.cpp

.Wall.o: Wall.h Wall.cpp Entidad.h
	$(CC) -std=c++11 -o $@ -c Wall.cpp

.Subject.o: Subject.h Subject.cpp Entidad.h
	$(CC) -std=c++11 -o $@ -c Subject.cpp
