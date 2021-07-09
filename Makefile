main:
	@gcc -I. caesar.c main.c -o main

test: main
	./main

.PHONY: clean
clean:
	rm -f main
