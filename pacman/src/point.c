#include "point.h"

static void tick(void);
static void touch(Entity *other);

void initPoint(char *line)
{
	Entity *e;
	
	e = malloc(sizeof(Entity));
	memset(e, 0, sizeof(Entity));
	stage.entityTail->next = e;
	stage.entityTail = e;
	
	sscanf(line, "%*s %f %f", &e->x, &e->y);
	
	e->health = 1;
		
	e->texture = loadTexture("gfx/point.png");
	SDL_QueryTexture(e->texture, NULL, NULL, &e->w, &e->h);
	e->touch = touch;
	
	stage.pointsTotal++;
}

static void touch(Entity *other)
{
	if (self->health > 0 && other == player)
	{
		self->health = 0;
		
		stage.pointsPlayer++;
		
		if (stage.pointsPlayer == stage.pointsTotal)
		{
			playSound(SND_VICTORY, CH_PLAYER);
			player->x = SCREEN_WIDTH/2;
			player->y = SCREEN_HEIGHT/2;
		}
		else
		{
			playSound(SND_POINT, CH_PLAYER);
			player->texture = loadTexture("gfx/pacman0.png");
		}
	}
}
