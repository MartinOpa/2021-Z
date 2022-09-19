#define MIN(a,b) (((a)<(b))?(a):(b))
#define MAX(a,b) (((a)>(b))?(a):(b))
#define STRNCPY(dest, src, n) strncpy(dest, src, n); dest[n - 1] = '\0'

#define SCREEN_WIDTH           448
#define SCREEN_HEIGHT          572

#define MAX_TILES              3
#define MAX_SPRITES            5
#define MAX_GHOSTS             4

#define TILE_SIZE              16

#define MAP_WIDTH              28
#define MAP_HEIGHT             36

#define MAP_RENDER_WIDTH       28
#define MAP_RENDER_HEIGHT      36

#define PLAYER_MOVE_SPEED      4
#define PINKY_MOVE_SPEED       4
#define INKY_MOVE_SPEED        2.8
#define BLINKY_MOVE_SPEED      3.6
#define CLYDE_MOVE_SPEED       4
#define MAX_FRAMES             3

#define MAX_NAME_LENGTH        32
#define MAX_LINE_LENGTH        1024
#define MAX_FILENAME_LENGTH    1024

#define MAX_KEYBOARD_KEYS      350

#define MAX_SND_CHANNELS       16
#define EF_SOLID               (2 << 1)

#define GLYPH_WIDTH            18
#define GLYPH_HEIGHT           29

enum
{
	TEXT_LEFT,
	TEXT_CENTER,
	TEXT_RIGHT
};

enum
{
	SND_DEATH,
	SND_POINT,
	SND_VICTORY,
	SND_DEFEAT,
	SND_MAX
};

enum
{
	CH_PLAYER,
	CH_POINT
};
