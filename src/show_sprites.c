/*
** EPITECH PROJECT, 2019
** Hunter2.0
** File description:
** show_duck.c
*/

#include "game.h"
#include "prototypes.h"
#include "include.h"

void change_duck_sense(game_t *game, int sense)
{
    game->duck.position = sfSprite_getPosition(game->duck.sprite);
    sfSprite_destroy(game->duck.sprite);
    sfTexture_destroy(game->duck.texture);
    if (sense == 1) {
        game->duck.texture =
        sfTexture_createFromFile("assets/Image/xmasltr.png", NULL);
        game->duck.sprite = sfSprite_create();
        sfSprite_setPosition(game->duck.sprite, game->duck.position);
    } else {
        game->duck.texture =
        sfTexture_createFromFile("assets/Image/xmasrtl.png", NULL);
        game->duck.sprite = sfSprite_create();
        sfSprite_setPosition(game->duck.sprite, game->duck.position);
    }
}

void move_duck(game_t *game)
{
    game->duck.position = sfSprite_getPosition(game->duck.sprite);
    if (game->duck.position.x + game->duck_vector.x >= 1920) {
        game->duck_vector.x *= -1.25;
        change_duck_sense(game, 0);
    }
    if (game->duck.position.x + game->duck_vector.x <= 0) {
        game->duck_vector.x *= -1.25;
        change_duck_sense(game, 1);
    }
    if (game->duck.position.y + game->duck_vector.y <= 0) {
        game->duck_vector.y *= -1.25;
    }
    if (game->duck.position.y + game->duck_vector.y >= 780) {
        game->duck_vector.y *= -1.25;
    }
    sfSprite_move(game->duck.sprite, game->duck_vector);
}

void show_sprites(game_t *game)
{
    sfSprite_setTexture(game->duck.sprite, game->duck.texture, sfTrue);
    sfSprite_setTextureRect(game->duck.sprite, game->rect_duck.rect);
    sfSprite_setTextureRect(game->life.lifespr, game->life.life_rect);
    sfSprite_setTextureRect(game->bullet.bulletspr, game->bullet.bullet_rect);
    cursor_show(game);
    sfText_setString(game->text.text_score, digit_to_char(game->score));
    sfRenderWindow_drawSprite(game->window, game->backgroundspr, NULL);
    paralax_move(game);
    sfRenderWindow_drawSprite(game->window, game->life.lifespr, NULL);
    sfRenderWindow_drawSprite(game->window, game->bullet.bulletspr, NULL);
    sfRenderWindow_drawText(game->window, game->text.text, NULL);
    sfRenderWindow_drawText(game->window, game->text.text_biggest_score, NULL);
    sfRenderWindow_drawText(game->window, game->text.text_score, NULL);
    sfRenderWindow_drawSprite(game->window, game->duck.sprite, NULL);
    sfRenderWindow_drawSprite(game->window, game->cursorspr, NULL);
    sfRenderWindow_display(game->window);
    move_duck(game);
    sfRenderWindow_clear(game->window, sfBlack);
}