NAME = push_swap

LIBFT_DIR = libft/
LIBFT_NAME = $(LIBFT_DIR)libft.a
HEADER = $(LIBFT_DIR)libft.h

CC = cc
FLAGS = -Wall -Werror -Wextra

SRCS =	main.c				\
		nodes.c				\
		debug.c				\
		push.c				\
		swap.c				\
		rotate.c			\
		reverse_rotate.c	\
		value_to_index.c	\
		args.c				\
		args_utils.c		\
		solution.c			\

OBJS_DIR = obj/
OBJS = $(SRCS:%.c=$(OBJS_DIR)%.o)

.PHONY: all
all: $(NAME)

$(LIBFT_NAME):
	@$(MAKE) -sC $(LIBFT_DIR)

$(NAME): Makefile $(OBJS) $(LIBFT_NAME)
	@$(MAKE) -sC $(LIBFT_DIR)
	@$(CC) $(FLAGS) $(OBJS) -L$(LIBFT_DIR) $(LIBFT_NAME) -o $(NAME)
	@echo "$(GREEN)$(BOLD)\nCompilation successful!$(RESET)"
	@echo "$(CYAN)  └─ Ready to run: ./$(NAME)\n$(RESET)"

$(OBJS_DIR)%.o: %.c $(HEADER) Makefile $(LIBFT_NAME)
	@mkdir -p $(OBJS_DIR)
	@echo "$(MAGENTA)$(BOLD)[Compiling...]$(RESET) $<"
	@$(CC) $(FLAGS) -c $< -o $@

.PHONY: clean
clean:
	@rm -rf $(OBJS_DIR) $(OBJS)
	@$(MAKE) clean -sC $(LIBFT_DIR)
	@echo "$(RED)$(BOLD)\nCleaning up project files...$(RESET)"
	@echo "$(YELLOW)  ├─ Removing object files$(RESET)"
	@echo "$(YELLOW)  └─ Cleaning libft$(RESET)"

.PHONY: fclean
fclean: clean
	@$(MAKE) fclean -sC $(LIBFT_DIR)
	@$(RM) $(NAME)
	@echo "$(RED)$(BOLD)\nFull clean-up completed:$(RESET)"
	@echo "$(YELLOW)  ├─ Removed object files and directories$(RESET)"
	@echo "$(YELLOW)  ├─ Cleaned libft$(RESET)"
	@echo "$(YELLOW)  └─ Deleted executable: $(NAME)\n$(RESET)"

.PHONY: re
re: fclean all

# ************************* COLORS ************************* #
BLACK = \033[30m
RED = \033[31m
GREEN = \033[32m
YELLOW = \033[33m
BLUE = \033[34m
MAGENTA = \033[35m
CYAN = \033[36m
WHITE = \033[37m
BOLD = \033[1m
RESET = \033[0m
