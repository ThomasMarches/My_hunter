/*
** EPITECH PROJECT, 2019
** CSFML_Initiation
** File description:
** csfml_initiation.c
*/

#include "game.h"
#include "prototypes.h"
#include "include.h"

int sfml_game_start(void)
{
    game_t *game = malloc(sizeof(game_t));

    if (game == NULL)
        return (-1);
    init_game(game);
    start_game(game);
    destroy_game(game);
    return (0);
}

void show_read_me(void)
{
    FILE *fd;
    char *map = malloc(sizeof(char) * 5001);
    int nb = 0;

    fd = fopen("usage.txt", "r");
    nb = fread(map, 5000, 1, fd);
    write(1, map, my_strlen(map) + 1);
    fclose(fd);
    free(map);
}

int main(int ac, char **av)
{
    if (ac == 1) {
        if (sfml_game_start() == -1)
            return (84);
    } else if (ac == 2 && av[1][0] == '-' && av[1][1] == 'h' && av[1][2] == 0)
        show_read_me();
    else
        return (84);
    return (0);
}