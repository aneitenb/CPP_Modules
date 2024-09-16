# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: aneitenb <aneitenb@student.hive.fi>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/09/13 15:33:25 by aneitenb          #+#    #+#              #
#    Updated: 2024/09/16 12:36:59 by aneitenb         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = megaphone
HEADERS	= -I ./include

CC = c++
CFLAGS = -Wall -Wextra -Werror
SRCS =  megaphone.cpp 
OBJS = $(SRCS:.cpp=.o)
RM = rm -f

all: $(NAME)

%.o: %.cpp
	@$(CC) $(CFLAGS) -o $@ -c $< $(HEADERS)

$(NAME): $(OBJS)
	@$(CC) $(CFLAGS) $(OBJS) $(HEADERS) -o $(NAME)
	@echo "\033[32;1mProgram is Ready!\033[0m"

clean:
	@$(RM) $(OBJS) 
	@echo "\033[32;1mCleaned files\033[0m"

fclean: clean
	@$(RM) $(NAME)
	@echo "\033[32;1mProgram removed\033[0m"

re: fclean all

.PHONY: all clean fclean re 
