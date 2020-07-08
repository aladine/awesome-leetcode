CXX      = g++
CPPFLAGS = -Wall -std=c++11 -O2
LD_FLAGS =

FILE     = algoexpert/08-jul
# FILE     = contest/contest-195
SOURCES  = $(FILE).cpp
OBJECTS  = $(SOURCES:.cpp=.o)
	EXE  = $(FILE).out

all: $(SOURCES) $(EXE)
	 rm $(OBJECTS)

$(EXE): $(OBJECTS)
	$(CXX) $(LD_FLAGS) $(OBJECTS) -o $@

clean:
	rm $(FILE).out

run:
	./$(EXE) 

test:
	./$(EXE) < $(FILE).txt
