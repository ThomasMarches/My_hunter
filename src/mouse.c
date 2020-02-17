/*
** EPITECH PROJECT, 2019
** CSFML_Initiation
** File description:
** my hunter managing mouse click function
*/

#include "game.h"
#include "prototypes.h"
#include "include.h"

void mouse_init(game_t *game)
{
    game->mouse_rect.rect.top = 0;
    game->mouse_rect.rect.left = 0;
    game->mouse_rect.rect.width = 80;
    game->mouse_rect.rect.height = 79;
}

void present_duck(game_t *game)
{
    if (game->duck_present == true) {
        sfSprite_destroy(game->duck.sprite);
        sfTexture_destroy(game->duck.texture);
        game->duck.speed = game->duck.speed + generate_number(0, 1);
        game->score += 10;
        create_duck(game);
    }
}

void manage_bullet(game_t *game)
{
    if (game->bullet.number_of_bullet > 0 && game->life.nb_life > 0 &&
        game->duck_present != true) {
        move_bullet_rect(game, 200, 400);
        game->bullet.number_of_bullet = game->bullet.number_of_bullet - 1;
    }
    if (game->life.nb_life == 1 && game->bullet.number_of_bullet == 0) {
        sfMusic_stop(game->music.game_music);
        if (game->score > my_getnbr(game->biggest_score))
            set_biggest_score(game);
        game_over(game);
    }
    if (game->life.nb_life > 0 && game->bullet.number_of_bullet == 0) {
        move_life_rect(game, 200, 400);
        game->life.nb_life = game->life.nb_life - 1;
        sfSprite_destroy(game->bullet.bulletspr);
        sfTexture_destroy(game->bullet.bullettxt);
        init_bullet(game);
    }
    present_duck(game);
}

void manage_mouse_click(game_t *game)
{
    sfVector2f position;

    game->mouse = sfMouse_getPositionRenderWindow(game->window);
    sfMusic_play(game->music.shot);
    check_rect(game);
    manage_bullet(game);
    game->duck_present = false;
}
