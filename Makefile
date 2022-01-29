# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gkintana <gkintana@student.42abudhabi.ae>  +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/11/21 12:47:05 by gkintana          #+#    #+#              #
#    Updated: 2022/01/29 18:21:53 by gkintana         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		=	fractol

LIBFT_DIR	=	libft
LIBFT		=	libft.a

LIBX_DIR	=	libx
LIBX		=	libmlx.a
FRAMEWORK	=	-L $(LIBX_DIR) -lmlx -framework OpenGL -framework AppKit

INC_DIR		=	include
SRC_DIR		=	sources
OBJ_DIR		=	objects

SRCS		=	fractol.c \
				check.c \
				events.c \
				fractal_julia.c \
				fractal_mandelbrot.c \
				fractal_ship.c \
				render.c \
				util_events_key.c \
				util_events_mouse.c \
				util_render.c
OBJS		=	$(addprefix $(OBJ_DIR)/, $(SRCS:%c=%o))

CC			=	gcc
CFLAGS		=	-Wall -Wextra -Werror -Ofast
LIB_AR		=	ar rcs
RM			=	rm -rf

DEFAULT		=	"\033[0m"
RED			=	"\033[0;31m"
GREEN		=	"\033[1;32m"
YELLOW		=	"\033[0;33m"
YELLOW_BU	=	"\033[1;4;33m"
CYAN		=	"\033[3;36m"

$(OBJ_DIR)/%.o : $(SRC_DIR)/%.c
			@mkdir -p $(OBJ_DIR)
			@printf $(CYAN)
			$(CC) $(CFLAGS) -I $(INC_DIR) -I $(LIBX_DIR) -I $(LIBFT_DIR)/$(INC_DIR) -c $< -o $@

all:		$(NAME)

$(NAME):	$(LIBX) $(LIBFT) $(OBJS)
			@echo $(DEFAULT)$(YELLOW)"Compiling object files, libft, and minilibx"$(CYAN)
			@$(CC) $(CFLAGS) $(OBJS) $(FRAMEWORK) $(LIBFT_DIR)/$(LIBFT) -o $@
			@echo $(DEFAULT)$(GREEN)"Fract'ol Ready! 🥳"$(DEFAULT)

$(LIBFT):	
			@printf $(DEFAULT)
			@make -C $(LIBFT_DIR)

$(LIBX):
			@printf $(CYAN)
			@make -C $(LIBX_DIR)

bonus:		all

clean:
			@make -C $(LIBX_DIR) clean
			@echo $(RED)"Deleted libmlx object files 🗃️"$(DEFAULT)
			@echo $(RED)"Deleted libmlx.a 😱"$(DEFAULT)
			@make -C $(LIBFT_DIR) fclean
			@$(RM) $(OBJ_DIR)
			@echo $(RED)"Deleted fract'ol object files & object folder 🗃️"$(DEFAULT)

fclean:		clean
			@$(RM) $(NAME)
			@echo $(RED)"Deleted fract'ol executable 😱"$(DEFAULT)

norm:
			@make -C $(LIBFT_DIR) norm
			@echo $(DEFAULT)$(YELLOW_BU)"fractol .c files"$(DEFAULT)$(CYAN)
			@norminette -R CheckForbiddenSourceHeader $(SRC_DIR)/*.c
			@echo $(DEFAULT)$(YELLOW_BU)"fractol .h files"$(DEFAULT)$(CYAN)
			@norminette -R CheckDefine $(INC_DIR)/*.h

re:			fclean all

.PHONY:		all clean fclean re bonus
