#include "common.h"

extern void cleanup(void);
extern void doInput(void);
extern void initGame(void);
extern void initSDL(void);
extern void initStage(void);
extern void prepareScene(void);
extern void presentScene(void);

App app;
Entity *player;
Entity *blinky;
Entity *clyde;
Entity *inky;
Entity *pinky;
Entity *self;
Stage stage;
