/*
** EPITECH PROJECT, 2019
** Hunter2.0
** File description:
** game
*/

#include "include.h"

#ifndef GAME_H_
#define GAME_H_

typedef struct
{
    int nb_life;
    sfMusic *life_sound;
    sfSprite *lifespr;
    sfTexture *lifetxt;
    sfVector2f life_pos;
    sfIntRect life_rect;
} life_t;

typedef struct
{
    int number_of_bullet;
    sfIntRect bullet_rect;
    sfVector2f bullet_pos;
    sfSprite *bulletspr;
    sfTexture *bullettxt;
} bullet_t;

typedef struct
{
    sfMusic *shot;
    sfMusic *background;
    sfMusic *game_music;
    sfMusic *game_over;
} music_t;

typedef struct
{
    sfIntRect rect;
} mouse_rect_t;

typedef struct
{
    sfIntRect rect;
} duck_rect_t;

typedef struct duck
{
    sfVector2f position;
    int direction_x;
    int direction_y;
    sfTexture *texture;
    sfSprite *sprite;
    int speed;
    sfFloatRect present_rect;
} duck_t;

typedef struct
{
    sfText *text;
    sfText *text_score;
    sfText *text_biggest_score;
    sfVector2f text_position;
    sfVector2f text_position_score;
    sfVector2f text_position_biggest_score;
} text_t;

typedef struct {
    sfSprite *paralaxspr;
    sfSprite *paralax2spr;
    sfTexture *paralaxtxt;
    sfTexture *paralax2txt;
    sfVector2f speed_paralax;
    sfVector2f paralax_position;
    sfVector2f paralax2_position;
    sfVector2f starting_point;
    sfVector2f starting_point2;
} paralax_t;

typedef struct
{
    bool duck_present;
    sfVector2i mouse;
    int score;
    char *biggest_score;
    sfSprite *backgroundspr;
    sfTexture *backgroundtxt;
    sfSprite *cursorspr;
    sfTexture *cursortxt;
    sfRenderWindow *window;
    sfVector2f duck_vector;
    sfVector2f cursor_pos;
    text_t text;
    bullet_t bullet;
    music_t music;
    duck_t duck;
    life_t life;
    paralax_t paralax;
    mouse_rect_t mouse_rect;
    duck_rect_t rect_duck;
} game_t;

typedef struct
{
    sfClock *launch_clock;
    sfTime launching_t;
    sfTexture *launch_txt;
    sfSprite *launch_spr;
} launch_t;

typedef struct
{
    sfClock *clock;
    sfTime time;
    sfTexture *txt;
    sfSprite *spr;
} game_over_t;

#endif /* !GAME_H_ */