# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jperez-r <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/01/11 19:24:26 by jperez-r          #+#    #+#              #
#    Updated: 2024/04/23 16:40:11 by jperez-r         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS	=	so_long.c \
			error_so_long.c \
			can_read.c

LIBFT	=	libft/

GNL		=	gnl/

MLX	=	-I libft -L libft \
			-I /usr/local/include -L /usr/local/lib \
			-l mlx -l ft -framework OpenGL -framework Appkit

OBJS	=	${SRCS:.c=.o}

CC		=	gcc

CFLAGS	=	-Wall -Wextra -Werror

RED		=	\033[31m
GREEN	=	\033[32m
YELLOW	=	\033[33m
RESET	=	\033[0m

NAME	=	so_long

.o:	.c
			${CC} ${CFLAGS} -c $< -o $@

${NAME}	:	${OBJS}
			@make -C ${LIBFT}
			@if [ -f ${LIBFT}/libft.a ]; then \
				echo "${GREEN}********* CREATION SUCCESS *********${RESET}"; \
			else \
				echo "${RED}********* FAIL CREATION *********${RESET}"; \
			fi
			@${CC} ${OBJS} -L${LIBFT} -lft -o ${NAME} ${MLX}


all		:	${NAME}

clean	:
			@make -C ${LIBFT} clean
			rm -f ${OBJS}
			@echo "${YELLOW}********* CLEAN SUCCESS *********${RESET}"; \

fclean	:	clean
			@make -C ${LIBFT} fclean
			rm -f ${NAME}
			@echo "${YELLOW}********* FCLEAN SUCCESS *********${RESET}"; \

re		:	fclean all

.PHONY	:	all clean fclean re
