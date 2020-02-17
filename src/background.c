/*
** EPITECH PROJECT, 2019
** Hunter2.0
** File description:
** background.c
*/

#include "game.h"
#include "prototypes.h"
#include "include.h"

void init_background(game_t *game)
{
    game->backgroundtxt = sfTexture_createFromFile("assets/Image/bpng.jpg",
    NULL);
    game->backgroundspr = sfSprite_create();
    sfSprite_setTexture(game->backgroundspr, game->backgroundtxt, sfTrue);
    game->cursortxt = sfTexture_createFromFile("assets/Image/cursor.png",
    NULL);
    game->cursorspr = sfSprite_create();
    sfSprite_setTexture(game->cursorspr, game->cursortxt, sfTrue);
}