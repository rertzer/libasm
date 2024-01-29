/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   strdup_tester.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rertzer <rertzer@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/29 11:08:28 by rertzer           #+#    #+#             */
/*   Updated: 2024/01/29 11:08:47 by rertzer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libasm_tester.h"

int	strdup_tester(const char *s)
{
	printf("Testing ft_strdup\n");

	errno = 0;
	char *dest_std = strdup(s);
	printf("length: %lu\n", strlen(dest_std));
	printf("errno after std strdup: %d\n\n", errno);
	
	errno = 0;
	char *dest_ft = ft_strdup(s);
	printf("errno after ft strdup: %d\n\n", errno);
	str_compare(dest_std, dest_ft);
	free(dest_std);
	free(dest_ft);
	return (0);
}
