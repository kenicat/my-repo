TARGET	:= App
SRCS	:= $(TARGET).cpp
OBJS	:= $(TARGET).o

CC		:= g++
CFLAGS	:= -c
DEPS	:= $(TARGET).h

all: $(OBJS)

%.o: %.cpp $(DEPS)
	$(CC) -pthread $^ $(CFLAGS)

clean:
	rm -f $(OBJS) $(TARGET).h.gch