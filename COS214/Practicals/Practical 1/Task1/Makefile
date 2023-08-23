all: ship

ship: *.o
	g++ $^ -o $@

%.o: %.cpp
	g++ -g -W -Wall -Wextra -c $^

run:
	./ship

clean:
	rm *.o ship