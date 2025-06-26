# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: aneitenb <aneitenb@student.fi>             +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/03/18 11:52:04 by aneitenb          #+#    #+#              #
#    Updated: 2025/06/18 11:02:10 by aneitenb         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = DreamJob

CC = c++
CFLAGS = -Wall -Wextra -Werror
SRCS =  main.cpp \
		Bureaucrat.cpp \
		AForm.cpp \
		PresidentialPardonForm.cpp \
		RobotomyRequestForm.cpp \
		ShrubberyCreationForm.cpp
OBJS = $(SRCS:.cpp=.o)
RM = rm -rf
GREEN= "\033[32;1m
RESET= \033[0m"

all: $(NAME)

%.o: %.cpp
	@$(CC) $(CFLAGS) -o $@ -c $<

$(NAME): $(OBJS)
	@$(CC) $(CFLAGS) $(OBJS) -o $(NAME)
	@echo ${GREEN}Program DreamJob is Ready!${RESET}

clean:
	@$(RM) $(OBJS) 
	@echo ${GREEN}Cleaned files${RESET}

fclean: clean
	@$(RM) $(NAME)
	@$(RM) *_shrubbery
	@echo ${GREEN}Program and output files removed${RESET}

re: fclean all

.PHONY: all clean fclean re 