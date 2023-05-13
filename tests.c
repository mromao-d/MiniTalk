#include <signal.h>
#include <stdio.h>
#include <unistd.h>

int ft_bin_2_int(int *ptr)
{
	static char  c;
	/* int    byte_idx; */
	int    bit_idx;
	int    val;

	bit_idx = 0;
	printf("Value per 8 bit -> ");
	while (bit_idx < 8)
	{
		val = ptr[bit_idx];
		if (val == 1)
			c = (c << 1) | 1;
		else if (val == 0)
			c <<= 1;
		bit_idx++;
	}
	printf("%d : ", c);
	return (c);
}

void    get_pid(char c)
{
	(void) context;
	/* if (word.client_pid != siginfo->si_pid)
		ft_reset_shit(); */
	/* word.client_pid = siginfo->si_pid; */
	while (word.bit_index < 8)
	{
		if (sig == SIGUSR2) {
			word.c = (word.c << 1) | 1; }
		else {
			word.c = (word.c << 1) | 0; }
		word.bit_index++;
	}
	if (siginfo->si_pid == 0)
        printf("Server didn't get client's PID\n");
	if (word.bit_index == 8) {
		write(1, &word.c, 1);
		ft_reset_shit(); }
}

int main(void)
{
    int word[8];
 /*    static char    c; */

    word[0] = 0;
    word[1] = 1;
    word[2] = 0;
    word[3] = 0;
    word[4] = 1;
    word[5] = 0;
    word[6] = 0;
    word[7] = 0;
    printf("\n%c", ft_bin_2_int(word));
    /* c = (char) 01000010;
    printf("\n%c", c); */
    return (0);
}