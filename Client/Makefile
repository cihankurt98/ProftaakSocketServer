CFLAGS=-Wall -Werror -pedantic -ggdb -O0 -std=c++98 -Iproduct

SOURCES=$(wildcard *.cpp)
HEADERS=$(wildcard *.h)

#CC=arm-linux-gnueabihf-g++
CC=g++

.phony: all clean

all: SocketClient

SocketClient: $(SOURCES) $(HEADERS) Makefile
	@$(CC) $(CFLAGS_NORMAL) $(SOURCES) -o $@


clean:
	@rm -rf SocketClient
