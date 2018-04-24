CFLAGS=-Wall -Werror -pedantic -ggdb -O0 -std=c++98 -Iproduct

SOURCES=$(wildcard *.cpp)
HEADERS=$(wildcard *.h)

CC=g++

.phony: all clean

all: SocketClient

SocketClient: $(SOURCES) $(HEADERS) Makefile
	@$(CC) $(CFLAGS_NORMAL) $(SOURCES) -o $@
	@scp  SocketClient pi@10.0.0.6:/home/pi/Desktop

clean:
	@rm -rf SocketClient
