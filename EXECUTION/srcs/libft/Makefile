# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hfadyl <hfadyl@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/10/19 16:08:41 by hfadyl            #+#    #+#              #
#    Updated: 2021/03/04 17:58:27 by hfadyl           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a

SOURCES = ft_isalnum.c ft_isprint.c ft_memcmp.c ft_putchar_fd.c ft_split.c  \
ft_strlcat.c ft_strncmp.c ft_substr.c ft_atoi.c ft_isalpha.c ft_itoa.c \
ft_memcpy.c ft_putendl_fd.c ft_strchr.c ft_strlcpy.c ft_strnstr.c \
ft_tolower.c ft_bzero.c ft_isascii.c ft_memccpy.c ft_memmove.c   \
ft_putnbr_fd.c ft_strdup.c ft_strlen.c ft_strrchr.c ft_toupper.c \
ft_calloc.c ft_isdigit.c ft_memchr.c ft_memset.c ft_putstr_fd.c \
ft_strjoin.c ft_strmapi.c ft_strtrim.c 

OBJECTS = *.o

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