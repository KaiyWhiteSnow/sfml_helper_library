#include <SFML/Graphics.h>
#include <stdio.h>


sfTexture* exampleTexture = NULL;

int loadResources(void){
    exampleTexture = sfTexture_createFromFile("./assets/sprites/example.png", NULL);
    if (!exampleTexture) {
        fprintf(stderr, "Failed to load example texture\n");
        return 0;
    }

    return 1;
}

// Free on application finish
void freeResources(void) {
    if (exampleTexture) { sfTexture_destroy(exampleTexture); exampleTexture = NULL; }
}

// Create a sprite from an already-loaded texture (returns NULL on failure)
sfSprite* createSpriteFromTexture(sfTexture* tex) {
    if (!tex) return NULL;
    sfSprite* s = sfSprite_create();
    if (!s) return NULL;
    sfSprite_setTexture(s, tex, sfTrue); 
    return s;
}

// Check if sprite was created
// Returns 1 on failed to create sprite
// Returns 0 on sprite created
int wasSpriteCreated(sfSprite *sprite, sfRenderWindow *window){
    if (!sprite) {
        fprintf(stderr, "Failed to create sprite\n");
        freeResources();
        sfRenderWindow_destroy(window);
        return 1;
    }
    return 0;
}

// Getters for textures
sfTexture* getExampleTexture() { return exampleTexture; }
