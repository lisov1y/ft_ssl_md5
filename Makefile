NAME = ft_ssl
SRC	= src/*.c
FLAGS =	-Wall -Wextra -Werror
LIB = includes/ft_libftprintf/libftprintf.a

all: $(NAME)

$(NAME): $(SRC)
	@make -C includes/ft_libftprintf/
	@gcc -o $(NAME) $(FLAGS) $(SRC) $(LIB)

clean:
	@rm -f *.o
	@make clean -C includes/ft_libftprintf/

fclean: clean
	@rm -f $(NAME)
	@make fclean -C includes/ft_libftprintf/

re:
	@make re -C includes/ft_libftprintf/
	@make fclean
	@make all