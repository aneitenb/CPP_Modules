# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: aneitenb <aneitenb@student.hive.fi>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/10/02 15:26:48 by aneitenb          #+#    #+#              #
#    Updated: 2024/11/12 13:51:47 by aneitenb         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = ClapTrap
HEADERS	= -I ./include

CC = c++
CFLAGS = -Wall -Wextra -Werror
SRCS =  main.cpp \
		ClapTrap.cpp
OBJS = $(SRCS:.cpp=.o)
RM = rm -rf

all: $(NAME)

%.o: %.cpp
	@$(CC) $(CFLAGS) -o $@ -c $< $(HEADERS)

$(NAME): $(OBJS)
	@$(CC) $(CFLAGS) $(OBJS) $(HEADERS) -o $(NAME)
	@echo "\033[32;1mProgram ClapTrap is Ready!\033[0m"

clean:
	@$(RM) $(OBJS) 
	@echo "\033[32;1mCleaned files\033[0m"

fclean: clean
	@$(RM) $(NAME)
	@echo "\033[32;1mProgram removed\033[0m"

re: fclean all

.PHONY: all clean fclean re 