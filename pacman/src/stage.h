#include "common.h"

extern void doEntities(void);
extern void doPlayer(void);
extern void doGhosts(void);
extern void drawEntities(void);
extern void drawMap(void);
extern void drawText(int x, int y, int r, int g, int b, int align, char *format, ...);
extern void initEntities(void);
extern void initMap(void);
extern void initPlayer(void);
extern void initGhosts(void);

extern App app;
extern Entity *player;
extern Entity *blinky;
extern Entity *clyde;
extern Entity *inky;
extern Entity *pinky;
extern Stage stage;
