# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hfadyl <hfadyl@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/03/04 18:00:55 by hfadyl            #+#    #+#              #
#    Updated: 2021/03/04 18:00:59 by hfadyl           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = execution

SOURCES = 

OBJECTS = *.o

all: $(NAME)

$(NAME): $(SOURCES)
	gcc -Wall -Wextra -Werror -c $(SOURCES)


clean:
	rm -rf *.o

fclean: clean
	rm -rf *.a

re: fclean all

.PHONY: all clean fclean re