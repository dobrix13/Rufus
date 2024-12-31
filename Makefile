CXX = g++
CXXFLAGS = -std=c++11 -Wall

SRCS = main.cpp rufus.cpp
OBJS = $(SRCS:.cpp=.o)

all: rufus

rufus: $(OBJS)
    $(CXX) $(CXXFLAGS) -o rufus $(OBJS)

main.o: main.cpp rufus.hpp Scenario.hpp Inventory.hpp rufus.hpp
    $(CXX) $(CXXFLAGS) -c main.cpp

rufus.o: rufus.cpp rufus.hpp
    $(CXX) $(CXXFLAGS) -c rufus.cpp

clean:
    rm -f rufus $(OBJS)