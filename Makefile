SRC := $(wildcard *.cpp)
CFLAGS = -I. -Wall

all: cutSphereMove

cutSphereMove: $(SRC)
	g++ -o $@ $^ $(CFLAGS)

clean:
	rm cutSphereMove
