/*
** EPITECH PROJECT, 2019
** Hunter2.0
** File description:
** game
*/

#include "game.h"
#include "include.h"

#ifndef PROTOTYPES_H_
#define PROTOTYPES_H_

void init_bullet(game_t *);
void init_life(game_t *);
void text_init(game_t *);
void text_init_biggest_score(game_t *);
void init_game(game_t *);
void init_background(game_t *);
void mouse_init(game_t *);
void music_init(game_t *);
void create_duck(game_t *);
void init_parallax(game_t *);

void cursor_show(game_t *);
void show_sprites(game_t *);

void poll_event(sfEvent, game_t *);
void check_rect(game_t *);

void manage_bullet(game_t *);
void manage_mouse_click(game_t *);

void move_duck_rect(game_t *, int, int);
void check_rect(game_t *);
void move_bullet_rect(game_t *, int, int);
void move_life_rect(game_t *, int, int);
void paralax_move(game_t *);

void get_biggest_score(game_t *);
void set_biggest_score(game_t *);

int my_getnbr(const char *);
int my_strlen(const char *);
char *digit_to_char(int);
int generate_number(int, int);

int sfml_game_start();
void launching_game(game_t *);
void start_game(game_t *);
void destroy_game(game_t *);
void game_over(game_t *);
void paralax_destroy(game_t *);
#endif /* !PROTOTYPES_H_ */