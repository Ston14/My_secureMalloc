CC = GCC
EXE = secmalloc

PI = include
PH = header
SOURCE += include/cache.c include/my_memmap.c include/my_secmalloc

EXE_TEST = test
PT = test

.PHONY: all main test clean
all: main test

test:
	@echo "test is building"
	$(CC) -lcriterion test/my_secmalloc_is_working.c $(SOURCE) -o $(PT)/$(ET)
	@echo "building done"
	@-./test/my_secmalloc_is_working.c
main:
	@echo "main is building"
	$(CC) -lcriterio test/main.c $(SOURCE) -o $(PT)/$(ET)
	@echo "building done"
	@-./test/my_secmalloc_is_working.c
clean:
	@echo "Clean is building")
	@rm $(PT)/$(EXE)
	@echo "je suis une merde"