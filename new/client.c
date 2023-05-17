/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mromao-d <mromao-d@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/14 18:08:46 by mromao-d          #+#    #+#             */
/*   Updated: 2023/05/17 13:43:23 by mromao-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	ft_send_bin(int pid, char *argv, size_t len)
{
	size_t	i;
	int		shift;

	i = 0;
	while (argv && argv[i] && i <= len)
	{
		shift = 7;
		while (shift >= 0)
		{
			if ((argv[i] >> shift) & 1)
				kill(pid, SIGUSR2);
			else
				kill(pid, SIGUSR1);
			usleep(300);
			shift--;
		}
		i++;
	}
	return ;
}

int	main(int argc, char *argv[])
{
	int	pid;

	if (argc != 3)
	{
		ft_putstr("Format is: ./client <server-pid> <message>\n");
		return (1);
	}
	pid = ft_atoi(argv[1]);
	ft_send_bin(pid, argv[2], ft_strlen(argv[2]));
	return (0);
}
