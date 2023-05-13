#define ANSI_COLOR_RED     "\x1b[31m"
#define ANSI_COLOR_GREEN   "\x1b[32m"
#define ANSI_COLOR_YELLOW  "\x1b[33m"
#define ANSI_COLOR_BLUE    "\x1b[34m"
#define ANSI_COLOR_MAGENTA "\x1b[35m"
#define ANSI_COLOR_CYAN    "\x1b[36m"
#define ANSI_COLOR_RESET   "\x1b[0m"

#include <signal.h>
#include <stdio.h>
#include <unistd.h>

typedef struct Data
{
	int		bit_index;
	char	c;
	int		client_pid;
} data_t;

data_t	word;

void	ft_reset_shit(void)
{
	word.bit_index = 0;
	word.c = 0;
	word.client_pid = 0;
}

void	get_pid(int sig, siginfo_t *siginfo, void *context)
{
	(void) context;
	sig -= SIGUSR1;
	if (word.client_pid != siginfo->si_pid)
		ft_reset_shit();
	/* while (word.bit_index < 8)
	{ */
	/* if (sig == SIGUSR2) {
		word.c = word.c << 1 | 1; }
	else {
		word.c = (word.c << 1) | 0; } */
	word.c = (word.c << 1 | sig);
	word.bit_index++;
	/* } */
	if (siginfo->si_pid == 0)
        printf("Server didn't get client's PID\n");
	if (word.bit_index == 8) {
		write(1, &word.c, 1);
		ft_reset_shit(); }
	word.client_pid = siginfo->si_pid;
}

int main(int argc, char **argv)
{
	struct sigaction        sa;

	(void) argc;
	(void) argv;
	ft_reset_shit();
	printf("PID: %d\n", getpid());			//display PID for kill()
	printf("\n");
	sa.sa_sigaction = &get_pid;
	sa.sa_flags = SA_SIGINFO;
	sigemptyset(&sa.sa_mask);
	sigaddset(&sa.sa_mask, SIGUSR1);
	sigaddset(&sa.sa_mask, SIGUSR2);
	sigaction(SIGUSR1, &sa, NULL);
	sigaction(SIGUSR2, &sa, NULL);
	printf("\n");
	while (1) {
		sleep(1); }
}