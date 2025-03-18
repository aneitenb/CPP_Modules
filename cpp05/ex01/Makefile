# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: aneitenb <aneitenb@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/03/18 11:52:04 by aneitenb          #+#    #+#              #
#    Updated: 2025/03/18 15:59:02 by aneitenb         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = DreamJob
HEADERS	= -I ./include

CC = c++
CFLAGS = -Wall -Wextra -Werror
SRCS =  main.cpp \
		Bureaucrat.cpp \
		Form.cpp 
OBJS = $(SRCS:.cpp=.o)
RM = rm -rf
GREEN= "\033[32;1m
RESET= \033[0m"

all: $(NAME)

%.o: %.cpp
	@$(CC) $(CFLAGS) -o $@ -c $< $(HEADERS)

$(NAME): $(OBJS)
	@$(CC) $(CFLAGS) $(OBJS) $(HEADERS) -o $(NAME)
	@echo ${GREEN}Program DreamJob is Ready!${RESET}

clean:
	@$(RM) $(OBJS) 
	@echo ${GREEN}Cleaned files${RESET}

fclean: clean
	@$(RM) $(NAME)
	@echo ${GREEN}Program removed${RESET}

re: fclean all

.PHONY: all clean fclean re 