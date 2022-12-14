# **************************************************************************** #
#                                                                              #
#                                                         ::::::::             #
#    Makefile                                           :+:    :+:             #
#                                                      +:+                     #
#    By: cherrewi <cherrewi@student.codam.nl>         +#+                      #
#                                                    +#+                       #
#    Created: 2022/10/24 14:31:32 by cherrewi      #+#    #+#                  #
#    Updated: 2022/10/28 10:02:56 by cherrewi      ########   odam.nl          #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a
SRCS = ft_printf.c write.c
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

.PHONY: all clean fclean re
