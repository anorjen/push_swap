PS_NAME = push_swap
CH_NAME = checker
CC = clang

LIBFT = ./lib/libft/libft.a
INCLUDES  = -I./includes/
INCLUDES += -I./lib/libft/

SRC_PATH = ./srcs/
SRC_FILES = ps_operation.c ps_operation_a.c ps_operation_b.c \
			stack.c stack_operation.c

CH_SRC_FILES = SRC_FILES
CH_SRC_FILES += checker.c

PS_SRC_FILES = SRC_FILES
PS_SRC_FILES += push_swap.c

CH_SRC = 	$(addprefix $(SRC_PATH), $(CH_SRC_FILES))
PS_SRC = 	$(addprefix $(SRC_PATH), $(PS_SRC_FILES))


FLAG = -Wall -Werror -Wextra -g
CH_OBJ = $(CH_SRC:.c=.o)
PS_OBJ = $(PS_SRC:.c=.o)
# OBJ = *.o

CG = \033[92m
all: start $(CH_NAME) $(PS_NAME)

$(CH_NAME):
	@make -sC ./lib/libft/
	@$(CC)  -c $(FLAG) $(CH_SRC) $(INCLUDES)
	@$(CC)  -ltermcap -o $(CH_NAME) $(CH_OBJ) -L.$(LIBFT) $(INCLUDES)

$(PS_NAME):
	@make -sC ./lib/libft/
	@$(CC)  -c $(FLAG) $(PS_SRC) $(INCLUDES)
	@$(CC)  -ltermcap -o $(PS_NAME) $(PS_OBJ) -L.$(LIBFT) $(INCLUDES)

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
