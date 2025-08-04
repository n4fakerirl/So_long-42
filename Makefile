# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ocviller <ocviller@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/08/02 18:09:08 by ocviller          #+#    #+#              #
#    Updated: 2025/08/02 18:09:42 by ocviller         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = so_long

CC = gcc
CFLAGS = -Wall -Wextra -Werror -g
MLXFLAGS = -L$(MLX_DIR) -lmlx -lXext -lX11 -lm

SRCDIR = srcs
INCDIR = includes
OBJDIR = obj

SRCFILES = $(notdir $(wildcard $(SRCDIR)/*.c))
SRCS = $(addprefix $(SRCDIR)/, $(SRCFILES))
OBJS = $(addprefix $(OBJDIR)/, $(SRCFILES:.c=.o))

HEADERS = $(INCDIR)/so_long.h

LIBFT_DIR = $(INCDIR)/libft
LIBFT = $(LIBFT_DIR)/libft.a
GNL_DIR = $(LIBFT_DIR)/get_next_line
PRINTF_DIR = $(LIBFT_DIR)/ft_printf

MLX_DIR = $(INCDIR)/minilibx-linux
MLX = $(MLX_DIR)/libmlx.a

GREEN = \033[0;32m
RED = \033[0;31m
BLUE = \033[0;34m
YELLOW = \033[0;33m
NC = \033[0m

all: $(NAME)

$(NAME): $(OBJDIR) $(OBJS) $(LIBFT) $(MLX)
	@echo "$(BLUE)Linking $(NAME)...$(NC)"
	@echo "$(YELLOW)Source files found: $(SRCFILES)$(NC)"
	@$(CC) $(OBJS) -L$(LIBFT_DIR) -lft $(MLXFLAGS) -o $(NAME)
	@echo "$(GREEN)✓ $(NAME) compiled successfully!$(NC)"

$(OBJDIR):
	@mkdir -p $(OBJDIR)

$(OBJDIR)/%.o: $(SRCDIR)/%.c $(HEADERS)
	@echo "$(YELLOW)Compiling $<...$(NC)"
	@$(CC) $(CFLAGS) -I$(INCDIR) -I$(LIBFT_DIR) -I$(GNL_DIR) -I$(PRINTF_DIR) -I$(MLX_DIR) -c $< -o $@

$(LIBFT):
	@echo "$(BLUE)Compiling libft...$(NC)"
	@make -C $(LIBFT_DIR)

$(MLX):
	@echo "$(BLUE)Checking MiniLibX...$(NC)"
	@if [ ! -f $(MLX) ]; then \
		echo "$(BLUE)Compiling MiniLibX...$(NC)"; \
		make -C $(MLX_DIR); \
	fi

clean:
	@echo "$(RED)Cleaning object files...$(NC)"
	@rm -rf $(OBJDIR)
	@make clean -C $(LIBFT_DIR)

fclean: clean
	@echo "$(RED)Cleaning executable...$(NC)"
	@rm -f $(NAME)
	@make fclean -C $(LIBFT_DIR)

re: fclean all

.PHONY: all clean fclean re