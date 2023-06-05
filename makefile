# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ahammout <ahammout@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/05/28 14:50:41 by ahammout          #+#    #+#              #
#    Updated: 2023/06/05 18:15:08 by ahammout         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = Cub3d

CC = cc

# CFLAGS = -Wall -Wextra -Werror

INCLUDES = includes/cub3d.h

LIBFT = libft/libft.a

SRCS =	srcs/main.c \
		srcs/parser.c \
		srcs/parser_tools.c \
		srcs/tools.c \
		srcs/parser_analyzer.c \
		get_next_line/get_next_line.c \

OBJS = $(SRCS:.c=.o)

%.o : %.c $(INCLUDES)
	$(CC) $(CFLAGS) -c $< -o $@

all : $(NAME)

$(NAME) : $(INCLUDES) $(OBJS)
	@make -C libft
	$(CC) $(CFLAGS) $(OBJS) $(LIBFT)   -o $(NAME)

clean:
	@make fclean -C libft
	@rm -fr $(OBJS)

fclean: clean
	@make fclean -C libft
	@rm -fr $(NAME)

re: fclean all