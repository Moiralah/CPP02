# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: huidris <huidris@student.42kl.edu.my>      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/07/31 23:24:00 by huidris           #+#    #+#              #
#    Updated: 2025/08/04 15:52:53 by huidris          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	= fixed

FLAGS	= -Wall -Wextra -Werror -std=c++98

CC		= c++

SRC		= $(wildcard *.cpp)

$(NAME):
		$(CC) $(FLAGS) $(SRC) -o $(NAME)

all: $(NAME)

clean:
	clear

fclean: clean
	rm -rf $(NAME)

re: fclean all

.PHONY: all clean fclean re
