# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: aneitenb <aneitenb@student.hive.fi>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/09/20 15:18:17 by aneitenb          #+#    #+#              #
#    Updated: 2024/09/20 15:48:52 by aneitenb         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = braiiiiinnnnzzzzzz
HEADERS	= -I ./include

CC = c++
CFLAGS = -Wall -Wextra -Werror
SRCS =  main.cpp \
		newZombie.cpp	\
		randomChump.cpp	\
		Zombie.cpp
OBJS = $(SRCS:.cpp=.o)
RM = rm -f

all: $(NAME)

%.o: %.cpp
	@$(CC) $(CFLAGS) -o $@ -c $< $(HEADERS)

$(NAME): $(OBJS)
	@$(CC) $(CFLAGS) $(OBJS) $(HEADERS) -o $(NAME)
	@echo "\033[32;1mProgram braiiiiinnnnzzzzzz is Ready!\033[0m"

clean:
	@$(RM) $(OBJS) 
	@echo "\033[32;1mCleaned files\033[0m"

fclean: clean
	@$(RM) $(NAME)
	@echo "\033[32;1mProgram removed\033[0m"

re: fclean all

.PHONY: all clean fclean re 