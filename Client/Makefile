CFLAGS=-Wall -Werror -pedantic -ggdb -O0 -std=c++11 -Iproduct 

SOURCES=$(wildcard *.cpp)
HEADERS=$(wildcard *.h)

#CC=arm-linux-gnueabihf-g++
CC=g++

.phony: all clean

all: SocketClient

SocketClient: $(SOURCES) $(HEADERS) Makefile
	@$(CC) $(CFLAGS_NORMAL) $(SOURCES) -o $@ -lpthread
#	@ scp SocketClient pi@10.0.0.8:/home/pi/Desktop
#	@ scp SocketClient pi@10.0.0.6:/home/pi/Desktop

clean:
	@rm -rf SocketClient
