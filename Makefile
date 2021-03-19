# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hfadyl <hfadyl@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/03/18 14:33:53 by mel-omar@st       #+#    #+#              #
#    Updated: 2021/03/19 14:45:20 by hfadyl           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = minishell

SRCS = PARSER/print/apply_flags.c PARSER/print/checker_flags.c PARSER/print/display.c\
	  PARSER/print/ft_atoi.c PARSER/print/ft_putnbr.c PARSER/print/print.c PARSER/print/print_utils.c\
	  PARSER/print/display_flags.c PARSER/readline/readline.c PARSER/dt/hash_table/additional_method.c \
	  PARSER/dt/hash_table/hash_map_method.c PARSER/dt/hash_table/hash_method2.c \
	  PARSER/dt/linkedlist/linkedlist_method.c PARSER/dt/linkedlist/linkedlist_method2.c \
	  PARSER/command_recognizer/double_quotes.c PARSER/command_recognizer/free_data.c \
	  PARSER/command_recognizer/getter_methods.c PARSER/command_recognizer/handle_coomands.c \
	  PARSER/command_recognizer/handle_coomands2.c  \
	  PARSER/command_recognizer/method_helper.c PARSER/command_recognizer/method_helper3.c \
	  PARSER/command_recognizer/rec_method.c PARSER/command_recognizer/single_quotes.c \
	  PARSER/command_recognizer/split_envirement_variables.c PARSER/command_recognizer/split_utiils.c \
	  PARSER/command_recognizer/split.c PARSER/command_recognizer/variables.c PARSER/command_recognizer/withback.c \
	  EXECUTION/srcs/ft_echo.c  EXECUTION/srcs/from_parsing2execution.c EXECUTION/srcs/files.c \
	  EXECUTION/srcs/ft_pipe.c EXECUTION/srcs/ft_unset.c EXECUTION/srcs/pipe_helper.c \
	  EXECUTION/srcs/ft_setup_builtins.c EXECUTION/srcs/ft_pwd.c EXECUTION/srcs/free_data.c \
	  EXECUTION/srcs/ft_cd.c  EXECUTION/srcs/ft_exit.c EXECUTION/srcs/ft_make_environ.c\
	  EXECUTION/srcs/ft_exec_env.c EXECUTION/srcs/ft_export.c  EXECUTION/srcs/ft_checker.c \
	  EXECUTION/srcs/ft_builtins_handler.c EXECUTION/srcs/ft_init_builtins.c \
	  EXECUTION/srcs/ft_main_execution.c EXECUTION/srcs/ft_signals.c \
	  EXECUTION/srcs/checker2.c ERRORS/srcs/check_backslash.c ERRORS/srcs/check_quotes.c \
	  ERRORS/srcs/check_redirections.c ERRORS/srcs/ft_check_dupl.c ERRORS/srcs/ft_error_parsing.c \
	  ERRORS/srcs/ft_error_printer.c EXECUTION/srcs/ft_remove_unused.c main.c EXECUTION/srcs/check_existance.c

LIBFTOBJ = ft_isprint.o ft_memcmp.o ft_putchar_fd.o ft_split.o ft_isalnum.o  \
		ft_strlcat.o ft_strncmp.o ft_substr.o ft_atoi.o ft_isalpha.o ft_itoa.o \
		ft_memcpy.o ft_putendl_fd.o ft_strchr.o ft_strlcpy.o ft_strnstr.o \
		ft_tolower.o ft_bzero.o ft_isascii.o ft_memccpy.o ft_memmove.o   \
		ft_putnbr_fd.o ft_strdup.o ft_strlen.o ft_strrchr.o ft_toupper.o \
		ft_calloc.o ft_isdigit.o ft_memchr.o ft_memset.o ft_putstr_fd.o \
		ft_strjoin.o ft_strmapi.o ft_strtrim.o
	  
	  
OBJS = $(SRCS:.c=.o)

all: $(NAME)

$(NAME): $(SRCS)
	@make -f libft/Makefile
	@gcc -Wall -Wextra -Werror libft.a $(SRCS)  -o $(NAME)
	
clean:
	@rm -rf libft.a
	@rm -f $(OBJ)
	@rm -f $(LIBFTOBJ)

fclean: clean
	@rm -f $(NAME)

re : fclean all

.PHONY: all clean fclean re