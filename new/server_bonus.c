/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mromao-d <mromao-d@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/14 18:08:51 by mromao-d          #+#    #+#             */
/*   Updated: 2023/05/21 14:49:36 by mromao-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk_bonus.h"

t_data		g_word;

void	ft_reset_shit(void)
{
	g_word.bit_index = 0;
	g_word.c = 0;
	g_word.client_pid = 0;
}

void	get_pid(int sig, siginfo_t *siginfo, void *context)
{
	(void)context;
	if (g_word.client_pid != siginfo->si_pid)
		ft_reset_shit();
	if (sig == SIGUSR2)
		g_word.c = g_word.c << 1 | 1;
	else
		g_word.c = g_word.c << 1;
	g_word.bit_index++;
	if (g_word.bit_index == 8)
	{	
		write(1, &g_word.c, 1);
		ft_reset_shit();
	}
	g_word.client_pid = siginfo->si_pid;
	kill(siginfo->si_pid, SIGUSR1);
}

int	main(int argc, char **argv)
{
	struct sigaction	sa;

	(void)argc;
	(void)argv;
	ft_reset_shit();
	ft_putstr("PID:	");
	ft_putnmbr(getpid());
	sa.sa_sigaction = &get_pid;
	sa.sa_flags = SA_SIGINFO;
	sigemptyset(&sa.sa_mask);
	sigaddset(&sa.sa_mask, SIGUSR1);
	sigaddset(&sa.sa_mask, SIGUSR2);
	sigaction(SIGUSR1, &sa, NULL);
	sigaction(SIGUSR2, &sa, NULL);
	ft_putchar('\n');
	while (1)
		sleep(1);
	return (0);
}
