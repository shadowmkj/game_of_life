run: build
	./main

build:
	cc -o main main.c -I/opt/homebrew/include -L/opt/homebrew/lib -lraylib

