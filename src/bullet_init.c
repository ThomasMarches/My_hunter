/*
** EPITECH PROJECT, 2019
** Hunter2.0 (copy)
** File description:
** bullet_init.c
*/

#include "game.h"
#include "prototypes.h"
#include "include.h"

void init_bullet(game_t *game)
{
    game->bullet.number_of_bullet = 3;
    game->bullet.bullet_pos.x = 1300;
    game->bullet.bullet_pos.y = 800;
    game->bullet.bullettxt =
    sfTexture_createFromFile("assets/Image/bullet.png", NULL);
    game->bullet.bulletspr = sfSprite_create();
    sfSprite_setTexture(game->bullet.bulletspr, game->bullet.bullettxt,
    sfTrue);
    game->bullet.bullet_rect.top = 0;
    game->bullet.bullet_rect.left = 0;
    game->bullet.bullet_rect.width = 600;
    game->bullet.bullet_rect.height = 143;
    sfSprite_setPosition(game->bullet.bulletspr, game->bullet.bullet_pos);
}