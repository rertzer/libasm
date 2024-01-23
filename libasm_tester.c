/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libasm_tester.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rertzer <rertzer@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/23 14:59:17 by rertzer           #+#    #+#             */
/*   Updated: 2024/01/23 16:08:20 by rertzer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <string.h>
#include <stdio.h>

extern size_t	ft_strlen(const char *s);
extern char		*ft_strcpy(char *dest, const char *src);

void	strlen_tester(const char *s)
{
	printf("Testing ft_strlen\n");
	printf("%s\n", s);
	printf("stdlib: %ld\n", strlen(s));
	printf("libasm: %ld\n\n", strlen(s));
}

void	strcpy_tester(const char *s)
{
	if (strlen(s) > 1023)
	{
		printf("string to long\n");
		return;
	}

	char *destA = malloc(1024);
	char *destB = malloc(1024);
	printf("Testing ft_strcpy\n");
	printf("%s\n", s);
	destA = strcpy(destA, s);
	printf("stdlib: %s\n", destA);
	destB = ft_strcpy(destB, s);
	printf("libasm: %s\n\n", destB);
}

int	main()
{
	char	test_string_1[] = "coucou";
	char	test_string_2[] = "";
	char	test_string_3[] = "Loin des oiseaux, des troupeaux, des villageoises,\nJe buvais a genoux dans quelque bruyere\nEntouree de tendres bois de noisetiers,\nPar un brouillard d'apres-midi tiede et vert.\n";

	strlen_tester(test_string_1);
	strlen_tester(test_string_2);
	strlen_tester(test_string_3);

	strcpy_tester(test_string_1);
	strcpy_tester(test_string_2);
	strcpy_tester(test_string_3);
	
	return 0;
}
