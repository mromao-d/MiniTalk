# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mromao-d <mromao-d@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/05/14 19:24:36 by mromao-d          #+#    #+#              #
#    Updated: 2023/05/21 14:32:31 by mromao-d         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CFLAGC = -Wall -Wextra -Werror -g
CC = cc
c_src = minitalk_utils.c
cb_src = minitalk_utils_bonus.c
c_obj=$(c_src:.c=.o)
cb_obj=$(cb_src:.c=.o)
server = server 
client = client
server_bonus = server_bonus
client_bonus = client_bonus

all: $(server) $(client)

bonus:	$(server_bonus) $(client_bonus)


$(server_bonus):$(cb_obj) minitalk_bonus.h
	$(CC) $(CFLAGS) server_bonus.c $(cb_obj) -o $(server_bonus) -fsanitize=address
$(client_bonus):$(cb_obj) minitalk_bonus.h
	$(CC) $(CFLAGS) client_bonus.c $(cb_obj) -o $(client_bonus) -fsanitize=address
%.o:%.c
	$(CC) $(CFLAGS) -c $^ -o $@

$(server):$(c_obj) minitalk.h
	$(CC) $(CFLAGS) server.c $(c_obj) -o $(server) -fsanitize=address
$(client):$(c_obj) minitalk.h
	$(CC) $(CFLAGS) client.c $(c_obj) -o $(client) -fsanitize=address
%.o:%.c
	$(CC) $(CFLAGS) -c $^ -o $@

clean:
	rm -rf $(c_obj) $(cb_obj)
fclean: clean
	rm -rf $(client) $(server) 
	rm -rf $(client_bonus) $(server_bonus)
re: fclean all
rebonus: fclean bonus