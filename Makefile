# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: anorjen <anorjen@student.21-school.ru>     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/08/24 15:42:48 by anorjen           #+#    #+#              #
#    Updated: 2020/11/23 16:47:45 by anorjen          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

PS_NAME = push_swap
CH_NAME = checker

CC = clang
FLAGS = -Wall -Werror -Wextra -g
LIBRARIES = -lft -L$(LIBFT_DIRECTORY)
INCLUDES = -I$(HEADERS_DIRECTORY) -I$(LIBFT_HEADERS)

LIBFT = $(LIBFT_DIRECTORY)libft.a
LIBFT_DIRECTORY = ./libft/
LIBFT_HEADERS = $(LIBFT_DIRECTORY)/includes

HEADERS_LIST = 	push_swap.h

HEADERS_DIRECTORY = ./includes/
HEADERS = $(addprefix $(HEADERS_DIRECTORY), $(HEADERS_LIST))

SOURCES_DIRECTORY = ./srcs/

COMMON_SRC_LIST = operations.c \
				operations_a.c \
				operations_b.c \
				stack.c \
				stack_operation.c \
				arguments.c \
				stack_index.c \
				logger.c

CH_SRC_LIST = $(COMMON_SRC_LIST)
CH_SRC_LIST += checker.c \
				ch_run.c

PS_SRC_LIST = $(COMMON_SRC_LIST)
PS_SRC_LIST += push_swap.c \
				ps_utils.c \
				ps_sort.c \
				ps_index.c \
				insert_sort.c \
				is_markup.c \
				is_rotate.c \
				merge_sort.c \
				ms_shift.c \
				simple_merge_sort.c

CH_SRC = 	$(addprefix $(SOURCES_DIRECTORY), $(CH_SRC_LIST))
PS_SRC = 	$(addprefix $(SOURCES_DIRECTORY), $(PS_SRC_LIST))

OBJECTS_DIRECTORY = objects/
CH_OBJ_LIST = $(patsubst %.c, %.o, $(CH_SRC_LIST))
CH_OBJ	= $(addprefix $(OBJECTS_DIRECTORY), $(CH_OBJ_LIST))

PS_OBJ_LIST = $(patsubst %.c, %.o, $(PS_SRC_LIST))
PS_OBJ	= $(addprefix $(OBJECTS_DIRECTORY), $(PS_OBJ_LIST))

# COLORS

GREEN = \033[0;32m
RED = \033[0;31m
RESET = \033[0m

.PHONY: all clean fclean re

all: start  $(OBJECTS_DIRECTORY) $(CH_NAME) $(PS_NAME)
	@./test.sh 100 5

start:
	@echo "\r$(CG)compile..."
	@echo "	------------------------------------------------------------------------------	"
	@echo "	| 000000  00   00  0000  00           0000  00          00   0000   000000   |	"
	@echo "	| 00   00 00   00 00     00          00     00    00    00 00    00 00   00  |	"
	@echo "	| 000000  00   00  0000  000000       0000   00   00   00  00    00 000000   |	"
	@echo "	| 00      00   00     00 00   00         00  00   00   00  00000000 00       |	"
	@echo "	| 00      00   00 0   00 00   00     0   00   00 0  0 00   00    00 00       |	"
	@echo "	| 00       00000   0000  00   00 0000 0000     000  000    00    00 00       |	"
	@echo "	------------------------------------------------------------------------------	"


$(CH_NAME): $(LIBFT) $(CH_OBJ) $(HEADERS)
	@$(CC) $(FLAGS) $(INCLUDES) $(CH_OBJ) $(LIBRARIES) -o $(CH_NAME)
	@echo "\n$(CH_NAME): $(GREEN)$(CH_NAME) object files were created$(RESET)"
	@echo "$(CH_NAME): $(GREEN)$(CH_NAME) was created$(RESET)"

$(PS_NAME): $(LIBFT) $(PS_OBJ) $(HEADERS)
	@$(CC) $(FLAGS) $(INCLUDES) $(PS_OBJ) $(LIBRARIES) -o $(PS_NAME)
	@echo "\n$(PS_NAME): $(GREEN)$(PS_NAME) object files were created$(RESET)"
	@echo "$(PS_NAME): $(GREEN)$(PS_NAME) was created$(RESET)"

$(OBJECTS_DIRECTORY):
	@mkdir -p $(OBJECTS_DIRECTORY)
	@echo "$(NAME): $(GREEN)$(OBJECTS_DIRECTORY) was created$(RESET)"

$(OBJECTS_DIRECTORY)%.o : $(SOURCES_DIRECTORY)%.c
	@$(CC) $(FLAGS) -c $(INCLUDES) $< -o $@
	@echo "$(GREEN).$(RESET)\c"

$(LIBFT):
	@echo "$(NAME): $(GREEN)creating $(LIBFT)...$(RESET)"
	@$(MAKE) -sC $(LIBFT_DIRECTORY)

clean:
	@$(MAKE) -sC $(LIBFT_DIRECTORY) clean
	@rm -rf $(OBJECTS_DIRECTORY)
	@echo "$(NAME): $(RED)$(OBJECTS_DIRECTORY) was deleted$(RESET)"
	@echo "$(NAME): $(RED)object files were deleted$(RESET)"

fclean: clean
	@rm -f $(LIBFT)
	@echo "$(NAME): $(RED)$(LIBFT) was deleted$(RESET)"
	@rm -f $(NAME)
	@echo "$(NAME): $(RED)$(NAME) was deleted$(RESET)"

re:
	@$(MAKE) fclean
	@$(MAKE) all
