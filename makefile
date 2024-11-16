main: src/*
	gcc src/main.c -o main

clean: main
	rm main