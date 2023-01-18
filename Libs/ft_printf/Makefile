# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: fbily <fbily@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/05/26 15:41:02 by fbily             #+#    #+#              #
#    Updated: 2022/12/05 16:12:55 by fbily            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libprintf.a

SRC_PATH = ./srcs/
SRC = ft_printf.c \
		ft_print_hexa.c \
		ft_print_int.c \
		ft_print_ptr.c \
		ft_print_string.c \
		ft_printf_fd.c \
		ft_print_hexa_fd.c \
		ft_print_int_fd.c \
		ft_print_ptr_fd.c \
		ft_print_string_fd.c \

SRCS = $(addprefix ${SRC_PATH}, ${SRC})

OBJ_PATH	= obj/
OBJ = ${SRC:.c=.o}

OBJS	= $(addprefix $(OBJ_PATH), $(OBJ))

INC = -I./includes/

DEPS = $(addprefix ${OBJ_PATH}, ${SRC:.c=.d})

CC = gcc

CFLAGS = -Wall -Wextra -Werror -MMD -MP

RM = rm -rf

####### COLORS #######

GREEN = "\033[92m"
CYAN = "\033[96m"
BOLD = "\033[1m"
NC = "\033[0m"
#Reset : NC = No Colors

all : ${NAME}

${NAME} : ${OBJS}
	@ar rc ${NAME} $^
	@echo ${CYAN}${BOLD}Printf ${NC}[${GREEN}OK${NC}]

$(OBJ_PATH)%.o: $(SRC_PATH)%.c
	@mkdir -p ${OBJ_PATH}
	@${CC} ${CFLAGS} ${INC} -o $@ -c $<

clean :
	@${RM} ${OBJ_PATH}

fclean : clean
	@${RM} ${NAME}
	
re : fclean all

-include ${DEPS}

.PHONY: all clean fclean re