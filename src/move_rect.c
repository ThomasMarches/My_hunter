/*
** EPITECH PROJECT, 2019
** Hunter2.0
** File description:
** duck.c
*/

#include "game.h"
#include "prototypes.h"
#include "include.h"

void check_rect(game_t *game)
{
    game->duck.present_rect = sfSprite_getGlobalBounds(game->duck.sprite);
    game->duck.present_rect.height += 20;
    game->duck.present_rect.width += 20;
    game->duck.present_rect.left += 20;
    game->duck_present = sfFloatRect_contains(&game->duck.present_rect,
    game->mouse.x, game->mouse.y);
}

void move_duck_rect(game_t *game, int offset, int max_value)
{
    if (game->rect_duck.rect.left + offset <= max_value)
        game->rect_duck.rect.left += offset;
    else
        game->rect_duck.rect.left = 0;
}

void move_life_rect(game_t *game, int offset, int max_value)
{
    if (game->life.life_rect.left + offset <= max_value)
        game->life.life_rect.left += offset;
    else
        game->life.life_rect.left = 0;
}

void move_bullet_rect(game_t *game, int offset, int max_value)
{
    if (game->bullet.bullet_rect.left + offset <= max_value)
        game->bullet.bullet_rect.left += offset;
    else
        game->bullet.bullet_rect.left = 0;
}