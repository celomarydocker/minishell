# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hfadyl <hfadyl@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/10/19 16:08:41 by hfadyl            #+#    #+#              #
#    Updated: 2021/03/19 14:58:10 by hfadyl           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a

SOURCES = libft/ft_isalnum.c libft/ft_isprint.c libft/ft_memcmp.c libft/ft_putchar_fd.c libft/ft_split.c  \
libft/ft_strlcat.c libft/ft_strncmp.c libft/ft_substr.c libft/ft_atoi.c libft/ft_isalpha.c libft/ft_itoa.c \
libft/ft_memcpy.c libft/ft_putendl_fd.c libft/ft_strchr.c libft/ft_strlcpy.c libft/ft_strnstr.c \
libft/ft_tolower.c libft/ft_bzero.c libft/ft_isascii.c libft/ft_memccpy.c libft/ft_memmove.c   \
libft/ft_putnbr_fd.c libft/ft_strdup.c libft/ft_strlen.c libft/ft_strrchr.c libft/ft_toupper.c \
libft/ft_calloc.c libft/ft_isdigit.c libft/ft_memchr.c libft/ft_memset.c libft/ft_putstr_fd.c \
libft/ft_strjoin.c libft/ft_strmapi.c libft/ft_strtrim.c 

OBJECTS = ft_isalnum.o ft_isprint.o ft_memcmp.o ft_putchar_fd.o ft_split.o  \
ft_strlcat.o ft_strncmp.o ft_substr.o ft_atoi.o ft_isalpha.o ft_itoa.o \
ft_memcpy.o ft_putendl_fd.o ft_strchr.o ft_strlcpy.o ft_strnstr.o \
ft_tolower.o ft_bzero.o ft_isascii.o ft_memccpy.o ft_memmove.o   \
ft_putnbr_fd.o ft_strdup.o ft_strlen.o ft_strrchr.o ft_toupper.o \
ft_calloc.o ft_isdigit.o ft_memchr.o ft_memset.o ft_putstr_fd.o \
ft_strjoin.o ft_strmapi.o ft_strtrim.o 

all: $(NAME)

$(NAME): $(SOURCES)
	gcc -Wall -Wextra -Werror -c $(SOURCES)
	ar rc $(NAME) $(OBJECTS)
	ranlib $(NAME)

clean:
	rm -rf *.o

fclean: clean
	rm -rf *.a

re: fclean all

.PHONY: all clean fclean re