CXX = g++

CXXFLAGS = -Wall -std=c++11

SRCS = eORM.cpp newDATABASE.cpp databaseADAPTER.cpp main.cpp

OBJS = $(SRCS:.cpp=.o)

EXEC = adapter_program

all: $(EXEC)

$(EXEC): $(OBJS)
	$(CXX) $(CXXFLAGS) -o $(EXEC) $(OBJS)

%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $<

clean:
	rm -f $(OBJS) $(EXEC)
