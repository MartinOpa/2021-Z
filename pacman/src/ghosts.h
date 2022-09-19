#include "common.h"

#include "SDL2/SDL_image.h"

extern SDL_Texture *loadTexture(char *filename);
extern void drawText(int x, int y, int r, int g, int b, int align, char *format, ...);
extern void playSound(int id, int channel);

extern App app;
extern Entity *player;
extern Entity *blinky;
extern Entity *clyde;
extern Entity *inky;
extern Entity *pinky;
extern Stage stage;