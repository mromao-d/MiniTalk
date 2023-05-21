/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mromao-d <mromao-d@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/14 18:08:46 by mromao-d          #+#    #+#             */
/*   Updated: 2023/05/21 14:43:19 by mromao-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk_bonus.h"

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
			usleep(5000);
			shift--;
		}
		i++;
	}
	return ;
}

void	sig_handler(void)
{
	printf("Recevied signal from server!\n");
}

int	main(int argc, char *argv[])
{
	struct sigaction	sa;
	int					pid;

	if (argc != 3)
	{
		ft_putstr("Format is: ./client <server-pid> <message>\n");
		return (1);
	}
	sigemptyset(&sa.sa_mask);
	sa.sa_flags = SA_SIGINFO;
	sa.sa_sigaction = (void *)sig_handler;
	sigaction(SIGUSR2, &sa, NULL);
	sigaction(SIGUSR1, &sa, NULL);
	pid = ft_atoi(argv[1]);
	ft_send_bin(pid, argv[2], ft_strlen(argv[2]));
	return (0);
}
