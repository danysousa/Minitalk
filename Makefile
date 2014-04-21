#******************************************************************************#
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dsousa <dsousa@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2014/02/08 11:33:26 by dsousa            #+#    #+#              #
#    Updated: 2014/02/08 11:34:54 by dsousa           ###   ########.fr        #
#                                                                              #
#******************************************************************************#

NAME = server

CLIENT = client

SRC_SERV =		src/server.c\
				src/list_serv.c\

SRC_CLIENT =	src/client.c\

LIB =		libft/libft.a

INCLUDE = 	libft/ -I src/include

CFLAGS =	-Wall -Wextra -Werror -o3

.PHONY: all clean fclean re

all: $(LIB) $(NAME) $(CLIENT)

$(NAME):
	@cc $(CFLAGS) $(LIB) $(SRC_SERV) -I $(INCLUDE) -o $@

$(CLIENT):
	@cc $(CFLAGS) $(LIB) $(SRC_CLIENT) -I $(INCLUDE) -o $@

$(LIB):
	@make -C libft/

clean:
	@make -C libft/ $@

fclean: clean
	@rm -f $(CLIENT) $(NAME)
	@make -C libft/ $@

re: fclean all
