#include <SFML/Audio.h>
#include <math.h>
#include <stdlib.h>


// Create sfSound* object
sfSound* createSFX(char path[], int volume){
    sfSoundBuffer *sfx = sfSoundBuffer_createFromFile(path);
    sfSound *sound = sfSound_create();
    if (volume > 100) volume = 100;
    if (volume < 0) volume = 0;
    sfSound_setVolume(sound, volume);
    sfSound_setBuffer(sound, sfx);
    return sound;
}

// TODO: Make sure a song can't play again if it already played before

// Create sfMusic* object
sfMusic* createMusic(char path[], int volume){
    sfMusic* music = sfMusic_createFromFile(path);
    if (volume > 100) volume = 100;
    if (volume < 0) volume = 0;
    sfMusic_setVolume(music, volume);
    return music;
}


sfBool hasMusicStoppedPlaying(sfMusic* music){
    if (sfMusic_getStatus(music) == sfStopped){
        return sfTrue;
    } return sfFalse;
}