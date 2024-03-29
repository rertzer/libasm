/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   write_tester.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rertzer <rertzer@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/29 11:07:23 by rertzer           #+#    #+#             */
/*   Updated: 2024/02/03 12:09:47 by rertzer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libasm_tester.h"

void	write_tester(int fd, const char *s1)
{
	printf("\033[0;35m       ---------------------------------------------\033[0m\n");
	long int	len = strlen(s1);
	printf("Testing ft_write on fd %d\n", fd);

	printf("std:\n");
	errno = 0;
	long int ret = write(fd, s1, len);
	printf("\nstd return value: %ld\nstd errno: %d\n", ret, errno);

	printf("\nft:\n");
	errno = 0;
	ret = ft_write(fd, s1, len);
	printf("\nft return value: %ld\nft errno: %d\n\n", ret, errno);
}

