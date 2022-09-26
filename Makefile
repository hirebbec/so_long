# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hirebbec <hirebbec@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/12/15 17:22:57 by hirebbec          #+#    #+#              #
#    Updated: 2021/12/28 17:32:36 by hirebbec         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = so_long

NAME_BONUS = so_long_bonus

CC = gcc
CFLAGS = -Wall -Wextra -Werror
RM = rm -f

FILES = open_map.c get_next_line.c get_next_line_utils.c \
					moves.c main.c cheaks.c map_cheak.c

FILES_BONUS = open_map_bonus.c get_next_line.c get_next_line_utils.c \
					moves_bonus.c main_bonus.c cheaks_bonus.c map_cheak_bonus.c	\
					ft_itoa.c
					
OBJS = $(FILES:%.c=%.o)

OBJS_BONUS = $(FILES_BONUS:%.c=%.o)

MLX_FLAGS = -L . -lmlx -framework OpenGL -framework AppKit

%.o: %.c libft.h
	$(CC) $(CFLAGS) -c $< -o $@ 

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(MLX_FLAGS) $(OBJS) -o $(NAME)

$(NAME_BONUS): $(OBJS_BONUS)
	$(CC) $(CFLAGS) $(MLX_FLAGS) $(OBJS_BONUS) -o $(NAME_BONUS)

all: $(NAME)

bonus: $(NAME_BONUS)

clean:
	$(RM) $(OBJS)
	$(RM) $(OBJS_BONUS)

fclean: clean
	$(RM) $(NAME)
	$(RM) $(NAME_BONUS)

re: fclean all

.PHONY:all clean fclean re bonus
