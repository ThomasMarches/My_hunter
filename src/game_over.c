/*
** EPITECH PROJECT, 2019
** Hunter2.0
** File description:
** launch.c
*/

#include "game.h"
#include "prototypes.h"
#include "include.h"

void score_check(game_t *game)
{
    if (game->score > my_getnbr(game->biggest_score)) {
        set_biggest_score(game);
        sfText_setString(game->text.text_biggest_score,
        digit_to_char(game->score));
    }
}

void show_score_end(game_t *game)
{
    sfText_setCharacterSize(game->text.text_score, 80);
    sfText_setCharacterSize(game->text.text, 80);
    sfText_setCharacterSize(game->text.text_biggest_score, 80);
    game->text.text_position.x = 560;
    game->text.text_position.y = 100;
    game->text.text_position_score.x = 1200;
    game->text.text_position_score.y = 100;
    game->text.text_position_biggest_score.x = 1270;
    game->text.text_position_biggest_score.y = 180;
    sfText_setPosition(game->text.text, game->text.text_position);
    sfText_setPosition(game->text.text_score,
    game->text.text_position_score);
    sfText_setPosition(game->text.text_biggest_score,
    game->text.text_position_biggest_score);
    score_check(game);
    sfRenderWindow_drawText(game->window, game->text.text, NULL);
    sfRenderWindow_drawText(game->window, game->text.text_score, NULL);
    sfRenderWindow_drawText(game->window, game->text.text_biggest_score, NULL);
}

int clock_game_over(game_t *game, game_over_t game_over)
{
    float seconds;
    sfEvent event;

    while (sfRenderWindow_pollEvent(game->window, &event))
        if (event.type == sfEvtClosed)
            sfRenderWindow_close(game->window);
    sfRenderWindow_clear(game->window, sfBlack);
    sfRenderWindow_drawSprite(game->window, game_over.spr, NULL);
    show_score_end(game);
    sfRenderWindow_display(game->window);
    game_over.time = sfClock_getElapsedTime(game_over.clock);
    seconds = game_over.time.microseconds / 1000000.0;
    if (seconds > 5.0) {
        sfClock_destroy(game_over.clock);
        return (1);
    }
    return (0);
}

void game_over(game_t *game)
{
    int opened = 0;
    game_over_t game_over;
    game_over.clock = sfClock_create();
    game_over.time = sfClock_getElapsedTime(game_over.clock);
    game_over.txt = sfTexture_createFromFile("assets/Image/go.png", NULL);
    game_over.spr = sfSprite_create();

    sfMusic_play(game->music.game_over);
    sfSprite_setTexture(game_over.spr, game_over.txt, sfTrue);
    sfRenderWindow_clear(game->window, sfBlack);
    while (sfRenderWindow_isOpen(game->window) && opened == 0) {
        opened = clock_game_over(game, game_over);
    }
    sfRenderWindow_clear(game->window, sfBlack);
    sfSprite_destroy(game_over.spr);
    sfTexture_destroy(game_over.txt);
    sfRenderWindow_close(game->window);
}