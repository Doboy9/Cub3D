# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dboire <dboire@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/12/21 17:44:47 by kprigent          #+#    #+#              #
#    Updated: 2024/05/16 16:16:46 by dboire           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = cub3D

MAIN_SRCS = src_parsing/main.c \
			src_parsing/event_close_release_button.c \
			src_parsing/mouse_menu_event.c \
			src_parsing/check_error.c \
			src_parsing/check_error2.c \
			src_parsing/free_and_exit.c \
			src_parsing/free_map_is_square.c \
			src_parsing/parsing.c \
			libft/ft_printf.c \
			libft/ft_strdup.c \
			libft/ft_putcharp.c \
			libft/ft_putnbr_base.c \
			libft/ft_putnbr_unsigned.c \
			libft/ft_putnbrp.c \
			libft/ft_putstrp.c \
			libft/ft_putaddr.c \
			libft/ft_itoa.c \
			libft/ft_strlen.c \
			libft/get_next_line.c \
			libft/get_next_line_utils.c\
			exec/exec.c\
			exec/draw.c\
			exec/redraw.c\
			exec/bresenham.c\
			exec/rays.c\
			


OBJTS = $(MAIN_SRCS:.c=.o)

HEADER = -I includes
CFLAGS = -Wall -Wextra -Werror -I ./mlx/ -g

$(NAME): $(OBJTS)
	cc -o $(NAME) $(OBJTS) $(CFLAGS) $(HEADER) -L ./mlx -lmlx -lXext -lX11 -lm -lbsd

RM	=	rm -f

all:	${NAME}

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	${RM} ${OBJTS} ${OBJTS_BONUS}
	
fclean:	clean
	${RM} ${NAME} ${NAME_BONUS}

re:	fclean all

.PHONY: all bonus clean fclean re
