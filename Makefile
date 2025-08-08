# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ocviller <ocviller@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/08/02 18:09:08 by ocviller          #+#    #+#              #
#    Updated: 2025/08/09 01:03:09 by ocviller         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = so_long
BONUS_NAME = so_long_bonus

CC = gcc
CFLAGS = -Wall -Wextra -Werror -g
MLXFLAGS = -L./includes/minilibx-linux -lmlx -lXext -lX11 -lm

# Normal version
SRCDIR = srcs
OBJDIR = obj
SRCFILES = main.c parsing.c parsing2.c parsing3.c put_image.c handle_keys.c clear_all.c utils.c
SRCS = $(addprefix $(SRCDIR)/, $(SRCFILES))
OBJS = $(addprefix $(OBJDIR)/, $(SRCFILES:.c=.o))

# Bonus version
BONUS_SRCDIR = bonus/srcs
BONUS_OBJDIR = bonus/obj
BONUS_SRCFILES = main_bonus.c parsing_bonus.c parsing2_bonus.c parsing3_bonus.c put_image_bonus.c handle_keys_bonus.c clear_all_bonus.c utils_bonus.c menu_bonus.c find_walls_bonus.c find_wall2_bonus.c
BONUS_SRCS = $(addprefix $(BONUS_SRCDIR)/, $(BONUS_SRCFILES))
BONUS_OBJS = $(addprefix $(BONUS_OBJDIR)/, $(BONUS_SRCFILES:.c=.o))

# Libraries
LIBFT_DIR = includes/libft
LIBFT = $(LIBFT_DIR)/libft.a
MLX_DIR = includes/minilibx-linux
MLX = $(MLX_DIR)/libmlx.a

# Colors
GREEN = \033[0;32m
RED = \033[0;31m
BLUE = \033[0;34m
MAGENTA = \033[0;35m
NC = \033[0m

all: $(NAME)

bonus: $(BONUS_NAME)

$(NAME): $(OBJDIR) $(OBJS) $(LIBFT) $(MLX)
	@echo "$(BLUE)Linking $(NAME)...$(NC)"
	@$(CC) $(OBJS) -L$(LIBFT_DIR) -lft $(MLXFLAGS) -o $(NAME)
	@echo "$(GREEN)✓ $(NAME) compiled successfully!$(NC)"

$(BONUS_NAME): $(BONUS_OBJDIR) $(BONUS_OBJS) $(LIBFT) $(MLX)
	@echo "$(MAGENTA)Linking $(BONUS_NAME)...$(NC)"
	@$(CC) $(BONUS_OBJS) -L$(LIBFT_DIR) -lft $(MLXFLAGS) -o $(BONUS_NAME)
	@echo "$(GREEN)✓ $(BONUS_NAME) compiled successfully!$(NC)"

$(OBJDIR):
	@mkdir -p $(OBJDIR)

$(BONUS_OBJDIR):
	@mkdir -p $(BONUS_OBJDIR)

$(OBJDIR)/%.o: $(SRCDIR)/%.c
	@echo "$(BLUE)Compiling $<...$(NC)"
	@$(CC) $(CFLAGS) -Iincludes -I$(LIBFT_DIR) -I$(LIBFT_DIR)/get_next_line -I$(LIBFT_DIR)/ft_printf -I$(MLX_DIR) -c $< -o $@

$(BONUS_OBJDIR)/%.o: $(BONUS_SRCDIR)/%.c
	@echo "$(MAGENTA)Compiling bonus $<...$(NC)"
	@$(CC) $(CFLAGS) -Ibonus/includes -Iincludes -I$(LIBFT_DIR) -I$(LIBFT_DIR)/get_next_line -I$(LIBFT_DIR)/ft_printf -I$(MLX_DIR) -c $< -o $@

$(LIBFT):
	@echo "$(BLUE)Compiling libft...$(NC)"
	@make -C $(LIBFT_DIR)

$(MLX):
	@echo "$(BLUE)Compiling MiniLibX...$(NC)"
	@make -C $(MLX_DIR)

clean:
	@echo "$(RED)Cleaning object files...$(NC)"
	@rm -rf $(OBJDIR) $(BONUS_OBJDIR)
	@make clean -C $(LIBFT_DIR)

fclean: clean
	@echo "$(RED)Cleaning executables...$(NC)"
	@rm -f $(NAME) $(BONUS_NAME)
	@make fclean -C $(LIBFT_DIR)

re: fclean all

.PHONY: all bonus clean fclean re