all: task

task: *.o 
	g++ $^ -o $@

%.o: %.cpp
	g++ -g -pedantic -c $^

run: 
	./task

clean:
	rm *.o task

	