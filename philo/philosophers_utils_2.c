/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers_utils_2.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hasabir <hasabir@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/13 18:57:44 by hasabir           #+#    #+#             */
/*   Updated: 2022/09/26 13:37:34 by hasabir          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

int	ft_error(void)
{
	printf("Number of arguments is not correct\n");
	return (1);
}

void	ft_bzero(void	*s, size_t n)
{
	size_t	i;

	i = 0;
	while (i < n)
	{
		((unsigned char *)s)[i] = 0;
		i++;
	}
	return ;
}

int	ft_conv_nbr(const char *str, int n)
{
	unsigned long int	i;
	unsigned long int	nb;

	i = 0;
	nb = 0;
	while (str[i] && str[i] >= '0' && str[i] <= '9')
	{
		nb = nb * 10 + str[i] - '0';
		if (n == 1 && nb >= L_MAX)
			return (-1);
		else if (n == -1 && nb >= (unsigned long )L_MAX + 1)
			return (0);
		i++;
	}
	return ((int)nb * n);
}

int	ft_atoi(const char *str)
{
	unsigned long int	i;
	int					n;

	i = 0;
	n = 1;
	while (str[i] == 32 || (str[i] >= 9 && str[i] <= 13))
		i++;
	if (str[i] == '-')
	{
		n = -n;
		i++;
	}
	else if (str[i] == '+' )
		i++;
	return (ft_conv_nbr(str + i, n));
}
