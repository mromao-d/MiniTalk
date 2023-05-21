/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk_utils_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mromao-d <mromao-d@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/17 11:58:40 by mromao-d          #+#    #+#             */
/*   Updated: 2023/05/21 14:35:41 by mromao-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk_bonus.h"

int	ft_atoi(const char *str)
{
	int	i;
	int	sign;
	int	result;

	i = 0;
	result = 0;
	sign = 1;
	while (str[i] == ' ' || str[i] == '\t' || str[i] == '\n' || str[i] == '\v'\
		|| str[i] == '\f' || str[i] == '\r')
		i++;
	if (str[i] == '-')
		sign = -1;
	if (str[i] == '+' || str[i] == '-')
		i++;
	while (str[i] != '\0' && (str[i] >= '0' && str[i] <= '9'))
	{
		if (str[i] == ' ')
			i++;
		else
		{
			result = result * 10 + str[i] - 48;
			i++;
		}
	}
	return (result * sign);
}

int	ft_strlen(const char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
		i++;
	return (i);
}

int	ft_putchar(char c)
{
	write(1, &c, 1);
	return (1);
}

int	ft_putstr(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		ft_putchar(str[i]);
		i++;
	}
	return (i);
}

int	ft_putnmbr(int i)
{
	int		j;
	int		copy;
	char	*nmbr;

	j = 0;
	copy = i;
	while (copy / 10 > 0)
	{
		copy = copy / 10;
		j++;
	}
	nmbr = (char *) malloc(sizeof(char) * j);
	while (j >= 0)
	{
		nmbr[j] = i % 10 + 48;
		i = i / 10;
		j--;
	}
	ft_putstr(nmbr);
	free (nmbr);
	return (ft_putstr(nmbr));
}
