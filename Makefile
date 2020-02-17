##
## EPITECH PROJECT, 2019
## CSFML_Initiation
## File description:
## Makefile
##

NAME 	= 	my_hunter

SRC		=	src/main.c \
			src/game.c \
			src/launch.c \
			src/create_duck.c \
			src/music.c \
			src/poll_event.c \
			src/mouse.c \
			src/show_sprites.c \
			src/move_rect.c \
			src/background.c \
			src/cursor_show.c \
			src/generate_random_number.c \
			src/text_init.c \
			src/life.c \
			src/bullet_init.c \
			src/game_over.c \
			src/digit_to_char.c \
			src/biggest_score_get.c \
			src/my_getnbr.c \
			src/my_strlen.c \
			src/parallax.c \

OBJ		=	$(SRC:.c=.o)

CFLAGS	=	-I./Include/ -l csfml-window -l csfml-graphics -l csfml-system -l csfml-audio

$(NAME):	$(OBJ)
		gcc -o $(NAME) $(OBJ) $(CFLAGS)

clean:
		rm -f src/*.o
		rm -f $(NAME)

fclean: clean
		rm -f $(NAME)

re: 	fclean clean $(NAME)

debug:
		gcc -o $(NAME) $(OBJ) $(CFLAGS)
