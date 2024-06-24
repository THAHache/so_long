# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jperez-r <jperez-r@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/01/11 19:24:26 by jperez-r          #+#    #+#              #
#    Updated: 2024/06/24 15:45:04 by jperez-r         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS	=	so_long.c \
		error_so_long.c \
		initialize_structs.c \
		read_map.c \
		count_map.c \
		check_map.c \
		check_path.c \
		win.c \
		draw_map.c \
		move.c \
		draw.c

LIBFT	=	libft

GNL		=	gnl/

# MAC
#MLX	=	-I libft -L libft \
#			-I /usr/local/include -L /usr/local/lib \
#			-l mlx -l ft -framework OpenGL -framework Appkit

# LINUX
#MLX		=	-I libft -L libft \
#			-I /usr/local/include -L /usr/local/lib \
#			-l -Lmlx_linux -lmlx_Linux -L/usr/lib -Imlx_linux -lXext -lX11 -lm -lz
MLX		=	mlx_linux

# La compilación debería de ser gcc "archivos so_long" -Lminilibx-linux -lmlx_Linux -lX11 -lXext

OBJS	=	${SRCS:.c=.o}

CC		=	gcc

CFLAGS	=	-Wall -Wextra -Werror

MLXFLAGS =	-lmlx_Linux -lX11 -lXext -lm -lz

SANI = -fsanitize=address

RED		=	\033[31m
GREEN	=	\033[32m
YELLOW	=	\033[33m
RESET	=	\033[0m

NAME	=	so_long

.o:	.c
			${CC} ${CFLAGS} -Ilibft -Imlx_linux -O3 -c $< -o $@

${NAME}	:	${OBJS}
			@make -C ${LIBFT}
			@if [ -f ${LIBFT}/libft.a ]; then \
				echo "${GREEN}********* CREATION SUCCESS *********${RESET}"; \
			else \
				echo "${RED}********* FAIL CREATION *********${RESET}"; \
			fi
			@make -C ${MLX}
			@if [ -f ${MLX}/libmlx.a ]; then \
				echo "${GREEN}********* CREATION SUCCESS *********${RESET}"; \
			else \
				echo "${RED}********* FAIL CREATION *********${RESET}"; \
			fi
#			@${CC} ${OBJS} -L${LIBFT} -L${MLX} -lft -o ${NAME}
#			@${CC} ${OBJS} -L${LIBFT} -L${MLX} -L${MXFLAGS} -lft -o ${NAME}
			@${CC} ${CFLAGS} ${SANI} ${OBJS} -L${LIBFT} -lft -Ilibft -Imlx_linux -L${MLX} ${MLXFLAGS} -o ${NAME}


all		:	${NAME}

clean	:
			@make -C ${LIBFT} clean
			@make -C ${MLX} clean
			rm -f ${OBJS}
			@echo "${YELLOW}********* CLEAN SUCCESS *********${RESET}"; \

fclean	:	clean
			@make -C ${LIBFT} fclean
			rm -f ${NAME}
			@echo "${YELLOW}********* FCLEAN SUCCESS *********${RESET}"; \

re		:	fclean all

.PHONY	:	all clean fclean re
