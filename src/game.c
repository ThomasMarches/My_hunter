/*
** EPITECH PROJECT, 2019
** Hunter2.0
** File description:
** game.c
*/

#include "game.h"
#include "prototypes.h"
#include "include.h"

void init_game(game_t *game)
{
    game->window = sfRenderWindow_create((sfVideoMode){1920, 1080, 32},
    "MyHunter", sfResize | sfClose, NULL);
    sfRenderWindow_setMouseCursorVisible(game->window, false);
    sfRenderWindow_setFramerateLimit(game->window, 30);
    init_background(game);
    init_parallax(game);
    music_init(game);
    init_bullet(game);
    init_life(game);
    create_duck(game);
    mouse_init(game);
    game->score = 0;
    text_init(game);
}

void start_game(game_t *game)
{
    sfEvent event;
    sfClock *clock = sfClock_create();

    launching_game(game);
    while (sfRenderWindow_isOpen(game->window)) {
        sfRenderWindow_clear(game->window, sfBlack);
        show_sprites(game);
        while (sfRenderWindow_pollEvent(game->window, &event))
            poll_event(event, game);
        if (sfClock_getElapsedTime(clock).microseconds / 100000.0 >= 1.0) {
            move_duck_rect(game, 70, 210);
            sfClock_restart(clock);
        }
    }
}

void sprite_destroy(game_t *game)
{
    sfSprite_destroy(game->duck.sprite);
    sfSprite_destroy(game->cursorspr);
    sfSprite_destroy(game->life.lifespr);
    sfSprite_destroy(game->bullet.bulletspr);
    sfSprite_destroy(game->backgroundspr);
}

void texture_destroy(game_t *game)
{
    sfTexture_destroy(game->duck.texture);
    sfTexture_destroy(game->backgroundtxt);
    sfTexture_destroy(game->cursortxt);
    sfTexture_destroy(game->life.lifetxt);
    sfTexture_destroy(game->bullet.bullettxt);
}

void destroy_game(game_t *game)
{
    sfRenderWindow_destroy(game->window);
    paralax_destroy(game);
    texture_destroy(game);
    sprite_destroy(game);
    sfText_destroy(game->text.text);
    sfText_destroy(game->text.text_score);
    sfText_destroy(game->text.text_biggest_score);
    sfMusic_destroy(game->music.shot);
    sfMusic_destroy(game->music.game_over);
    sfMusic_destroy(game->music.game_music);
    free(game);
}