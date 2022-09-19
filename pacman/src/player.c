#include "player.h"

static void tick(void);
static void touch(Entity *other);

static SDL_Texture *pacman[16];
static void loadPlayer(void);

void initPlayer(void)
{
	player = malloc(sizeof(Entity));
	memset(player, 0, sizeof(Entity));
	stage.entityTail->next = player;
	stage.entityTail = player;
	player->health = 4;
	
	loadPlayer();
	
	player->texture = pacman[0];
	
	player->x = (MAP_WIDTH/2)*(TILE_SIZE-0.5);
	player->y = 26*TILE_SIZE;

	SDL_QueryTexture(player->texture, NULL, NULL, &player->w, &player->h);
	player->w = player->w-2;
	player->h = player->h-2;
}

void doPlayer(void)
{	
	player->dx = 0;
	player->dy = 0;

	if (app.keyboard[SDL_SCANCODE_A] || app.keyboard[SDL_SCANCODE_LEFT])
	{
		player->dx = -PLAYER_MOVE_SPEED;

		player->texture = pacman[3];
	}
	
	if (app.keyboard[SDL_SCANCODE_D] || app.keyboard[SDL_SCANCODE_RIGHT])
	{
		player->dx = PLAYER_MOVE_SPEED;
		
		player->texture = pacman[1];
	}
	
	if (app.keyboard[SDL_SCANCODE_W] || app.keyboard[SDL_SCANCODE_UP])
	{
		player->dy = -PLAYER_MOVE_SPEED;

		player->texture = pacman[4];
	}

	if (app.keyboard[SDL_SCANCODE_S] || app.keyboard[SDL_SCANCODE_DOWN])
	{
		player->dy = PLAYER_MOVE_SPEED;

		player->texture = pacman[2];
	}
}

static void loadPlayer(void)
{
	int i;
	char filename[MAX_FILENAME_LENGTH];

	for (i = 0 ; i < MAX_SPRITES ; i++)
	{
		sprintf(filename, "gfx/pacman%d.png", i);

		pacman[i] = loadTexture(filename);
	}
}