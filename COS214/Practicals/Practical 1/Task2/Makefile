all: client

client: *.o
	g++ $^ -o $@

%.o: %.cpp
	g++ -g -W -Wall -Wextra -c $^

run:
	./client

clean:
	rm *.o client