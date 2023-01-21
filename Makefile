# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: fbily <fbily@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/11/23 18:47:35 by fbily             #+#    #+#              #
#    Updated: 2023/01/21 19:54:04 by fbily            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = cub3d

SRC_PATH = ./srcs/
SRC = 	main.c \
		parsing.c \
		clean.c \
		file_handler.c \
		colors_handler.c \
		textures_handler.c \

SRCS = $(addprefix ${SRC_PATH}, ${SRC})

OBJ_PATH	= obj/
OBJ = ${SRC:.c=.o}

OBJS	= $(addprefix $(OBJ_PATH), $(OBJ))

DEPS = $(addprefix ${OBJ_PATH}, ${SRC:.c=.d})

INC = -I./includes/ -I./Libs/Libft/includes/ -I./Libs/mlx_linux/

LIB = -L./Libs/Libft/ -lft -L./Libs/mlx_linux/ -lmlx -lXext -lX11 -lm -lz

CC = cc

CFLAGS = -Wall -Wextra -Werror -MMD -g3

RM = rm -rf

############ COLORS ############

GREEN = "\033[92m"
CYAN = "\033[96m"
BOLD = "\033[1m"
NC = "\033[0m"
# NC = No Colors (use for reset)

all : ${NAME}

${NAME} : ${OBJS}
	make --no-print-directory header
	@make --no-print-directory -C Libs/Libft
	@make --no-print-directory -C Libs/mlx_linux
	@${CC} ${CFLAGS} ${OBJS} ${LIB} -o ${NAME}
	@echo ${CYAN}${BOLD}Compilation ${NC}[${GREEN}OK${NC}]

$(OBJ_PATH)%.o: $(SRC_PATH)%.c
	@mkdir -p ${OBJ_PATH}
	@${CC} ${CFLAGS} ${INC} -o $@ -c $<

clean :
	@make $@ --no-print-directory -C ./Libs/Libft/
	@make $@ --no-print-directory -C ./Libs/mlx_linux/
	@${RM} ${OBJ_PATH}
	@echo ${CYAN}${BOLD}Objects cleaned${NC}

fclean : clean
	@make $@ --no-print-directory -C ./Libs/Libft/
	@${RM} ${NAME}
	@echo ${CYAN}${BOLD}Cleanning ${NC}[${GREEN}OK${NC}]

#debug : fclean
#	@make --no-print-directory CFLAGS+="-g3"

re : fclean all

#ASCII = ANSI Shadow
define HEADER
\033[92m

 ██████╗██╗   ██╗██████╗ ██████╗ ██████╗ 
██╔════╝██║   ██║██╔══██╗╚════██╗██╔══██╗
██║     ██║   ██║██████╔╝ █████╔╝██║  ██║
██║     ██║   ██║██╔══██╗ ╚═══██╗██║  ██║
╚██████╗╚██████╔╝██████╔╝██████╔╝██████╔╝
 ╚═════╝ ╚═════╝ ╚═════╝ ╚═════╝ ╚═════╝ 
                                         
\033[0m                                                                                                           
endef
export HEADER

header :
	clear
	@echo "$$HEADER"

-include ${DEPS}

.SECONDARY : ${OBJ} ${OBJ_PATH} ${OBJS}

.PHONY : all clean fclean re
