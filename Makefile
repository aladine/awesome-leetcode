CXX      = g++
CPPFLAGS = -Wall -std=c++11 -O2
LD_FLAGS =
LAST_MODIFIED_CXX_FILE = $(shell ls -rt */*\.cpp | tail -1)

# FILE     = algoexpert/10-jul
# FILE     = contest/contest-195
SOURCES  = $(LAST_MODIFIED_CXX_FILE)
OBJECTS  = $(SOURCES:.cpp=.o)
	EXE  = $(SOURCES:.cpp=.out)

all: $(SOURCES) $(EXE)
	 rm $(OBJECTS)

last: $(notdir $(basename $(LAST_MODIFIED_CXX_FILE)))

.PHONY: last

$(EXE): $(OBJECTS)
	$(CXX) $(LD_FLAGS) $(OBJECTS) -o $@

clean:
	rm */*.out

run:
	./$(EXE) 

test:
	./$(EXE) < input.txt
