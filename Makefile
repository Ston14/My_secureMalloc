CC = gcc

CFLAGS = -Werror -Wall -pedantic -std=gnu99 -I./include
TEST_LDFLAGS= -lcriterion

EXE = secmalloc
EXE_TEST = oupsi

SOURCE = src/cache.c \
         src/my_memmap.c \
         src/my_secmalloc.c

COVERAGE = $(SOURCE:.c=.gcda) \
           $(SOURCE:.c=.gcno) \
           $(TEST_SOURCE:.c=.gcno) \
           $(TEST_SOURCE:.c=.gcda)


TEST_SOURCE = ./test/main.c

OBJ=$(SOURCE:.c=.o)
TEST_OBJ=  $(TEST_SOURCE:.c=.o)

all: static dynamic test

static:	$(OBJ)
	ar rcs $(EXE).a $(OBJ)

dynamic: $(OBJ)
	$(CC) -shared -o $(EXE).so $(OBJ)

test: CFLAGS += --coverage
test: $(TEST_OBJ) $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) $(TEST_OBJ) -o $(EXE_TEST) $(TEST_LDFLAGS)
	./$(EXE_TEST)
	gcovr --exclude test

clean:
	rm -f $(OBJ)
	rm -f $(COVERAGE)

fclean: clean
	rm -f $(EXE).so
	rm -f $(EXE).a
	rm -f $(TEST_EXE)

re: fclean all


.PHONY: all static clean dynamic fclean re test