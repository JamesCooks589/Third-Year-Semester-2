all: Window

Window: main.o factory.o openGLFactory.o openGLPrimitive.o openGLWindow.o primitive.o vulkanFactory.o vulkanPrimitive.o vulkanWindow.o Window.o
	g++ $^ -o $@

%.o: %.cpp
	g++ -g -W -Wall -Wextra -c $^

run:
	./Window

clean:
	rm *.o Window

