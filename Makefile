# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hfadyl <hfadyl@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/03/18 14:33:53 by mel-omar@st       #+#    #+#              #
#    Updated: 2021/04/02 17:52:14 by hfadyl           ###   ########.fr        #
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
	  PARSER/command_recognizer/handle_coomands2.c PARSER/command_recognizer/replace_envirement.c \
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
	  EXECUTION/srcs/ft_main_execution.c EXECUTION/srcs/ft_signals.c ERRORS/srcs/ft_handle_file_case_export.c \
	  EXECUTION/srcs/checker2.c ERRORS/srcs/check_backslash.c ERRORS/srcs/check_quotes.c \
	  readline/key_functions1.c readline/key_functions2.c readline/stack_manip.c readline/helper_method.c \
	  readline/readline.c readline/ft_termcap.c readline/ft_history_manip.c PARSER/dt/stack/*.c \
	  ERRORS/srcs/check_redirections.c ERRORS/srcs/ft_check_dupl.c ERRORS/srcs/ft_error_parsing.c \
	  ERRORS/srcs/ft_error_printer.c EXECUTION/srcs/ft_remove_unused.c main.c EXECUTION/srcs/check_existance.c \
	  ERRORS/srcs/ft_pipe_errors.c ERRORS/srcs/additional_function_error.c EXECUTION/srcs/ft_sort_export.c \
	  EXECUTION/srcs/helper_function.c

LIBFTOBJ = ft_isprint.o ft_memcmp.o ft_putchar_fd.o ft_isalnum.o  \
		ft_strlcat.o ft_strncmp.o ft_substr.o ft_atoi.o ft_isalpha.o ft_itoa.o \
		ft_memcpy.o ft_putendl_fd.o ft_strchr.o ft_strlcpy.o ft_strnstr.o \
		ft_tolower.o ft_bzero.o ft_isascii.o ft_memccpy.o ft_memmove.o   \
		ft_putnbr_fd.o ft_strdup.o ft_strlen.o ft_strrchr.o ft_toupper.o \
		ft_calloc.o ft_isdigit.o ft_memchr.o ft_memset.o ft_putstr_fd.o \
		ft_strjoin.o ft_strmapi.o 
	  
	  
OBJS = PARSER/print/apply_flags.o PARSER/print/checker_flags.o PARSER/print/display.o\
	  PARSER/print/ft_atoi.o PARSER/print/ft_putnbr.o PARSER/print/print.o PARSER/print/print_utils.o\
	  PARSER/print/display_flags.o PARSER/readline/readline.o PARSER/dt/hash_table/additional_method.o \
	  PARSER/dt/hash_table/hash_map_method.o PARSER/dt/hash_table/hash_method2.o \
	  PARSER/dt/linkedlist/linkedlist_method.o PARSER/dt/linkedlist/linkedlist_method2.o \
	  PARSER/command_recognizer/double_quotes.o PARSER/command_recognizer/free_data.o \
	  PARSER/command_recognizer/getter_methods.o PARSER/command_recognizer/handle_coomands.o \
	  PARSER/command_recognizer/handle_coomands2.o PARSER/command_recognizer/replace_envirement.o  \
	  PARSER/command_recognizer/method_helper.o PARSER/command_recognizer/method_helper3.o \
	  PARSER/command_recognizer/rec_method.o PARSER/command_recognizer/single_quotes.o \
	  PARSER/command_recognizer/split_envirement_variables.o PARSER/command_recognizer/split_utiils.o \
	  PARSER/command_recognizer/split.o PARSER/command_recognizer/variables.o PARSER/command_recognizer/withback.o \
	  EXECUTION/srcs/ft_echo.o  EXECUTION/srcs/from_parsing2execution.o EXECUTION/srcs/files.o \
	  EXECUTION/srcs/ft_pipe.o EXECUTION/srcs/ft_unset.o EXECUTION/srcs/pipe_helper.o \
	  EXECUTION/srcs/ft_setup_builtins.o EXECUTION/srcs/ft_pwd.o EXECUTION/srcs/free_data.o \
	  EXECUTION/srcs/ft_cd.o  EXECUTION/srcs/ft_exit.o EXECUTION/srcs/ft_make_environ.o\
	  EXECUTION/srcs/ft_exec_env.o EXECUTION/srcs/ft_export.o  EXECUTION/srcs/ft_checker.o \
	  EXECUTION/srcs/ft_builtins_handler.o EXECUTION/srcs/ft_init_builtins.o \
	  EXECUTION/srcs/ft_main_execution.o EXECUTION/srcs/ft_signals.o ERRORS/srcs/ft_handle_file_case_export.o \
	  EXECUTION/srcs/checker2.o ERRORS/srcs/check_backslash.o ERRORS/srcs/check_quotes.o \
	  readline/key_functions1.o readline/key_functions2.o readline/stack_manip.o readline/helper_method.o \
	  readline/readline.o readline/ft_termcap.o readline/ft_history_manip.o PARSER/dt/stack/*.o \
	  ERRORS/srcs/check_redirections.o ERRORS/srcs/ft_check_dupl.o ERRORS/srcs/ft_error_parsing.o \
	  ERRORS/srcs/ft_error_printer.o EXECUTION/srcs/ft_remove_unused.o main.o EXECUTION/srcs/check_existance.o \
	  ERRORS/srcs/ft_pipe_errors.o ERRORS/srcs/additional_function_error.o EXECUTION/srcs/ft_sort_export.o \
	  EXECUTION/srcs/helper_function.o

all: $(NAME)

$(NAME): $(SRCS)
	@make -f libft/Makefile
	@gcc -Wall -Wextra -Werror libft.a $(SRCS)  -o $(NAME)
	@rm -f $(LIBFTOBJ)
	
clean:
	@rm -rf libft.a
	@rm -f $(OBJ)
	@rm -f $(LIBFTOBJ)

fclean: clean
	@rm -f $(NAME)

re : fclean all

.PHONY: all clean fclean re