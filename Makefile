# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ebenoist <ebenoist@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/10/27 10:47:12 by ebenoist          #+#    #+#              #
#    Updated: 2025/10/28 15:45:36 by ebenoist         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		= cub3d
BONUS_NAME	= cub3d_bonus
CC			= cc
CFLAGS		= -Wall -Werror -Wextra -g -Iincludes
AR			= ar
ARFLAGS		= rcs
OBJ_DIR		= obj
FILES	=	main.c\
			check_arg.c\
			error.c\
			init_map.c\
			end_of_programme.c\
			parsing_map.c\
			parsing_map2.c\

				
HEADER		= includes/cub3d.h

BONUS_SRC	= 

SRC_DIR		= srcs
SRCS		= $(addprefix $(SRC_DIR)/, $(FILES))

OBJ = $(patsubst $(SRC_DIR)/%.c,$(OBJ_DIR)/%.o,$(SRCS))

BONUS_OBJS	= $(BONUS_SRCS:%.c=$(OBJ_DIR)/%.o)

LIBFT_PATH	= ./libft
LIBFT		= $(LIBFT_PATH)/libft.a

RESET 		= \033[0m
GREEN 		= \033[0;32m
BLUE   		= \033[0;34m
YELLOW		= \033[1;33m

all: message $(NAME)

bonus : $(BONUS_NAME)
	
message:
	@printf "$(GREEN)compilation Cube3D...$(RESET)\n"

$(NAME): $(OBJ)
	@$(MAKE) --no-print-directory -C $(LIBFT_PATH)
	@$(CC) $(CFLAGS) $(OBJ) $(LIBFT) -o $(NAME) -lreadline
	@printf "$(GREEN)cube3d complete$(RESET)\n"

$(BONUS_NAME): $(BONUS_OBJS)
	@$(MAKE) --no-print-directory -C $(LIBFT_PATH)
	@$(CC) $(CFLAGS) $(BONUS_OBJS) $(LIBFT) -o $(BONUS_NAME)
	@printf "$(GREEN)cub3d_bonus complete$(RESET)\n"
	
$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c $(HEADER)
	@mkdir -p $(dir $@)
	@printf "$(YELLOW)Compiling $(notdir $<)$(RESET)\n"
	@$(CC) $(CFLAGS) -c $< -o $@

clean:
	@printf "$(BLUE)Cleaning objects$(RESET)\n"
	@rm -f $(OBJ) $(BONUS_OBJS)
	@$(MAKE) --no-print-directory -C $(LIBFT_PATH) clean

fclean: clean
	@printf "$(BLUE)Cleaning all$(RESET)\n"
	@rm -f $(NAME) $(BONUS_NAME)
	@$(MAKE) --no-print-directory -C $(LIBFT_PATH) fclean

re: fclean all
	@printf "$(GREEN)Recompil de Cub3D...$(RESET)\n"

.PHONY: all clean fclean re
