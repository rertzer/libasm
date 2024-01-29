/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   piscine_atoi_base.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rertzer <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/18 10:27:21 by rertzer           #+#    #+#             */
/*   Updated: 2024/01/29 09:25:01 by rertzer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
/*
#include <stdio.h>
#include <unistd.h>*/

static int	skip_and_get_sign(char **str)
{
	int	sign;

	sign = 1;
	while ((**str >= 9 && **str <= 12) || **str == 32)
			(*str)++;
	while (**str == '+' || **str == '-')
	{
		if (**str == '-')
			sign *= -1;
		(*str)++;
	}
	return (sign);
}

static int	get_num(char *str, char *base, int len)
{
	int	total;
	int	nval;

	total = 0;
	while (*str)
	{
		nval = 0;
		while (nval < len)
		{
			if (*str == base[nval])
				break ;
			nval++;
		}
		if (nval >= len)
			return (total);
		total = total * len + nval;
		str++;
	}
	return (total);
}

static int	base_check(char *base)
{
	int	len;
	int	j;

	len = 0;
	while (base[len])
	{
		j = 0;
		while (j < len)
		{
			if (base[j] == base[len])
				return (0);
			j++;
		}
		if (base[len] == '+' || base[len] == '-' || base[len] == 32)
			return (0);
		if (base[len] >= 9 && base[len] <= 13)
			return (0);
		len++;
	}
	if (len < 2)
		len = 0;
	return (len);
}

int	piscine_atoi_base(char *str, char *base)
{
	int	total;
	int	sign;
	int	len;

	len = base_check(base);
	if (len)
	{
		total = 0;
		sign = skip_and_get_sign(&str);
		total = get_num(str, base, len);
		return (sign * total);
	}
	else
		return (0);
}
/*
int	main(int argc, char **argv)
{
	int	nb;
	
	if (argc > 2)
	{
		nb = ft_atoi_base(argv[1], argv[2]);
		printf("%d\n", nb);
	}
	else
		puts("Usage : a.out number base");	
}*/
