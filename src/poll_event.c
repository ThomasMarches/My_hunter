/*
** EPITECH PROJECT, 2019
** Hunter2.0
** File description:
** poll_event.c
*/

#include "game.h"
#include "prototypes.h"
#include "include.h"

void poll_event(sfEvent event, game_t *game)
{
    if (event.type == sfEvtClosed) {
        sfRenderWindow_close(game->window);
    } else if (event.type == sfEvtMouseButtonReleased)
        manage_mouse_click(game);
}