# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: kobe <kobe@student.42.fr>                  +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/11/16 09:11:12 by thodavid          #+#    #+#              #
#    Updated: 2025/11/28 14:15:53 by kobe             ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

#####
#Var#
#####
NAME	= a.out
FLAGS	= -Wall -Wextra -Werror -std=c++98
SRCDIR	= src
OBJDIR	= obj
INCLUDES= -I.

#####
#Src#
#####
SRC		= main ClapTrap
SRCS	= $(addprefix $(SRCDIR)/,$(addsuffix .cpp,$(SRC)))
OBJ		= $(patsubst $(SRCDIR)/%.cpp,$(OBJDIR)/%.o,$(SRCS))

#######
#Rules#
#######
all: $(NAME)

$(NAME): $(OBJ)
	c++ $(FLAGS) $(OBJ) -o $(NAME)
	@echo "✅ ready ✅"

$(OBJDIR)/%.o: $(SRCDIR)/%.cpp
	@mkdir -p $(dir $@)
	c++ $(FLAGS) $(INCLUDES) -c $< -o $@

clean:
	rm -rf $(OBJDIR)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
