OBJS := src/App/App.cpp src/AppC/AppC.cpp src/AppS/AppS.cpp src/exception/SocketException.cpp src/TCPSocket/TCPSocket.cpp src/client/Client.cpp src/server/Server.cpp

CC		:= g++
CFLAGS	:=

all: client server

client: $(OBJS)
	$(CC) -pthread $(OBJS) mainc.cpp -o $@

server: $(OBJS)
	$(CC) -pthread $(OBJS) mains.cpp -o $@

clean:
	rm -f client server