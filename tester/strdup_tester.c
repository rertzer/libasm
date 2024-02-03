/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   strdup_tester.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rertzer <rertzer@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/29 11:08:28 by rertzer           #+#    #+#             */
/*   Updated: 2024/02/03 11:28:12 by rertzer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libasm_tester.h"

int	strdup_tester(const char *s)
{
	printf("\033[0;35m       ---------------------------------------------\033[0m\n");
	printf("Testing ft_strdup\n");

	errno = 0;
	char *dest_std = strdup(s);
	printf("length: %lu\n", strlen(dest_std));
	printf("errno after std strdup: %d\n\n", errno);
	
	errno = 0;
	char *dest_ft = ft_strdup(s);
	printf("length: %lu\n", strlen(dest_ft));
	printf("errno after ft strdup: %d\n\n", errno);
	str_compare(dest_std, dest_ft);
	free(dest_std);
	free(dest_ft);
	return (0);
}
