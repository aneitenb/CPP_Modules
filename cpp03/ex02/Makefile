# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: aneitenb <aneitenb@student.hive.fi>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/10/02 15:26:48 by aneitenb          #+#    #+#              #
#    Updated: 2024/11/09 16:22:25 by aneitenb         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = FragTrap
HEADERS	= -I ./include

CC = c++
CFLAGS = -Wall -Wextra -Werror
SRCS =  main.cpp \
		ClapTrap.cpp \
		ScavTrap.cpp \
		FragTrap.cpp
OBJS = $(SRCS:.cpp=.o)
RM = rm -f

all: $(NAME)

%.o: %.cpp
	@$(CC) $(CFLAGS) -o $@ -c $< $(HEADERS)

$(NAME): $(OBJS)
	@$(CC) $(CFLAGS) $(OBJS) $(HEADERS) -o $(NAME)
	@echo "\033[32;1mProgram FragTrap is Ready!\033[0m"

clean:
	@$(RM) $(OBJS) 
	@echo "\033[32;1mCleaned files\033[0m"

fclean: clean
	@$(RM) $(NAME)
	@echo "\033[32;1mProgram removed\033[0m"

re: fclean all

.PHONY: all clean fclean re 