# **************************************************************************** #
#                                                                              #
#                                                         ::::::::             #
#    Makefile                                           :+:    :+:             #
#                                                      +:+                     #
#    By: ihering- <ihering-@student.codam.nl>         +#+                      #
#                                                    +#+                       #
#    Created: 2019/06/27 15:24:14 by ihering-       #+#    #+#                 #
#    Updated: 2019/10/30 14:25:42 by ihering-      ########   odam.nl          #
#                                                                              #
# **************************************************************************** #

NAME = fractol
S = ./
H = ./
SRC = main.c mandelbrot.c julia.c menu.c mouse.c color.c keys.c burningship.c
OBJ = $(SRC:%.c=%.o)
HDR = fdf.h libft/include/libft.h
MINILIBX = -I minilibx -L minilibx -lmlx -framework OpenGL -framework Appkit
LIB = -I libft/include -L libft -lft
FLAGS = -Wall -Werror -Wextra

DARKOLIVEGREEN3= \033[0;38;5;149m
DARKSEAGREEN3= \033[0;38;5;150m
DARKSEAGREEN2= \033[0;38;5;151m
RESET = \033[0m

.PHONY: all clean fclean re

all: $(NAME)

$(NAME): $(SRC)
	@make -C minilibx/
	@make -C libft/
	@echo "$(DARKSEAGREEN3)Library and Fractol Ready to Go$(RESET)"
	@gcc $(FLAGS) -I minilibx -I libft/includes -c $(SRC)
	@gcc -o $(NAME) $(OBJ) $(LIB) $(MINILIBX)

clean:
	@/bin/rm -f $(OBJ)
	@make clean -C minilibx/
	@make clean -C libft/
	@echo "$(DARKSEAGREEN2)Cleaning... Done$(RESET)"

fclean: clean
	@/bin/rm -f $(NAME)
	@make fclean -C libft/
	@echo "$(DARKOLIVEGREEN3)Erasing Everything... Done$(RESET)"

re: fclean all