# **************************************************************************** #
#                                                                              #
#                                                         ::::::::             #
#    Makefile                                           :+:    :+:             #
#                                                      +:+                     #
#    By: cherrewi <cherrewi@student.codam.nl>         +#+                      #
#                                                    +#+                       #
#    Created: 2022/10/24 14:31:32 by cherrewi      #+#    #+#                  #
#    Updated: 2023/02/08 15:29:08 by cherrewi      ########   odam.nl          #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a
SRCS = ft_printf.c ft_printf_utils.c
OBJS = $(addprefix $(OBJDIR)/, $(SRCS:.c=.o))
OBJDIR = objects
FLAGS = -Wall -Wextra -Werror
LIBFTDIR = libft
LIBFTNAME = libft.a

all: $(NAME)

$(NAME): $(OBJS) $(LIBFTDIR)/$(LIBFTNAME)
	cp $(LIBFTDIR)/$(LIBFTNAME) $(NAME)
	ar rc $(NAME) $(OBJS)

$(LIBFTDIR)/$(LIBFTNAME):
	cd $(LIBFTDIR) ; make bonus

$(OBJDIR):
	mkdir $(OBJDIR)

$(OBJDIR)/%.o: %.c $(OBJDIR)
	$(CC) -c $(FLAGS) $< -o $@ -I ./$(LIBFTDIR)

clean:
	rm -rf $(OBJDIR)
	cd $(LIBFTDIR) ; make clean

fclean:
	rm -rf $(OBJDIR)
	rm -f $(NAME)
	cd $(LIBFTDIR) ; make fclean

re: fclean all

test: $(NAME)
	$(CC) $(NAME) tests/test_ft_printf.c -o test.out 
	./test.out

.PHONY: all clean fclean re
