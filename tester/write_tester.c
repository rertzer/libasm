/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   write_tester.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rertzer <rertzer@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/29 11:07:23 by rertzer           #+#    #+#             */
/*   Updated: 2024/01/29 11:07:49 by rertzer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libasm_tester.h"

void	write_tester(int fd, const char *s1)
{
	long int	len = strlen(s1);
	printf("Testing ft_write\n");

	printf("std:\n");
	errno = 0;
	long int ret = write(fd, s1, len);
	printf("\nstd return value: %ld\nstd errno: %d\n", ret, errno);

	printf("\nft:\n");
	errno = 0;
	ret = ft_write(fd, s1, len);
	printf("\nft return value: %ld\nft errno: %d\n\n", ret, errno);
}

