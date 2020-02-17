/*
** EPITECH PROJECT, 2019
** Hunter2.0 (copy)
** File description:
** life.c
*/

#include "game.h"
#include "prototypes.h"
#include "include.h"

void init_life(game_t *game)
{
    game->life.nb_life = 3;
    game->life.life_pos.x = 1300;
    game->life.life_pos.y = 25;
    game->life.lifetxt = sfTexture_createFromFile("assets/Image/life.png",
    NULL);
    game->life.lifespr = sfSprite_create();
    sfSprite_setTexture(game->life.lifespr, game->life.lifetxt, sfTrue);
    game->life.life_rect.top = 0;
    game->life.life_rect.left = 0;
    game->life.life_rect.width = 600;
    game->life.life_rect.height = 141;
    sfSprite_setPosition(game->life.lifespr, game->life.life_pos);
}