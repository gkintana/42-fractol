# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gkintana <gkintana@student.42abudhabi.ae>  +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/09/28 18:55:33 by gkintana          #+#    #+#              #
#    Updated: 2022/01/29 10:51:03 by gkintana         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		=	libft.a

INC_DIR		=	include
SRC_DIR		=	sources
OBJ_DIR		=	objects
EXT_DIR		=	extras

SRCS		=	ft_isalpha.c \
				ft_isdigit.c \
				ft_isalnum.c \
				ft_isascii.c \
				ft_isprint.c \
				ft_strlen.c \
				ft_memset.c \
				ft_bzero.c \
				ft_memcpy.c \
				ft_memmove.c \
				ft_strlcpy.c \
				ft_strlcat.c \
				ft_toupper.c \
				ft_tolower.c \
				ft_strchr.c \
				ft_strrchr.c \
				ft_strncmp.c \
				ft_memchr.c \
				ft_memcmp.c \
				ft_strnstr.c \
				ft_atoi.c \
				ft_calloc.c \
				ft_strdup.c \
				ft_substr.c \
				ft_strjoin.c \
				ft_strtrim.c \
				ft_split.c \
				ft_itoa.c \
				ft_strmapi.c \
				ft_striteri.c \
				ft_putchar_fd.c \
				ft_putstr_fd.c \
				ft_putendl_fd.c \
				ft_putnbr_fd.c
OBJ_SRC		=	$(addprefix $(OBJ_DIR)/, $(SRCS:%c=%o))

BONUS		=	ft_lstnew.c \
				ft_lstadd_front.c \
				ft_lstsize.c \
				ft_lstlast.c \
				ft_lstadd_back.c \
				ft_lstdelone.c \
				ft_lstclear.c \
				ft_lstiter.c \
				ft_lstmap.c
OBJ_BONUS	=	$(addprefix $(OBJ_DIR)/, $(BONUS:%c=%o))

EXTRA		=	ft_atof.c \
				ft_isspace.c \
				ft_strcmp.c \
				ft_swap.c
OBJ_EXTRA	=	$(addprefix $(OBJ_DIR)/, $(EXTRA:%c=%o))

LIB_AR		=	ar rcs
CC			=	gcc
CFLAGS		=	-Wall -Wextra -Werror
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
				$(CC) $(CFLAGS) -I $(INC_DIR) -c $< -o $@

$(OBJ_DIR)/%.o : $(EXT_DIR)/%.c
				@mkdir -p $(OBJ_DIR)
				@printf $(CYAN)
				$(CC) $(CFLAGS) -I $(INC_DIR) -c $< -o $@

all:			$(NAME)

$(NAME):		$(OBJ_SRC) $(OBJ_EXTRA)
				@echo $(YELLOW)"Archiving object files"$(DEFAULT)
				@$(LIB_AR) $(NAME) $(OBJ_SRC) $(OBJ_EXTRA)
				@echo $(GREEN)"Libft Ready 😎"$(DEFAULT)

bonus:			$(OBJ_BONUS)
				@echo $(YELLOW)"Archiving linked list functions"$(DEFAULT)
				@$(LIB_AR) $(NAME) $(OBJ_BONUS)
				@echo $(GREEN)"Linked List Functions Ready 😉"$(DEFAULT)

clean:
				@$(RM) $(OBJ_DIR)
				@echo $(RED)"Deleted libft object files & object folder 🗃️"$(DEFAULT)

fclean:			clean
				@$(RM) $(NAME)
				@echo $(RED)"Deleted libft.a 😱"$(DEFAULT)

re:				fclean all

norm:
				@echo $(DEFAULT)$(YELLOW_BU)"libft .c files"$(DEFAULT)$(CYAN)
				@norminette -R CheckForbiddenSourceHeader $(SRC_DIR)/*.c
				@norminette -R CheckForbiddenSourceHeader $(EXT_DIR)/*.c
				@echo $(DEFAULT)$(YELLOW_BU)"libft .h files"$(DEFAULT)$(CYAN)
				@norminette -R CheckDefine $(INC_DIR)/*.h

.PHONY:			all clean fclean norm re bonus
