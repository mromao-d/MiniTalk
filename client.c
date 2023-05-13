#include <signal.h>
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <string.h>

/* static int rec; */

void ft_send_bin(int	pid, char *argv, size_t len)
{
	size_t	i;
	int	shift;

	i = 0;
	while (argv && argv[i] && i < len)
	{
		shift = 8;
		while (shift > 0)
		{
			if ((argv[i] >> shift) & 1)
				kill(pid, SIGUSR2);
			else 
				kill(pid, SIGUSR1);
			usleep(500);
			shift--;
		}
		i++;
	}
	return ;
}

/* void sig_handler(int signum, siginfo_t *info, void *context)
{
	(void) signum;
	(void) info;
	(void) context;
	printf("receceived siganl\n");
} */

int main(int argc, char *argv[])
{
	/* struct sigaction	sa; */
	int	pid;

	if (argc != 3)
	{	
		printf("\x1b[33mU entered \x1b[31m%d\x1b[33m arguments (U must enter \x1b[32mEGG\x1b[33mxactly 2)", argc - 1);
		return(1);
	}
	/* sigemptyset(&sa.sa_mask); */
	/* sa.sa_flags = SA_RESTART | SA_SIGINFO;
	sa.sa_sigaction = sig_handler; */
	/* sigaction(SIGUSR2, &sa, NULL);
	sigaction(SIGUSR1, &sa, NULL); */
	pid = atoi(argv[1]);
	ft_send_bin(pid, argv[2], strlen(argv[2]) + 1);
	return (0);
}
