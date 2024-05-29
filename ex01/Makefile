# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ftholoza <ftholoza@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/02/16 14:01:59 by ftholoza          #+#    #+#              #
#    Updated: 2024/05/29 20:05:43 by ftholoza         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = c++
FLAGS = -std=c++98 -Wall -Wextra -Werror
SRC = contact_utils.cpp phone_book.cpp phone_book_utils.cpp
OBJ = $(SRC:.cpp=.o)
NAME = PhoneBook

all : $(NAME)

re : fclean $(NAME)

$(NAME) : $(OBJ)
	$(CC) $(FALGS) $(OBJ) -o $(NAME)
	
$(OBJ) : $(SRC)
	$(CC) $(FLAGS) -c $(SRC) phone_book.hpp

clean :
	rm -f $(OBJ) phone_book.hpp.gch
fclean : clean
	rm -rf $(NAME)