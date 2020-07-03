# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: anorjen <anorjen@student.21-school.ru>     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/08/24 15:42:48 by anorjen           #+#    #+#              #
#    Updated: 2020/07/03 19:23:53 by anorjen          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME_PS = push_swap
NAME_CH = checker

CC = clang
FLAGS = -Wall -Werror -Wextra
LIBRARIES = -lft -L$(LIBFT_DIRECTORY)
INCLUDES = -I$(HEADERS_DIRECTORY) -I$(LIBFT_HEADERS)

LIBFT = $(LIBFT_DIRECTORY)libft.a
LIBFT_DIRECTORY = ./lib/libft/
LIBFT_HEADERS = $(LIBFT_DIRECTORY)

HEADERS_LIST = push_swap.h
HEADERS_DIRECTORY = ./includes/
HEADERS = $(addprefix $(HEADERS_DIRECTORY), $(HEADERS_LIST))

SOURCES_DIRECTORY = ./srcs/
SOURCES_LIST = 	operations.c \
				operations_a.c \
				operations_b.c \
				stack.c \
				stack_operation.c \
				arguments.c \
				stack_index.c \
				logger.c

SOURCES_LIST_PS = 	push_swap.c \
					ps_utils.c \
					ps_sort.c \
					ps_index.c \
					insert_sort.c \
					is_markup.c \
					is_rotate.c \
					merge_sort.c \
					ms_shift.c

SOURCES_LIST_CH =	checker.c \
					ch_run.c

SOURCES = $(addprefix $(SOURCES_DIRECTORY), $(SOURCES_LIST))
SOURCES_PS = $(addprefix $(SOURCES_DIRECTORY), $(SOURCES_LIST_PS))
SOURCES_CH = $(addprefix $(SOURCES_DIRECTORY), $(SOURCES_LIST_CH))

OBJECTS_DIRECTORY = objects/
OBJECTS_LIST = $(patsubst %.c, %.o, $(SOURCES_LIST))
OBJECTS_LIST_PS = $(patsubst %.c, %.o, $(SOURCES_LIST_PS))
OBJECTS_LIST_CH = $(patsubst %.c, %.o, $(SOURCES_LIST_CH))
OBJECTS	= $(addprefix $(OBJECTS_DIRECTORY), $(OBJECTS_LIST))
OBJECTS_PS = $(addprefix $(OBJECTS_DIRECTORY), $(OBJECTS_LIST_PS))
OBJECTS_CH = $(addprefix $(OBJECTS_DIRECTORY), $(OBJECTS_LIST_CH))

# COLORS

GREEN = \033[0;32m
RED = \033[0;31m
RESET = \033[0m

.PHONY: all clean fclean re

all: $(NAME_PS) $(NAME_CH)

$(NAME_PS): $(LIBFT) $(OBJECTS_DIRECTORY) $(OBJECTS) $(OBJECTS_PS)
	@$(CC) $(FLAGS) -o $(NAME_PS)  $(OBJECTS) $(OBJECTS_PS) $(LIBRARIES) $(INCLUDES)
	@echo "\n$(NAME_PS): $(GREEN)$(NAME_PS) object files were created$(RESET)"
	@echo "$(NAME_PS): $(GREEN)$(NAME_PS) was created$(RESET)"

$(NAME_CH): $(LIBFT) $(OBJECTS_DIRECTORY) $(OBJECTS) $(OBJECTS_CH)
	@$(CC) $(FLAGS) -o $(NAME_CH) $(OBJECTS) $(OBJECTS_CH) $(LIBRARIES) $(INCLUDES)
	@echo "\n$(NAME_PS): $(GREEN)$(NAME_CH) object files were created$(RESET)"
	@echo "$(NAME_PS): $(GREEN)$(NAME_CH) was created$(RESET)"

$(OBJECTS_DIRECTORY):
	@mkdir -p $(OBJECTS_DIRECTORY)
	@echo "$(NAME_PS): $(GREEN)$(OBJECTS_DIRECTORY) was created$(RESET)"

$(OBJECTS_DIRECTORY)%.o : $(SOURCES_DIRECTORY)%.c $(HEADERS)
	@$(CC) $(FLAGS) -c $(INCLUDES) $< -o $@
	@echo "$(GREEN).$(RESET)\c"

$(LIBFT):
	@echo "$(NAME_PS): $(GREEN)creating $(LIBFT)...$(RESET)"
	@$(MAKE) -sC $(LIBFT_DIRECTORY)

clean:
	@$(MAKE) -sC $(LIBFT_DIRECTORY) clean
	@rm -rf $(OBJECTS_DIRECTORY)
	@echo "$(NAME_PS): $(RED)$(OBJECTS_DIRECTORY) was deleted$(RESET)"
	@echo "$(NAME_PS): $(RED)object files were deleted$(RESET)"

fclean: clean
	@rm -f $(LIBFT)
	@echo "$(NAME_PS): $(RED)$(LIBFT) was deleted$(RESET)"
	@rm -f $(NAME_PS)
	@echo "$(NAME_PS): $(RED)$(NAME_PS) was deleted$(RESET)"
	@rm -f $(NAME_CH)
	@echo "$(NAME_PS): $(RED)$(NAME_CH) was deleted$(RESET)"

re:
	@$(MAKE) fclean
	@$(MAKE) all
