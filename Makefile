# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: prippa <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/11/13 14:20:39 by prippa            #+#    #+#              #
#    Updated: 2017/11/13 14:21:04 by prippa           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		=	libft.a

CC			=	gcc -Wall -Werror -Wextra

INC_PATH	=	./includes/
SRC_PATH	=	./source/
OBJ_PATH 	= 	./obj/

HEAD_NAME	=	libft.h get_next_line.h

SRC_NAME	= 	ft_atoi.c ft_bzero.c ft_isalnum.c ft_isalpha.c\
			ft_isascii.c ft_isdigit.c ft_islowercase.c ft_isprint.c ft_isspace.c\
			ft_isstralpha.c ft_isstrdigit.c ft_isstrlowercase.c ft_isstruppercase.c\
			ft_isuppercase.c ft_itoa.c ft_lstadd.c ft_lstdel.c ft_lstdelone.c\
			ft_lstiter.c ft_lstmap.c ft_lstnew.c ft_memalloc.c\
			ft_memccpy.c ft_memchr.c ft_memcmp.c ft_memcpy.c\
			ft_memdel.c ft_memmove.c ft_memset.c ft_putchar.c\
			ft_putchar_fd.c ft_putendl.c ft_putendl_fd.c ft_putnbr.c\
			ft_putnbr_fd.c ft_putstr.c ft_putstr_fd.c ft_strcat.c\
			ft_strchr.c ft_strclr.c ft_strcmp.c ft_strcpy.c\
			ft_strdel.c ft_strdup.c ft_strequ.c ft_striter.c\
			ft_striteri.c ft_strjoin.c ft_strlcat.c ft_strlen.c\
			ft_strmap.c ft_strmapi.c ft_strncat.c ft_strncmp.c\
			ft_strncpy.c ft_strnequ.c ft_strnew.c ft_strnstr.c\
			ft_strrchr.c ft_strsplit.c ft_strstr.c ft_strsub.c\
			ft_strtrim.c ft_tolower.c ft_tostrlowercase.c ft_tostruppercase.c\
			ft_toupper.c\
			get_next_line.c

OBJ_NAME 	= 	$(SRC_NAME:.c=.o)

OBJ 		= 	$(addprefix $(OBJ_PATH),$(OBJ_NAME))
INC_I 		= 	$(addprefix -I,$(INC_PATH))
INC_H 		= 	$(addprefix $(INC_PATH),$(HEAD_NAME))

all: $(NAME)

$(NAME): $(OBJ)
	@ar rc $@ $^
	@ranlib $@
	@echo "Compiling" [ $(NAME) ]

$(OBJ_PATH)%.o: $(SRC_PATH)%.c $(INC_H)
	@mkdir -p $(OBJ_PATH)
	@$(CC) $(INC_I) -c -o $@ $< 
	@echo "Linking" [ $< ]

clean:
	@rm -rf $(OBJ_PATH)
	@echo "Cleaning .o files"

fclean: clean
	@rm -f $(NAME)
	@echo "Clean" [ $(NAME) ]

re: fclean all

.PHONY: all clean fclean re
