CFLAGS=-Wall -Werror -pedantic -ggdb -O0 -Iproduct 

SOURCES=$(wildcard *.cpp)
HEADERS=$(wildcard *.h)

#CC=arm-linux-gnueabihf-g++
CC=g++

.phony: all clean

all: SocketServer

SocketServer: $(SOURCES) $(HEADERS) Makefile
	@$(CC) -std=c++11  $(CFLAGS_NORMAL) $(SOURCES) -o $@ -pthread
#	@ scp SocketServer pi@10.0.0.4:/home/pi/Desktop

clean:
	@rm -rf SocketServer
