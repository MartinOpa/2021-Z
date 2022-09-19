#include "stage.h"

static void logic(void);
static void draw(void);
static void drawHud(void);

void initStage(void)
{
	app.delegate.logic = logic;
	app.delegate.draw = draw;
	
	memset(&stage, 0, sizeof(Stage));
	
	stage.entityTail = &stage.entityHead;
	
	initEntities();
	
	initPlayer();

	initGhosts();
	
	initMap();
}

static void logic(void)
{
	doPlayer();

	doGhosts();

	doEntities();
}

static void draw(void)
{
	SDL_SetRenderDrawColor(app.renderer, 0, 0, 0, 255);
	SDL_RenderFillRect(app.renderer, NULL);
	
	drawMap();

	drawEntities();

	drawHud();
}

static void drawHud(void)
{
	SDL_Rect r;
	
	r.x = 0;
	r.y = 0;
	r.w = SCREEN_WIDTH;
	r.h = 48;
	
	SDL_SetRenderDrawBlendMode(app.renderer, SDL_BLENDMODE_BLEND);
	SDL_SetRenderDrawColor(app.renderer, 0, 0, 0, 196);
	SDL_RenderFillRect(app.renderer, &r);
	SDL_SetRenderDrawBlendMode(app.renderer, SDL_BLENDMODE_NONE);
	
	drawText(SCREEN_WIDTH - 5, 5, 255, 255, 255, TEXT_RIGHT, "POINTS: %d", 50*stage.pointsPlayer);
	drawText(5, 5, 255, 255, 255, TEXT_LEFT, "LIVES: %d", player->health-1);
}
