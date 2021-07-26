TARGET	:= SocketException
SRCS	:= $(TARGET).cpp
OBJS	:= $(TARGET).o

CC		:= g++
CFLAGS	:= -c
DEPS	:= $(TARGET).h

all: $(OBJS)

%.o: %.cpp $(DEPS)
	$(CC) $^ $(CFLAGS)

clean:
	rm -f $(OBJS) $(TARGET).h.gch