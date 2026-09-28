run: build
	./main

build:
	cc -o main main.c -I/opt/homebrew/include -L/opt/homebrew/lib -lraylib \
		-framework CoreVideo -framework IOKit -framework Cocoa \
		-framework GLUT -framework OpenGL

