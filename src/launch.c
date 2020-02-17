/*
** EPITECH PROJECT, 2019
** Hunter2.0
** File description:
** launch.c
*/

#include "game.h"
#include "prototypes.h"
#include "include.h"

int clock_launching_game(game_t *game, launch_t l_game)
{
    float seconds;
    sfEvent event;

    while (sfRenderWindow_pollEvent(game->window, &event))
        if (event.type == sfEvtClosed)
            sfRenderWindow_close(game->window);
    sfRenderWindow_drawSprite(game->window, l_game.launch_spr, NULL);
    sfRenderWindow_display(game->window);
    l_game.launching_t = sfClock_getElapsedTime(l_game.launch_clock);
    seconds = l_game.launching_t.microseconds / 1000000.0;
    if (seconds > 8.0) {
        sfClock_destroy(l_game.launch_clock);
        return (1);
    }
    sfRenderWindow_clear(game->window, sfBlack);
    return (0);
}

void launching_game(game_t *game)
{
    int opened = 0;
    launch_t l_game;
    l_game.launch_clock = sfClock_create();
    l_game.launching_t = sfClock_getElapsedTime(l_game.launch_clock);
    l_game.launch_txt = sfTexture_createFromFile("assets/Image/l.jpg", NULL);
    l_game.launch_spr = sfSprite_create();
    sfMusic_play(game->music.background);
    sfSprite_setTexture(l_game.launch_spr, l_game.launch_txt, sfTrue);
    sfRenderWindow_clear(game->window, sfBlack);
    while (sfRenderWindow_isOpen(game->window) && opened == 0) {
        opened = clock_launching_game(game, l_game);
    }
    sfRenderWindow_clear(game->window, sfBlack);
    sfSprite_destroy(l_game.launch_spr);
    sfTexture_destroy(l_game.launch_txt);
    sfMusic_destroy(game->music.background);
    sfMusic_play(game->music.game_music);
}