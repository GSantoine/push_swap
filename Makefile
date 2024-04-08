# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: agras <agras@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/07/26 17:44:07 by agras             #+#    #+#              #
#    Updated: 2022/08/02 15:33:07 by agras            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

INCLUDES			=	includes/

NAME				=	push_swap
CC					=	cc
RM					=	rm -rf
CFLAGS				=	-Wall -Wextra -Werror

SRCS		= 	src/main.c\
				src/basic_sort.c\
				src/exit.c\
				src/init_sorting.c\
				src/lists_management.c\
				src/lists_management2.c\
				src/lists_management3.c\
				src/push.c\
				src/radix_sort.c\
				src/rotate.c\
				src/rrotate.c\
				src/simple_sort.c\
				src/swap.c\
				src/utils.c\
				src/split.c\
				src/parse.c

OBJS				=	$(SRCS:.c=.o)

all:                ${NAME}

${NAME}: $(OBJS)
					$(CC) $(CFLAGS) $(OBJS) -o $(NAME)

%.o: %.c $(INCLUDES)/prototypes.h
	$(CC) $(CFLAGS) -c $< -o $@

clean:
					$(RM) $(OBJS)

fclean: clean
					$(RM) push_swap

re:					fclean all

.PHONY:				all clean fclean re
