NAME = convert
HEADERS	= -I ./include

CC = c++
CFLAGS = -Wall -Wextra -Werror
SRCS =  main.cpp \
		ScalarConverter.cpp
OBJS = $(SRCS:.cpp=.o)
RM = rm -rf
GREEN= "\033[32;1m
RESET= \033[0m"

all: $(NAME)

%.o: %.cpp
	@$(CC) $(CFLAGS) -o $@ -c $< $(HEADERS)

$(NAME): $(OBJS)
	@$(CC) $(CFLAGS) $(OBJS) $(HEADERS) -o $(NAME)
	@echo ${GREEN}Program convert is Ready!${RESET}

clean:
	@$(RM) $(OBJS) 
	@echo ${GREEN}Cleaned files${RESET}

fclean: clean
	@$(RM) $(NAME)
	@echo ${GREEN}Program removed${RESET}

re: fclean all

.PHONY: all clean fclean re 
