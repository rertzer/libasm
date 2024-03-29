/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   strcmp_tester.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rertzer <rertzer@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/29 11:06:30 by rertzer           #+#    #+#             */
/*   Updated: 2024/02/04 09:54:27 by rertzer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libasm_tester.h"

void	strcmp_tester(const char *s1, const char *s2)
{
	printf("\033[0;35m       ---------------------------------------------\033[0m\n");
	long int	len = strlen(s1);
	printf("Testing ft_strcmp\n");
	if (len < 1024)
		printf("%s\n", s1);
	else
		printf("(s1 len: %ld)\n", len);

	len = strlen(s2);
	if (len < 1024)
		printf("%s\n", s2);
	else
		printf("(s2 len: %ld)\n", len);
	int	std = strcmp(s1, s2);
	int	ft = ft_strcmp(s1, s2);
	sign_compare(std, ft);
}


