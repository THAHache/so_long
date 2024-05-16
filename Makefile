# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jperez-r <jperez-r@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/01/11 19:24:26 by jperez-r          #+#    #+#              #
#    Updated: 2024/05/15 20:18:08 by jperez-r         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS	=	so_long.c \
			error_so_long.c \
			can_read.c

LIBFT	=	libft/

GNL		=	gnl/

# MAC
#MLX	=	-I libft -L libft \
#			-I /usr/local/include -L /usr/local/lib \
#			-l mlx -l ft -framework OpenGL -framework Appkit

# LINUX
#MLX		=	-I libft -L libft \
#			-I /usr/local/include -L /usr/local/lib \
#			-l -Lmlx_linux -lmlx_Linux -L/usr/lib -Imlx_linux -lXext -lX11 -lm -lz
MLX		=	minilibx-linux/

OBJS	=	${SRCS:.c=.o}

CC		=	gcc

CFLAGS	=	-Wall -Wextra -Werror

MLXFLAGS =	-lmlx -lXert -lX11

RED		=	\033[31m
GREEN	=	\033[32m
YELLOW	=	\033[33m
RESET	=	\033[0m

NAME	=	so_long

.o:	.c
			${CC} ${CFLAGS} -I/usr/include -Iminilibx-linux -O3 -c $< -o $@

${NAME}	:	${OBJS}
			@make -C ${LIBFT}
			@if [ -f ${LIBFT}/libft.a ]; then \
				echo "${GREEN}********* CREATION SUCCESS *********${RESET}"; \
			else \
				echo "${RED}********* FAIL CREATION *********${RESET}"; \
			fi
#			@make -C ${MLX}
#			@if [ -f ${MLX}/libmlx.a ]; then \
#				echo "${GREEN}********* CREATION SUCCESS *********${RESET}"; \
#			else \
#				echo "${RED}********* FAIL CREATION *********${RESET}"; \
#			fi
#			@${CC} ${OBJS} -L${LIBFT} -L${MLX} -lft -o ${NAME}
			@${CC} ${OBJS} -L${LIBFT} -L${MLX} -L${MXFLAGS} -lft -o ${NAME}


all		:	${NAME}

clean	:
			@make -C ${LIBFT} clean
#			@make -C ${MLX} clean
			rm -f ${OBJS}
			@echo "${YELLOW}********* CLEAN SUCCESS *********${RESET}"; \

fclean	:	clean
			@make -C ${LIBFT} fclean
			rm -f ${NAME}
			@echo "${YELLOW}********* FCLEAN SUCCESS *********${RESET}"; \

re		:	fclean all

.PHONY	:	all clean fclean re
