#ifndef SPRITES_H
#define SPRITES_H


#include <SFML/Graphics.h>
#include <SFML/System/Vector2.h>


int loadResources(void);
void freeResources(void);
sfSprite* createSpriteFromTexture(sfTexture* tex);
int wasSpriteCreated(sfSprite *sprite, sfRenderWindow *window);
sfTexture* getExampleTexture();


#endif