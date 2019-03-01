# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: wconnell <wconnell@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/11/22 18:07:34 by fmasha-h          #+#    #+#              #
#    Updated: 2019/02/13 14:18:40 by wconnell         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fillit

SRC = tools.c validators.c create_struct.c place_n_print.c map.c get_coord.c fillit.c main.c

HEAD = fillit.h

LIB = ./libft

FLAGS = -Wall -Wextra -Werror

all: $(NAME)

$(NAME):
	make -C $(LIB) re
	gcc $(FLAGS) -L $(LIB) -lft $(SRC) -I $(LIB) -I $(HEAD) -o $(NAME)

clean:
	/bin/rm -f ./libft/*.o

fclean: clean
	/bin/rm -f ./libft/*.a
	/bin/rm -f $(NAME)

re: fclean all
