# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: kmashao <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/08/20 12:27:21 by kmashao           #+#    #+#              #
#    Updated: 2018/08/28 14:40:28 by kmashao          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #



NAME = filler

LIBFT = ./libft/libft.a

COM = make -C libft/

SOURCES =	ai.c\
			filler.c\
			get_map.c\
			get_piece.c\
			get_position.c\
			crop_piece.c\
			check_piece.c\
			place.c

FLAGS =		-Wall -Wextra -Werror

all: $(NAME)

$(NAME): $(SOURCES)
	make -C libft/
	gcc $(FLAGS) -o $(NAME) $(SOURCES) $(LIBFT)

clean:
	make clean -C libft/

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: fclean clean re all