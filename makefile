CXX = g++
CXXFLAGS = -Wall
OBJECTS = Entity.o Area.o Game.o Zerg.o Zergling.o Mutalisk.o Hydralisk.o Terran.o Marine.o Ghost.o Battlecruiser.o
IODIR = ../../proj4_IO

proj4: $(OBJECTS) main.cpp
	$(CXX) $(CXXFLAGS) $(OBJECTS) main.cpp -o proj4

Entity.o: Entity.cpp Entity.h
	$(CXX) $(CXXFLAGS)  -c Entity.cpp

Area.o: Area.cpp Area.h
	$(CXX) $(CXXFLAGS)  -c Area.cpp

Game.o: Area.h Entity.h Zerg.h Terran.h Hydralisk.h Mutalisk.h Zergling.h Battlecruiser.h Ghost.h Marine.h Game.h Game.cpp
	$(CXX) $(CXXFLAGS)  -c Game.cpp

Zerg.o: Zerg.cpp Zerg.h Entity.o
	$(CXX) $(CXXFLAGS)  -c Zerg.cpp

Zergling.o: Zergling.cpp Zerg.o Zergling.h Entity.o
	$(CXX) $(CXXFLAGS)  -c Zergling.cpp

Mutalisk.o: Mutalisk.cpp Mutalisk.h Zerg.o Entity.o
	$(CXX) $(CXXFLAGS)  -c Mutalisk.cpp

Hydralisk.o: Hydralisk.cpp Hydralisk.h Zerg.o Entity.o
	$(CXX) $(CXXFLAGS)  -c Hydralisk.cpp

Terran.o: Terran.cpp Terran.h Entity.o
	$(CXX) $(CXXFLAGS)  -c Terran.cpp

Marine.o: Marine.cpp Marine.h Terran.o Entity.o
	$(CXX) $(CXXFLAGS)  -c Marine.cpp

Ghost.o: Ghost.cpp Ghost.h Terran.o Entity.o
	$(CXX) $(CXXFLAGS)  -c Ghost.cpp

Battlecruiser.o: Battlecruiser.cpp Battlecruiser.h Terran.o Entity.o
	$(CXX) $(CXXFLAGS)  -c Battlecruiser.cpp

run1:
	./proj4 proj4_map1.txt

val1:
	valgrind ./proj4 proj4_map1.txt

run2:
	./proj4 proj4_map2.txt

val2:
	valgrind ./proj4 proj4_map2.txt
