# **************************************************************************** #
#                                                                              #
#                                                         ::::::::             #
#    Makefile                                           :+:    :+:             #
#                                                      +:+                     #
#    By: ihering- <marvin@codam.nl>                   +#+                      #
#                                                    +#+                       #
#    Created: 2019/01/19 17:44:26 by ihering-       #+#    #+#                 #
#    Updated: 2019/07/03 11:17:49 by ihering-      ########   odam.nl          #
#                                                                              #
# **************************************************************************** #

NAME = libft.a

LIBFT = ft_whitespaces.c ft_memset.c ft_bzero.c ft_memcpy.c ft_memccpy.c \
		ft_memmove.c ft_memchr.c ft_memcmp.c ft_memalloc.c ft_memdel.c \
		ft_memdup.c ft_strlen.c ft_strdup.c ft_strcpy.c ft_strncpy.c \
		ft_strcat.c ft_strncat.c ft_strlcat.c ft_strchr.c ft_strrchr.c \
		ft_strstr.c ft_strnstr.c ft_strcmp.c ft_strncmp.c ft_atoi.c \
		ft_isalpha.c ft_isdigit.c ft_isalnum.c ft_isascii.c ft_isprint.c \
		ft_toupper.c ft_tolower.c ft_strnew.c ft_strdel.c ft_strclr.c \
		ft_striter.c ft_striteri.c ft_strmap.c ft_strmapi.c ft_strequ.c \
		ft_strnequ.c ft_strsub.c ft_strjoin.c ft_strtrim.c ft_strsplit.c \
		ft_itoa.c ft_putchar.c ft_putstr.c ft_putendl.c ft_putnbr.c \
		ft_putchar_fd.c ft_putstr_fd.c ft_putendl_fd.c ft_putnbr_fd.c \
		ft_lstadd.c ft_lstdel.c ft_lstdelone.c ft_lstiter.c ft_lstmap.c \
		ft_lstnew.c ft_leng.c ft_swap.c ft_strarrdel.c get_next_line.c \
		ft_error.c

HEADER = libft.h
OBJDIR = objects
LIBFT_SRCS = $(addprefix srcs/,$(LIBFT))
SRCS = $(LIBFT_SRCS)
OBJ = $(LIBFT:.c=.o)


SRC = $(addprefix srcs/,$(SRC_DIR))
FLAGS = -Wall -Wextra -Werror

all: $(NAME)

$(NAME):
		@gcc $(FLAGS) -c $(SRCS) -I $(HEADER)
		@ar rc $(NAME) $(OBJ)
		@ranlib $(NAME)

clean:
		@rm -rf $(OBJ)

fclean: clean
		@rm -rf $(NAME)

re: fclean all