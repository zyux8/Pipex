# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ohaker <ohaker@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/02/10 16:48:23 by ohaker            #+#    #+#              #
#    Updated: 2025/03/14 18:12:05 by ohaker           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = pipex.a
CFLAGS = -Wall -Wextra -Werror

SRC = \
	pipex.c \
	pipex_helper.c

OBJ = $(SRC:.c=.o)

all: $(NAME)

$(NAME): $(OBJ)
	make re -C ./libft
	gcc $(CFLAGS) $(OBJ) -Llibft -lft -o $(NAME) 

%.o: %.c
	gcc $(CFLAGS) -c $< -o $@

clean:
	make clean -C ./libft
	rm -rf $(OBJ)

fclean: clean
	make fclean -C ./libft
	rm -rf $(NAME)

re: fclean all

party:
	@printf "\033c"
	@echo "\n\033[35m♪┏(・o･)┛♪"
	@sleep 1
	@printf "\033c"
	@echo "\033[1;33m♪┗(・o･)┓♪"
	@sleep 1
	@printf "\033c"
	@echo "\n\033[36m♪┏(・o･)┛♪"
	@sleep 1
	@printf "\033c"
	@echo "\033[34m♪┗(・o･)┓♪\n"

mygit:
	@bash -c ' \
	cp -ru ~/Projects/Pipex ~/GitHub && \
	cd ../../GitHub/Pipex && \
	git add Pipex && \
	git status && \
	read -p "Commitment message: " input; \
	git commit -m "$$input" && \
	git push origin main'

.PHONY: all clean fclean re party