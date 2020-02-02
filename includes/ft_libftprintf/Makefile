NAME = libftprintf.a

HEADER = ft_printf.h

SRC = src/*.c

OBJ = *.o

LIB = includes/libft/libft.a

FLAGS = -I.includes/ft_printf.h

all: $(NAME)

$(NAME):
	@gcc -c -Wall -Werror -Wextra $(FLAGS) -I.includes/libft/libft.h includes/libft/*.c $(SRC)
	@ar rc $(NAME) $(OBJ)
	@ranlib $(NAME)

clean:
	@rm -f $(OBJ) includes/*.gch
	@rm -f includes/libft/$(OBJ) includes/libft/*.gch

fclean: clean
	@rm -f $(NAME)
	@rm -f includes/libft/libft.a

re: fclean all

.PHONY: clean fclean
