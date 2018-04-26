CC=gcc
CFLAGS=-Wall -O -g

SOURCE=$(wildcard *.c)
OBJS=${SOURCE:.c=.o}
TARGET = boyermoore

all: $(TARGET)

$(TARGET):$(OBJS)
	$(CC) $(CFLAGS)  $^ -o $@

.PHONY: clean

clean:
	rm -rf  $(TARGET) $(OBJS) *~ core*
