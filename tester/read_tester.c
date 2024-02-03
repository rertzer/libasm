/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_tester.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rertzer <rertzer@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/29 11:07:57 by rertzer           #+#    #+#             */
/*   Updated: 2024/02/03 12:10:48 by rertzer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libasm_tester.h"

void	read_tester(int fd, char *s1, const size_t len)
{
	printf("\033[0;35m       ---------------------------------------------\033[0m\n");
	printf("Testing read on fd %d, bffer size: %ld\n", fd, len);
	
	printf("\nstd, your entry:\n");
	bzero((void*)s1, len);
	errno = 0;
	long int ret = read(fd, s1, len);
	printf("\nstd return value: %ld\nstd errno: %d\n", ret, errno);
	printf("buffer contain: %s\n", s1);

	printf("\nft, your entry:\n");
	bzero((void*)s1, len);
	errno = 0;
	ret = ft_read(fd, s1, len);
	printf("\nft return value: %ld\nft errno: %d\n\n", ret, errno);
	printf("buffer contain: %s\n\n", s1);
	bzero((void*)s1, len);
}

