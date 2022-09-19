#include "ghosts.h"

static void touchGhost(Entity *other);
static SDL_Texture *ghosts[4];
void doGhosts(void);

void doGhosts(void)
{	
	if (blinky->x > player->x)
	{
		blinky->dx = -BLINKY_MOVE_SPEED;
	}
	if (blinky->y > player->y)
	{
		blinky->dy = -BLINKY_MOVE_SPEED;
	}
	if (blinky->x < player->x)
	{
		blinky->dx = BLINKY_MOVE_SPEED;
	}
	if (blinky->y < player->y)
	{
		blinky->dy = BLINKY_MOVE_SPEED;
	}

	if (inky->x > player->x)
	{
		inky->dx = -INKY_MOVE_SPEED;
	}
	if (inky->y > player->y)
	{
		inky->dy = -INKY_MOVE_SPEED;
	}
	if (inky->x < player->x)
	{
		inky->dx = INKY_MOVE_SPEED;
	}
	if (inky->y < player->y)
	{
		inky->dy = INKY_MOVE_SPEED;
	}

	if (clyde->dx == 0 && clyde->dy == 0)
	{
		clyde->dx = ((rand() % (2 + 1 - 0) + 0)-1)*CLYDE_MOVE_SPEED;
		clyde->dy = ((rand() % (2 + 1 - 0) + 0)-1)*CLYDE_MOVE_SPEED;
	}	

	if (pinky->dx == 0 && pinky->dy == 0)
	{
		pinky->dx = ((rand() % (2 + 1 - 0) + 0)-1)*PINKY_MOVE_SPEED;
		pinky->dy = ((rand() % (2 + 1 - 0) + 0)-1)*PINKY_MOVE_SPEED;
	}			
}

void initGhosts(void)
{
	blinky = malloc(sizeof(Entity));
	memset(blinky, 0, sizeof(Entity));
	stage.entityTail->next = blinky;
	stage.entityTail = blinky;
	blinky->health = 1;
	blinky->touch = touchGhost;

	ghosts[0] = loadTexture("gfx/ghost0.png");
	blinky->texture = ghosts[0];

	clyde = malloc(sizeof(Entity));
	memset(clyde, 0, sizeof(Entity));
	stage.entityTail->next = clyde;
	stage.entityTail = clyde;
	clyde->health = 1;
	clyde->touch = touchGhost;
	
	ghosts[1] = loadTexture("gfx/ghost1.png");
	clyde->texture = ghosts[1];

	inky = malloc(sizeof(Entity));
	memset(inky, 0, sizeof(Entity));
	stage.entityTail->next = inky;
	stage.entityTail = inky;
	inky->health = 1;
	inky->touch = touchGhost;
	
	ghosts[2] = loadTexture("gfx/ghost2.png");
	inky->texture = ghosts[2];

	pinky = malloc(sizeof(Entity));
	memset(pinky, 0, sizeof(Entity));
	stage.entityTail->next = pinky;
	stage.entityTail = pinky;
	pinky->health = 1;
	pinky->touch = touchGhost;
	
	ghosts[3] = loadTexture("gfx/ghost3.png");
	pinky->texture = ghosts[3];
	
	blinky->x = 6*TILE_SIZE;
	blinky->y = 11*TILE_SIZE;
		
	inky->x = 21*TILE_SIZE;
	inky->y = 29*TILE_SIZE;
		
	clyde->x = 21*TILE_SIZE;
	clyde->y = 11*TILE_SIZE;
		
	pinky->x = 6*TILE_SIZE;
	pinky->y = 29*TILE_SIZE;

	SDL_QueryTexture(blinky->texture, NULL, NULL, &blinky->w, &blinky->h);
	SDL_QueryTexture(clyde->texture, NULL, NULL, &clyde->w, &clyde->h);
	SDL_QueryTexture(inky->texture, NULL, NULL, &inky->w, &inky->h);
	SDL_QueryTexture(pinky->texture, NULL, NULL, &pinky->w, &pinky->h);
	blinky->w = blinky->w-2;
	blinky->h = blinky->h-2;
	clyde->w = clyde->w-2;
	clyde->h = clyde->h-2;
	inky->w = inky->w-2;
	inky->h = inky->h-2;
	pinky->w = pinky->w-2;
	pinky->h = pinky->h-2;
}

static void touchGhost(Entity *other)
{
	if (blinky->health > 0 && other == player ||
		pinky->health > 0 && other == player ||
		inky->health > 0 && other == player ||
		clyde->health > 0 && other == player)
	{
		player->health = player->health - 1;
		playSound(SND_DEATH, CH_PLAYER);
		SDL_Delay(3000);

		if (player->health <= 1)
		{
			player->x = SCREEN_WIDTH/2;
			player->y = SCREEN_HEIGHT/2;
			playSound(SND_DEFEAT, CH_PLAYER);
		}
		else
		{
		blinky->x = 6*TILE_SIZE;
		blinky->y = 11*TILE_SIZE;
		blinky->dx = 0;
		blinky->dy = 0;
		
		clyde->x = 21*TILE_SIZE;
		clyde->y = 11*TILE_SIZE;
		clyde->dx = 0;
		clyde->dy = 0;
		
		inky->x = 21*TILE_SIZE;
		inky->y = 29*TILE_SIZE;
		inky->dx = 0;
		inky->dy = 0;

		pinky->x = 6*TILE_SIZE;
		pinky->y = 29*TILE_SIZE;
		pinky->dx = 0;
		pinky->dy = 0;

		player->x = (MAP_WIDTH/2)*(TILE_SIZE-0.5);
		player->y = 26*TILE_SIZE;
		player->dx = 0;
		player->dy = 0;
		}
	}
}