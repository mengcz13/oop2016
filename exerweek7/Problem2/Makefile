CC := g++
CFLAGS := -O3 -Wall
TARGET := main
SRCS := $(wildcard *.cpp)
OBJS := $(patsubst %.cpp, %.o, $(SRCS))
.PHONY:clean

all:$(TARGET)

$(TARGET):$(OBJS)
	$(CC) $(CFLAGS) $^ -o $@

%.o:%.cpp %.h
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm $(TARGET) *.o
