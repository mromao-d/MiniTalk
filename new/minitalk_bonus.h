/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk_bonus.h                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mromao-d <mromao-d@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/17 11:56:28 by mromao-d          #+#    #+#             */
/*   Updated: 2023/05/21 14:31:18 by mromao-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINITALK_BONUS_H
# define MINITALK_BONUS_H

# include <signal.h>
# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# define ANSI_COLOR_RED "\x1b[31m"
# define ANSI_COLOR_GREEN "\x1b[32m"
# define ANSI_COLOR_YELLOW "\x1b[33m"
# define ANSI_COLOR_BLUE "\x1b[34m"
# define ANSI_COLOR_MAGENTA "\x1b[35m"
# define ANSI_COLOR_CYAN "\x1b[36m"
# define ANSI_COLOR_RESET "\x1b[0m"

typedef struct s_data
{
	int		bit_index;
	char	c;
	int		client_pid;
}			t_data;

int	ft_atoi(const char *str);
int	ft_strlen(const char *str);
int	ft_putchar(char c);
int	ft_putstr(char *str);
int	ft_putnmbr(int i);

#endif