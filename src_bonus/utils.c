/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cspreafi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/06 11:00:20 by cspreafi          #+#    #+#             */
/*   Updated: 2024/05/06 11:00:26 by cspreafi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"


int	ft_check(char **argv)
{
	int	i;

	i = 0;
	if(argv[2][i] == '-' || argv[2][i] == '+')
		i++;
	while (argv[2][i])
	{
		if (ft_isdigit(argv[2][i]) == 0 && argv[2][i] != '.')
			return (0);
		i++;
	}
	i = 0;
	if(argv[3][i] == '-' || argv[3][i] == '+')
		i++;
	while (argv[3][i])
	{
		if (ft_isdigit(argv[3][i]) == 0 && argv[3][i] != '.')
			return (0);
		i++;
	}
	return (1);
}

double	ft_atod(char *s)
{
	double	nb;
	double	power;
	int		sign;
	int		i;

	sign = 1;
	nb = 0.0;
	power = 1.0;
	i = 0;
	if (s[i++] == '-')
		sign = -1;
	while (ft_isdigit(s[i]))
	{
		nb = 10.0 * nb + (s[i] - '0');
		i++;
	}
	if (s[i] == '.')
		i++;
	while (ft_isdigit(s[i]))
	{
		nb = 10.0 * nb + (s[i] - '0');
		power *= 10.0;
		i++;
	}
	return (sign * nb / power);
}

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t	c;

	c = 0;
	if (n == 0)
		return (0);
	if (n != 0)
	{
		while (s1[c] == s2[c] && s1 && c < n - 1)
			c++;
	}
	else
		return (0);
	return (((unsigned char)(s1[c]) - (unsigned char)(s2[c])));
}

int	ft_isdigit(int c)
{
	if (c >= '0' && c <= '9')
		return (1);
	return (0);
}
