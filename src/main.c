// System imports
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

// Library imports
#include <SFML/Graphics.h>
#include <SFML/System/Vector2.h>
#include <SFML/Window/VideoMode.h>
#include <SFML/Audio.h>

// Custom imports
#include "../headers/graphics/color.h"
#include "../headers/graphics/window.h"
#include "../headers/core/time.h"
#include "../headers/entities/sprites.h"
#include "../headers/audio/sound.h"

// --- Prototypes --- Will move into proper files later
void update(sfSprite* player, sfRenderWindow* window);


// --- Main ---
int main() {
    // --- SFML setup ---
    sfRenderWindow* window;
    sfEvent event;

    // --- Create window ---
    window = sfRenderWindow_create(getMode(), "window", sfResize | sfClose, NULL);
    if (!window) return 1;

    if (!loadResources()) {
        sfRenderWindow_destroy(window);
        return 1;
    }

    // Setup window 
    sfRenderWindow_setFramerateLimit(window, 60);

    // --- Sprites ---
    sfSprite* example = createSpriteFromTexture(getExampleTexture());
    
    // Make sure sprites were created properly 
    wasSpriteCreated(example, window);
    sfVector2f examplePos = {400.f, 300.f};
    // Player setup
    sfSprite_setPosition(example, examplePos);
    sfFloatRect pbounds = sfSprite_getLocalBounds(example);
    sfSprite_setOrigin(example, (sfVector2f){pbounds.width / 2, pbounds.height / 2});

    // Sound and music setup
    // TODO: Add check to make sure these are created
    sfSound *examplefx            = createSFX("./assets/sound/exampleSFX.mp3", 40);
    sfMusic *music              = NULL;


    // Game loop
    while (sfRenderWindow_isOpen(window)) {
        float deltaTime = restartDeltaTime();   
        
        // Music handling
        if (hasMusicStoppedPlaying(music) || music == NULL){
            if (music != NULL) sfMusic_destroy(music);
            music = createMusic("./assets/music/exampleMusic.mp3", 30);
            sfMusic_play(music);
        }

        // Process events
        while (sfRenderWindow_pollEvent(window, &event)) {
            if (event.type == sfEvtClosed) sfRenderWindow_close(window);          
        }

        // Update window
        update(example, window);
    }

    // Cleanup - Divided by ownership
    sfSound_destroy(examplefx);
    sfSprite_destroy(example);
    sfMusic_destroy(music);

    freeResources();
    
    sfRenderWindow_destroy(window);
    sfClock_destroy(getClock());

    return 0;
}

// --- Functions ---

// Draw, render and handle display
void update(sfSprite* player, sfRenderWindow* window) {
    sfRenderWindow_clear(window, sfTurqoise());
    if (player)
        sfRenderWindow_drawSprite(window, player, NULL);

    sfRenderWindow_display(window);
}
