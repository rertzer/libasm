/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_file_tester.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rertzer <rertzer@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/03 12:17:30 by rertzer           #+#    #+#             */
/*   Updated: 2024/02/04 10:04:08 by rertzer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libasm_tester.h"

int	read_file_tester(char *s1, const size_t len)
{
	printf("\033[0;35m       ---------------------------------------------\033[0m\n");
	printf("Testing read on random.txt, buffer size: %ld\n", len);

	int fd = open("random.txt", O_RDONLY);
	if (fd == -1)
	{
		printf("open random.txt failed. Quitting...\n");
		return 1;
	}

	bzero((void*)s1, len);
	errno = 0;
	long int ret = read(fd, s1, len);
	printf("\nstd return value: %ld\nstd errno: %d\n", ret, errno);
	printf("buffer contain: %s\n", s1);
	close (fd);
	fd = open("random.txt", O_RDONLY);
	if (fd == -1)
	{
		printf("open random.txt failed. Quitting...\n");
		return 1;
	}

	bzero((void*)s1, len);
	errno = 0;
	ret = ft_read(fd, s1, len);
	printf("\nft return value: %ld\nft errno: %d\n\n", ret, errno);
	printf("buffer contain: %s\n\n", s1);
	bzero((void*)s1, len);
	close(fd);
	return 0;
}

