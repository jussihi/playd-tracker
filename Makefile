CPP      = g++
OBJ      =main.o GUI.o
LINKOBJ  =main.o GUI.o
LIBS     =`pkg-config ncurses --libs`
CXXFLAGS =-std=c++14 -Wall -g -c `pkg-config ncurses --libs`
BIN	 = playd-tracker

.PHONY: all all-before all-after clean clean-custom

all: all-before $(BIN) all-after

$(BIN): $(OBJ)
	$(CPP) $(LINKOBJ) -o $(BIN) $(LIBS)

./%.o: ./%.cpp
	$(CPP) $(CXXFLAGS) $< -o $@

.PHONY : clean
clean : 
	-rm *.o $(BIN)

