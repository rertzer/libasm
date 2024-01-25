/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libasm_tester.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rertzer <rertzer@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/23 14:59:17 by rertzer           #+#    #+#             */
/*   Updated: 2024/01/25 11:29:56 by rertzer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <stdio.h>
#include <errno.h>


#define	BIG_SIZE 42 * 4096 - 7

extern size_t	ft_strlen(const char *s);
extern char		*ft_strcpy(char *dest, const char *src);
extern int		ft_strcmp(const char *s1, const char * s2);
extern ssize_t	ft_write(int fd, const char *buf, size_t count);


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
	long int	len = strlen(std);
	if (len < 1024)
	{
		printf("stdlib: %s\n", std);
		printf("libasm: %s\n", ft);
	}
	else
		printf("(string len: %ld)\n", len);

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

int	main()
{
	char	test_string_1[] = "coucou";
	char	test_string_2[] = "";
	char	test_string_3[] = "Loin des oiseaux, des troupeaux, des villageoises,\nJe buvais a genoux dans quelque bruyere\nEntouree de tendres bois de noisetiers,\nPar un brouillard d'apres-midi tiede et vert.\n";
	char	test_string_4[] = "coukou";
	char	*test_string_bigA = malloc(BIG_SIZE + 1);
	if (test_string_bigA == NULL)
	{
		printf("\033[0;31mSorry, malloc failure\033[0m\n");
		return (1);
	}

	for (int i = 0; i < BIG_SIZE; i++)
		test_string_bigA[i] = 'A';
	test_string_bigA[BIG_SIZE] = '\0';

	printf("\033[0;33m       ==================== STRLEN =====================\033[0m\n");
	strlen_tester(test_string_1);
	strlen_tester(test_string_2);
	strlen_tester(test_string_3);
	strlen_tester(test_string_bigA);

	printf("\033[0;33m       ==================== STRCPY =====================\033[0m\n");
	if (strcpy_tester(test_string_1))
		return 1;;
	if (strcpy_tester(test_string_2))
		return 1;
	if (strcpy_tester(test_string_3))
		return 1;
	if (strcpy_tester(test_string_bigA))
		return 1;
	
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

	free(test_string_bigA);
	return 0;
}
