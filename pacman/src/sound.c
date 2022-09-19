#include "sound.h"

static void loadSounds(void);

static Mix_Chunk *sounds[SND_MAX];

void initSounds(void)
{
	memset(sounds, 0, sizeof(Mix_Chunk*) * SND_MAX);
	
	loadSounds();
}

void playSound(int id, int channel)
{
	Mix_PlayChannel(channel, sounds[id], 0);
}

static void loadSounds(void)
{
	sounds[SND_DEATH] = Mix_LoadWAV("sound/death.mp3");
	sounds[SND_POINT] = Mix_LoadWAV("sound/point.mp3");
	sounds[SND_VICTORY] = Mix_LoadWAV("sound/victory.mp3");
	sounds[SND_DEFEAT] = Mix_LoadWAV("sound/defeat.mp3");
}
