PS_NAME = push_swap
CH_NAME = checker
CC = clang

LIBFT_PATH = ./lib/libft/
LIBFT = $(LIBFT_PATH)libft.a
INCLUDES  = -I./includes/
INCLUDES += -I./lib/libft/

SRC_PATH = ./srcs/
SRC_FILES = operations.c \
			operations_a.c \
			operations_b.c \
			stack.c \
			stack_operation.c \
			arguments.c

CH_SRC_FILES = $(SRC_FILES)
CH_SRC_FILES += checker.c \
				ch_run.c

PS_SRC_FILES = $(SRC_FILES)
PS_SRC_FILES += push_swap.c \
				ps_utils.c \
				ps_sorting1.c

CH_SRC = 	$(addprefix $(SRC_PATH), $(CH_SRC_FILES))
PS_SRC = 	$(addprefix $(SRC_PATH), $(PS_SRC_FILES))


FLAG = -Wall -Werror -Wextra -g
CH_OBJ = $(CH_SRC_FILES:.c=.o)
PS_OBJ = $(PS_SRC_FILES:.c=.o)
# OBJ = *.o

CG = \033[92m
all: start $(CH_NAME) $(PS_NAME)

$(LIBFT):
	@make -sC ./lib/libft/
	@echo "\r--= libft compiled =--"

$(CH_NAME): $(LIBFT)
	@$(CC)  -c $(FLAG) $(CH_SRC) $(INCLUDES)
	@$(CC)  -ltermcap -o $(CH_NAME) $(CH_OBJ) -lft -L$(LIBFT_PATH) $(INCLUDES)
	@echo "\r--= $(CH_NAME) compiled =--"

$(PS_NAME): $(LIBFT)
	@$(CC)  -c $(FLAG) $(PS_SRC) $(INCLUDES)
	@$(CC)  -ltermcap -o $(PS_NAME) $(PS_OBJ) -lft -L$(LIBFT_PATH) $(INCLUDES)
	@echo "\r--= $(PS_NAME) compiled =--"

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

clean:
	@make clean -sC lib/libft/
	@rm -rf $(CH_OBJ) $(PS_OBJ)

fclean: clean
	@make fclean -sC lib/libft/
	@rm -rf $(CH_NAME) $(PS_NAME)

re: fclean all
