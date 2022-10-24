# **************************************************************************** #
#                                                                              #
#                                                         ::::::::             #
#    Makefile                                           :+:    :+:             #
#                                                      +:+                     #
#    By: cherrewi <cherrewi@student.codam.nl>         +#+                      #
#                                                    +#+                       #
#    Created: 2022/10/24 14:31:32 by cherrewi      #+#    #+#                  #
#    Updated: 2022/10/24 15:22:53 by cherrewi      ########   odam.nl          #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a
SRCS = ft_printf.c validations.c
OBJS = $(SRCS:.c=.o)
FLAGS = -Wall -Wextra -Werror
LIBFTDIR = libft
LIBFTNAME = libft.a

all: $(NAME)

$(NAME): $(OBJS) $(LIBFTDIR)/$(LIBFTNAME)
	ar rc $(NAME) $(OBJS) $(LIBFTDIR)/$(LIBFTNAME)

$(LIBFTDIR)/$(LIBFTNAME):
	cd $(LIBFTDIR) ; make

%.o: %.c
	$(CC) -c $(FLAGS) $< -o $@ -I ./$(LIBFTDIR)

clean:
	rm -f $(OBJS)
	cd $(LIBFTDIR) ; make clean

fclean:
	rm -f $(OBJS)
	rm -f $(NAME)
	cd $(LIBFTDIR) ; make fclean

re: fclean all

test: $(NAME)
	$(CC) $(NAME) tests/main.c -o test.out -I ./$(LIBFTDIR) 
	./test.out

.PHONY: all clean fclean re
