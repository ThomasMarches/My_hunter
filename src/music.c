/*
** EPITECH PROJECT, 2019
** Hunter2.0
** File description:
** music.c
*/

#include "game.h"
#include "prototypes.h"
#include "include.h"

void music_init(game_t *game)
{
    game->music.shot = sfMusic_createFromFile("assets/Music/shot.wav");
    game->music.background = sfMusic_createFromFile("assets/Music/board.ogg");
    game->music.game_music = sfMusic_createFromFile("assets/Music/music.ogg");
    game->music.game_over = sfMusic_createFromFile("assets/Music/go.wav");
}