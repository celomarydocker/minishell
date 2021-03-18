# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mel-omar@student.1337.ma <mel-omar>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/03/18 14:33:53 by mel-omar@st       #+#    #+#              #
#    Updated: 2021/03/18 14:59:43 by mel-omar@st      ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = "minishell"
SRCS = PARSER/print/apply_flags.c PARSER/print/checker_flags.c PARSER/print/display.c\
	  PARSER/print/ft_atoi.c PARSER/print/ft_putnbr.c PARSER/print/print.c PARSER/print/print_utils.c\
	  PARSER/print/display_flags.c PARSER/readline/readline.c PARSER/dt/hash_table/additional_method.c \
	  PARSER/dt/hash_table/hash_map_mehtod.c PARSER/dt/hash_table/hash_mehtod2.c \
	  PARSER/dt/linkedlist/linkedlist_method.c PARSER/dt/linkedlist/linkedlist_method2.c \
	  PARSER/command_recognizer/double_quotes.c PARSER/command_recognizer/free_data.c \
	  PARSER/command_recognizer/getter_methods.c PARSER/command_recognizer/handle_coomands.c \
	  PARSER/command_recognizer/handle_coomands2.c
	  
	  

OBJ = apply_flags.o checker_flags.o display.o \
	  ft_atoi.o ft_putnbr.o print.o print_utils.o \
	  display_flags.o readline.o additional_method.o \
	  hash_map_mehtod.o hash_mehtod2.o linkedlist_method.o \
	  linkedlist_method2.c double_quotes.o free_data.o \
	  
	  

all: $(NAME)
	@gcc -Wall -Wextra -Werror $(SRC) -o $(NAME)
clean:
	@rm -f $(OBJ)
fclean: clean
	@rm -f $(NAME)
re : fclean all
