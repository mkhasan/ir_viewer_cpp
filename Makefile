APP := main

CC := gcc

TARGET := bin/main

OBJ := obj/${APP}.o obj/ir_viewer.o

.PHONY: all
all: build
build: ${TARGET}

${TARGET}: ${OBJ}
	${CC} ${CFLAGE} $^ ${LDFLAGS} -o $@
	
obj/%.o: src/%.c src/*.h
	${CC} -c ${CFLAGS} -o $@ $<
	
.PHONY: clean
clean:
	rm obj/*.o bin/* -rf 