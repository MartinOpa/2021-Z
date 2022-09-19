OUT = bin

SEARCHPATH += src
vpath %.c $(SEARCHPATH)
vpath %.h $(SEARCHPATH)

DEPS += defs.h structs.h

_OBJS += draw.o
_OBJS += entities.o
_OBJS += ghosts.o
_OBJS += init.o input.o io.o
_OBJS += main.o map.o
_OBJS += point.o player.o
_OBJS += stage.o
_OBJS += sound.o
_OBJS += textures.o text.o
_OBJS += util.o

OBJS = $(patsubst %,$(OUT)/%,$(_OBJS))

all: $(PROG)

$(OUT)/%.o: %.c %.h $(DEPS)
	@mkdir -p $(OUT)
	$(CC) $(CFLAGS) $(CXXFLAGS) -c -o $@ $<
	
clean:
	$(RM) -rf $(OUT) $(PROG)
