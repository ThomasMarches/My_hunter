/*
** EPITECH PROJECT, 2019
** Hunter2.0
** File description:
** duck.c
*/

#include "game.h"
#include "prototypes.h"
#include "include.h"

void duck_spawn(game_t *game)
{
    int nb = 0;

    nb = generate_number(1, 2);
    game->duck.position.y = generate_number(0, 780);
    if (nb == 1) {
        game->duck.texture =
        sfTexture_createFromFile("assets/Image/xmasltr.png", NULL);
        game->duck.sprite = sfSprite_create();
        game->duck.position.x = 0;
        sfSprite_setPosition(game->duck.sprite, game->duck.position);
    } else {
        game->duck.texture =
        sfTexture_createFromFile("assets/Image/xmasrtl.png", NULL);
        game->duck.sprite = sfSprite_create();
        game->duck.position.x = 1920;
        sfSprite_setPosition(game->duck.sprite, game->duck.position);
    }
}

void create_duck(game_t *game)
{
    duck_spawn(game);
    game->duck_vector.x = 10 + game->duck.speed;
    game->duck_vector.y = generate_number(0, 10);
    game->rect_duck.rect.top = 0;
    game->rect_duck.rect.left = 0;
    game->rect_duck.rect.width = 70;
    game->rect_duck.rect.height = 92;
}