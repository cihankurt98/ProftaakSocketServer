CFLAGS=-Wall -Werror -pedantic -ggdb -O0 -std=c++98 -Iproduct

SOURCES=$(wildcard *.cpp)
HEADERS=$(wildcard *.h)

CC=arm-linux-g++

.phony: all clean

all: SocketServer

SocketServer: $(SOURCES) $(HEADERS) Makefile
	@$(CC) $(CFLAGS_NORMAL) $(SOURCES) -o $@
	@scp  SocketServer pi@10.0.0.3:/home/pi/Desktop

clean:
	@rm -rf SocketServer
