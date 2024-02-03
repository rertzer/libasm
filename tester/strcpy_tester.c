/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   strcpy_tester.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rertzer <rertzer@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/29 11:05:41 by rertzer           #+#    #+#             */
/*   Updated: 2024/02/03 11:28:46 by rertzer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libasm_tester.h"

int	strcpy_tester(const char *s)
{
	printf("\033[0;35m       ---------------------------------------------\033[0m\n");
	printf("Testing ft_strcpy\n");
	int	len = strlen(s);

	char *dest_std = malloc(len + 1);
	if (dest_std == NULL)
	{
		printf("\033[0;31mSorry, malloc failure\033[0m\n");
		return (1);
	}
	char *dest_ft = malloc(len + 1);

	if (dest_ft == NULL)
	{
		printf("\033[0;31mSorry, malloc failure\033[0m\n");
		return (1);
	}
	dest_std = strcpy(dest_std, s);
	dest_ft = ft_strcpy(dest_ft, s);
	str_compare(dest_std, dest_ft);
	free(dest_std);
	free(dest_ft);
	return (0);
}


