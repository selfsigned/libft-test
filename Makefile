# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: xperrin <xperrin@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/04/04 23:57:19 by xperrin           #+#    #+#              #
#    Updated: 2018/05/28 02:20:06 by xperrin          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft-test
CFLAGS = -Wextra -Werror -g

LIBDIR = ../
LIBINC = -I$(LIBDIR)/includes
LIBAR = $(LIBDIR)/libft.a

INCDIR = includes
INCFILES = libft_test.h
INCFULL = $(addprefix $(INCDIR)/, $(INCFILES))
INC = $(addprefix -I, $(INCDIR)) $(LIBINC)
SRCDIR = src

SRC = main.c \
      sort_test.c

VPATH= $(SRCDIR)
OBJDIR = obj
OBJ = $(addprefix $(OBJDIR)/, $(SRC:.c=.o))

.PHONY: all libft clean fclean re

all: $(NAME)

libft:
	@$(MAKE) -C $(LIBDIR) --no-print-directory

$(NAME): $(OBJ) | libft
	$(CC) $(CFLAGS) -o $@ $^ $(LIBAR)

$(OBJDIR):
	mkdir -p $(OBJDIR)

$(OBJDIR)/%.o: %.c $(INCFULL) | $(OBJDIR)
	$(CC) $(CFLAGS) -c -o $@ $< $(INC)

clean:
	@$(MAKE) -C $(LIBDIR) clean --no-print-directory
	$(RM) -r $(OBJDIR)

fclean:
	@$(MAKE) -C $(LIBDIR) fclean --no-print-directory
	$(RM) -r $(OBJDIR) $(NAME)

re:
	@$(MAKE) --no-print-directory fclean
	@$(MAKE) --no-print-directory
