CC := g++
CFLAGS := -O3 -Wall
TARGET := main
SRCS := $(wildcard *.cpp)
HEADERS := $(wildcard *.h)
OBJS := $(patsubst %.cpp, %.o, $(SRCS))
.PHONY:clean

all:$(TARGET)

$(TARGET):$(OBJS)
	$(CC) $(CFLAGS) $^ -o $@

%.o:%.cpp $(HEADERS)
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm $(TARGET) $(OBJS)
