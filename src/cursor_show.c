/*
** EPITECH PROJECT, 2019
** Hunter2.0
** File description:
** cursor_show.c
*/

#include "game.h"
#include "prototypes.h"
#include "include.h"

void cursor_show(game_t *game)
{
    sfVector2f position;
    sfVector2i mouse_pos;

    mouse_pos = sfMouse_getPositionRenderWindow(game->window);
    position.x = mouse_pos.x - 100;
    position.y = mouse_pos.y - 100;
    sfSprite_setPosition(game->cursorspr, position);
}