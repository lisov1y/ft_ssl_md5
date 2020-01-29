# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mstupnik <mstupnik@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/11/20 16:41:56 by mstupnik          #+#    #+#              #
#    Updated: 2020/01/28 16:22:32 by mstupnik         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = ft_ssl

FLAGS = -Wall -Werror -Wextra

SRC = src/*.c

HEADER = -I.includes/ft_ssl.h

LIB = includes/ft_libftprintf/libftprintf.a

all: $(NAME)

$(NAME):
	@gcc $(FLAGS) $(HEADER) -o $(NAME) $(SRC) $(LIB)

debug:
	@gcc $(FLAGS) $(HEADER) -o $(NAME) $(SRC) $(LIB) -g

clean:
	@rm -rf *.o
	@rm -rf ft_ssl.dSYM

fclean: clean
	@rm $(NAME)

re: clean
	@gcc $(FLAGS) $(HEADER) -o $(NAME) $(SRC) $(LIB)