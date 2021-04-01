#!/bin/bash
gcc -Wall -Wextra -Werror -fsanitize=address libft/*.c PARSER/print/apply_flags.c PARSER/print/checker_flags.c PARSER/print/display.c\
	  PARSER/print/ft_atoi.c PARSER/print/ft_putnbr.c PARSER/print/print.c PARSER/print/print_utils.c\
	  PARSER/print/display_flags.c PARSER/dt/hash_table/additional_method.c \
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
	  ERRORS/srcs/check_redirections.c ERRORS/srcs/ft_check_dupl.c ERRORS/srcs/ft_error_parsing.c \
	  readline/key_functions1.c readline/key_functions2.c readline/stack_manip.c readline/helper_method.c \
	  readline/readline.c readline/ft_termcap.c readline/ft_history_manip.c PARSER/dt/stack/*.c \
	  ERRORS/srcs/ft_error_printer.c EXECUTION/srcs/ft_remove_unused.c main.c EXECUTION/srcs/check_existance.c \
	  ERRORS/srcs/ft_pipe_errors.c ERRORS/srcs/additional_function_error.c EXECUTION/srcs/ft_sort_export.c EXECUTION/srcs/helper_function.c -o minishell -lcurses
./minishell