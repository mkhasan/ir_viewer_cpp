APP := main

CC := g++

TARGET := bin/main

OBJ := obj/${APP}.o obj/ir_viewer.o obj/CircularBuffer.o obj/Socket.o obj/Decoder.o

CFLAGS += -I${IR_VIEWER_C} -ggdb -Wall -std=c++11 $(shell pkg-config --cflags sdl)
LDFLAGS += -lpthread -lrt $(shell pkg-config --libs sdl)



.PHONY: all

all: build
build: ${TARGET}

${TARGET}: ${OBJ}
	
	${CC} ${CFLAGS} $^ ${LDFLAGS} -o $@

obj/%.o: ${IR_VIEWER_C}/%.cpp 
	${CC} -c ${CFLAGS} -o $@ $<

obj/main.o: src/main.cpp ${IR_VIEWER_C}/*.h
	${CC} -c ${CFLAGS} -o $@ $<


	
.PHONY: clean
clean:
	rm obj/*.o bin/* -rf
	
.PHONY: test
test:
	@echo ${IR_VIEWER_C} 
