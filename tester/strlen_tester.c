/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   strlen_tester.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rertzer <rertzer@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/29 11:04:31 by rertzer           #+#    #+#             */
/*   Updated: 2024/02/03 11:27:49 by rertzer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libasm_tester.h"

void	strlen_tester(const char *s)
{
	printf("\033[0;35m       ---------------------------------------------\033[0m\n");
	printf("Testing ft_strlen\n");

	long int	len_std = strlen(s);
	long int	len_asm = ft_strlen(s);

	if (len_std < 1024)
		printf("%s\n", s);

	li_compare(len_std, len_asm);
}
