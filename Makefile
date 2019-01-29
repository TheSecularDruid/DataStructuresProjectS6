SET_DIR=set
SEN_DIR=sentinel

BIN=sentinel_struc 
#sentinel_func

CC=cc
CPPFLAGS=-I ${SET_DIR} -I ${SEN_DIR}
CFLAGS=-Wall -Wextra -std=c99

.PHONY: all test build clean

all: build test

build: ${BIN}

test: build
	@for e in ${BIN}; do \
	echo $${e}; ./$${e}; \
	done

clean:
	rm -f *.o ${BIN}

#sentinel
set_sentinel.o: ${SEN_DIR}/set_sentinel.c ${SEN_DIR}/set_sentinel.h
	${CC} ${CPPFLAGS} ${CFLAGS} ${SEN_DIR}/set_sentinel.c -c

test_sentinel_struc.o: ${SEN_DIR}/test_sentinel_struc.c ${SEN_DIR}/set_sentinel.h
	${CC} ${CPPFLAGS} ${CFLAGS} ${SEN_DIR}/test_sentinel_struc.c -c

sentinel_struc: test_sentinel_struc.o set_sentinel.o
	${CC} test_sentinel_struc.o set_sentinel.o -o $@

#pour l'exercice 12
test_sentinel_func.o: ${SET_DIR}/test_set_func.c ${SEN_DIR}/set_sentinel.h
	${CC} ${CPPFLAGS} ${CFLAGS} -DSENTINEL ${SET_DIR}/test_set_func.c -c -o $@

sentinel_func: test_sentinel_func.o set_sentinel.o
	${CC} test_sentinel_func.o set_sentinel.o -o $@

#dynamic

#link
link.o : link/link.c link/link.h
	${CC} ${CPPFLAGS} ${CFLAGS} link/link.c -ggdb -c
test_link_struc.o : link/link.c link/link.h link/test_link_struc.c
	${CC} ${CPPFLAGS} ${CFLAGS} link/test_link_struc.c -ggdb -c
test_link : link.o test_link_struc.o
	${CC} ${CPPFLAGS} ${CFLAGS} link.o test_link_struc.o -o test_link
