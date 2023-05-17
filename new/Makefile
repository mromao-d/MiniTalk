# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mromao-d <mromao-d@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/05/14 19:24:36 by mromao-d          #+#    #+#              #
#    Updated: 2023/05/17 13:47:14 by mromao-d         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CFLAGC = -Wall -Wextra -Werror -g
CC = cc
c_src = minitalk_utils.c
c_obj=$(c_src:.c=.o)
cb_obj=$(cb_src:.c=.o)
#cb_src = minitalk_utils_bonus.c
server = server 
client = client
#server_bonus = server_bonus
#client_bonus = client_bonus
all: $(server) $(client)

#bonus:$(server_bonus) $(client_bonus)


#$(server_bonus):$(cb_obj) minitalk_bonus.h
#	$(CC) $(CFLAGS) server_bonus.c $(cb_obj) -o $(server_bonus) -fsanitize=address
$(client_bonus):$(cb_obj) minitalk_bonus.h
	$(CC) $(CFLAGS) client_bonus.c $(cb_obj) -o $(client_bonus) -fsanitize=address

$(server):$(c_obj) minitalk.h
	$(CC) $(CFLAGS) server.c $(c_obj) -o $(server)
$(client):$(c_obj) minitalk.h
	$(CC) $(CFLAGS) client.c $(c_obj) -o $(client)
%.o:%.c
	$(CC) $(CFLAGS) -c $^ -o $@

clean:
	rm -rf $(c_obj) $(cb_obj)
fclean: clean
	rm -rf $(client) $(server) 
#	$(client_bonus) $(server_bonus)
re: fclean all