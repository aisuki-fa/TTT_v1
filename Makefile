CC      = gcc
CFLAGS  = -std=c99 -Wall -O2 $(shell pkg-config --cflags raylib) -I./src -I./lib/raygui
LDLIBS  = $(shell pkg-config --libs raylib) -lm

v1: $(wildcard V1-C_Terminal/*.c)
	$(CC) $(CFLAGS) $^ -o v1

v2: $(wildcard V2-C_Graphics/*.c)
	$(CC) $(CFLAGS) $^ $(LDLIBS) -o v2

run1: v1
	./v1
run2: v2
	./v2

clean:
	rm -f v1 v1.exe v2 v2.exe

.PHONY: run1 run2 clean
