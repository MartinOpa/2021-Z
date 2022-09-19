#include "common.h"

extern void blit(SDL_Texture *texture, int x, int y, int center);
extern int collision(int x1, int y1, int w1, int h1, int x2, int y2, int w2, int h2);
extern void initPoint(char *line);
extern int isInsideMap(int x, int y);
extern SDL_Texture *loadTexture(char *filename);
extern char *readFile(const char *filename);

extern Entity *self;
extern Stage stage;
