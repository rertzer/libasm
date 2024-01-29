/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libasm_tester.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rertzer <rertzer@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/23 14:59:17 by rertzer           #+#    #+#             */
/*   Updated: 2024/01/29 11:07:04 by rertzer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libasm_tester.h"

void	li_compare(long int std, long int ft)
{
	printf("ref:    %ld\n", std);
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

int	main()
{
	//char	test_string_1[] = "coucou";
	//char	test_string_2[] = "";
	char	atoi_string_1[] = "1234";
	char	atoi_string_2[] = "9876543210";
	char	atoi_string_3[] = "lapinnappllinap";
	char	atoi_string_4[] = "1333666999";
	char	atoi_string_5[] = "            555666777";
	char	atoi_string_6[] = "-33";
	char	atoi_string_7[] = "+abc";
	char	atoi_string_8[] = " -++---42";
	char	atoi_string_9[] = "10100001110101011110110010";
	char	atoi_string_10[] = "007";
	char	atoi_string_11[] = "0";
	char	atoi_base_ten[] = "0123456789";
	char	atoi_base_two[] = "01";
	char	atoi_base_hex[] = "0123456789abcdef";
	char	atoi_base_lapin[] = "lapin";
	//char	test_string_3[] = "Loin des oiseaux, des troupeaux, des villageoises,\nJe buvais a genoux dans quelque bruyere\nEntouree de tendres bois de noisetiers,\nPar un brouillard d'apres-midi tiede et vert.\n";
	/*char	test_string_4[] = "coukou";
	char	*test_string_bigA = malloc(BIG_SIZE + 1);
	if (test_string_bigA == NULL)
	{
		printf("\033[0;31mSorry, malloc failure\033[0m\n");
		return (1);
	}

	for (int i = 0; i < BIG_SIZE; i++)
		test_string_bigA[i] = 'A';
	test_string_bigA[BIG_SIZE] = '\0';*/
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

	printf("\033[0;33m       ==================== STRDUP ===================\033[0m\n");
	strdup_tester(test_string_1);
	strdup_tester(test_string_2);
	strdup_tester(test_string_3);
	strdup_tester(test_string_bigA);
*/

	printf("\033[0;33m       ====================== BONUS =================\033[0m\n");
	printf("\033[0;33m       ==================== ATOI BASE ===============\033[0m\n");
	atoi_base_tester(atoi_string_1, atoi_base_ten);
	printf("buffer overflow:\n");
	atoi_base_tester(atoi_string_2, atoi_base_ten);
	atoi_base_tester(atoi_string_4, atoi_base_ten);
	atoi_base_tester(atoi_string_3, atoi_base_lapin);
	atoi_base_tester(atoi_string_1, atoi_base_lapin);
	atoi_base_tester(atoi_base_lapin, atoi_base_lapin);
	atoi_base_tester(atoi_string_5, atoi_base_ten);
	atoi_base_tester(atoi_string_6, atoi_base_ten);
	atoi_base_tester(atoi_string_7, atoi_base_ten);
	atoi_base_tester(atoi_string_8, atoi_base_ten);
	atoi_base_tester(atoi_string_7, atoi_base_hex);
	atoi_base_tester(atoi_string_9, atoi_base_two);
	atoi_base_tester(atoi_string_10, atoi_base_ten);
	atoi_base_tester(atoi_string_11, atoi_base_ten);
//	free(test_string_bigA);
//	free(buffer);
	return 0;
}
