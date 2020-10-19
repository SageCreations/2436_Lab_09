CXX = g++
#CXXFLAGS = -Wall -Werror -Wextra -pedantic -std=c++17 -g -fsanitize=address
CXXFLAGS =  -pedantic -std=c++17 -g 
#CXXFLAGS = -Wall -Werror -Wextra -pedantic -std=c++17 -g
#LDFLAGS =  -fsanitize=address

SRC =  $(wildcard *.cpp)
OBJ = $(SRC:.cpp=.o)
EXEC = testDVDStore

all: $(EXEC)

$(EXEC): $(OBJ)
	$(CXX) $(LDFLAGS) -o $@ $(OBJ) $(LBLIBS)

clean:
	rm -rf $(OBJ) $(EXEC)
