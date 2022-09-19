PROG = pacman
CC = gcc

include common.mk

CXXFLAGS += `sdl2-config --cflags`

LDFLAGS += `sdl2-config --libs` -lSDL2_mixer -lSDL2_image -lSDL2_ttf -lm

$(PROG): $(OBJS)
	$(CC) -o $@ $(OBJS) $(LDFLAGS)
