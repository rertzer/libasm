/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libasm_tester.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rertzer <rertzer@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/23 14:59:17 by rertzer           #+#    #+#             */
/*   Updated: 2024/01/25 17:09:00 by rertzer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <stdio.h>
#include <errno.h>


#define	BIG_SIZE 42000

extern size_t	ft_strlen(const char *s);
extern char		*ft_strcpy(char *dest, const char *src);
extern int		ft_strcmp(const char *s1, const char * s2);
extern ssize_t	ft_write(int fd, const char *buf, size_t count);
extern ssize_t	ft_read(int fd, const void *buf, size_t count);
extern char		*ft_strdup(const char *src);


void	li_compare(long int std, long int ft)
{
	printf("stdlib: %ld\n", std);
	printf("libasm: %ld\n", ft);

	if (std != ft)
		printf("\033[0;31m\tKO\033[0m\n\n");
	else
		printf("\033[0;32m\tOK\033[0m\n\n");
}

void	str_compare(const char *std, const char *ft)
{
	long int	std_len = strlen(std);
	long int	ft_len = strlen(ft);
	if (std_len < 1024)
	{
		printf("stdlib: %s\n", std);
		printf("libasm: %s\n", ft);
	}
	else
	{
		printf("(std string len: %ld)\n", std_len);
		printf("( ft string len: %ld)\n", ft_len);
	}
	if (strcmp(std, ft))
		printf("\033[0;31m\tKO\033[0m\n\n");
	else
		printf("\033[0;32m\tOK\033[0m\n\n");

}

void	strlen_tester(const char *s)
{
	printf("Testing ft_strlen\n");

	long int	len_std = strlen(s);
	long int	len_asm = ft_strlen(s);

	if (len_std < 1024)
		printf("%s\n", s);

	li_compare(len_std, len_asm);
}

int	strcpy_tester(const char *s)
{
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

void	strcmp_tester(const char *s1, const char *s2)
{
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
	li_compare(std, ft);
}

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

void	read_tester(int fd, char *s1, const size_t len)
{
	printf("Testing read\n");
	
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

int	main()
{
	char	test_string_1[] = "coucou";
	char	test_string_2[] = "";
	char	test_string_3[] = "Loin des oiseaux, des troupeaux, des villageoises,\nJe buvais a genoux dans quelque bruyere\nEntouree de tendres bois de noisetiers,\nPar un brouillard d'apres-midi tiede et vert.\n";
	//char	test_string_4[] = "coukou";
	char	*test_string_bigA = malloc(BIG_SIZE + 1);
	if (test_string_bigA == NULL)
	{
		printf("\033[0;31mSorry, malloc failure\033[0m\n");
		return (1);
	}

	for (int i = 0; i < BIG_SIZE; i++)
		test_string_bigA[i] = 'A';
	test_string_bigA[BIG_SIZE] = '\0';
/*
	printf("\033[0;33m       ==================== STRLEN =====================\033[0m\n");
	strlen_tester(test_string_1);
	strlen_tester(test_string_2);
	strlen_tester(test_string_3);
	strlen_tester(test_string_bigA);

	printf("\033[0;33m       ==================== STRCPY =====================\033[0m\n");
	if (strcpy_tester(test_string_1) ||
		strcpy_tester(test_string_2) ||
		strcpy_tester(test_string_3) ||
		strcpy_tester(test_string_bigA))
	{
		free(test_string_bigA);
		return 1;
	}
	
	printf("\033[0;33m       ==================== STRCMP =====================\033[0m\n");
	
	strcmp_tester(test_string_1, test_string_1);
	strcmp_tester(test_string_1, test_string_2);
	strcmp_tester(test_string_3, test_string_1);
	strcmp_tester(test_string_1, test_string_4);
	strcmp_tester(test_string_bigA, test_string_bigA);
	strcmp_tester(test_string_bigA, test_string_1);


	printf("\033[0;33m       ==================== WRITE =====================\033[0m\n");
	write_tester(1, test_string_1);
	write_tester(42, test_string_1);
	write_tester(1, test_string_2);
	write_tester(42, test_string_2);
	write_tester(2, test_string_3);
	write_tester(-3, test_string_3);


	printf("\033[0;33m       ==================== READ =====================\033[0m\n");
	size_t	buffer_len = 1024;
	char	*buffer = malloc(buffer_len);
	if (buffer == NULL)
	{
		printf("\033[0;31mSorry, malloc failure\033[0m\n");
		free(test_string_bigA);
		return (1);
	}
	printf("Reading on stdin, buffer size %ld\n", buffer_len);
	read_tester(0, buffer, buffer_len);
	printf("Reading on non existing fd\n");
	read_tester(42, buffer, buffer_len);
	printf("Reading on size 4 buffer\n");
	read_tester(0, buffer, 4);
	printf("another read to flush\n");
	read_tester(0, buffer, buffer_len);
	printf("read on size 0 buffer\n");
	read_tester(0, buffer, 0);
*/
//	printf("\033[0;33m       ==================== STRDUP ===================\033[0m\n");
	strdup_tester(test_string_1);
	strdup_tester(test_string_2);
	strdup_tester(test_string_3);
	strdup_tester(test_string_bigA);


	free(test_string_bigA);
//	free(buffer);
	return 0;
}
