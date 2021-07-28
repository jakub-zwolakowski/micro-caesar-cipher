main: caesar.h caesar.c main.c
	@gcc -I. caesar.c main.c -o main

.PHONY: test
test: main
	./main

.PHONY: valgrind
valgrind: main
	valgrind --leak-check=yes ./main

main.UBSan-out: caesar.h caesar.c main.c
	clang -fsanitize=undefined -Wno-main-return-type -I. caesar.c main.c -o main.UBSan-out

.PHONY: main.UBSan-run
main.UBSan-run: main.UBSan-out
	./main.UBSan-out

ubsan: main.UBSan-run

.PHONY: clean
clean:
	rm -f main
	rm -f main.UBSan-out
