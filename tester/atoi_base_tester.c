/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   atoi_base_tester.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rertzer <rertzer@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/29 11:00:14 by rertzer           #+#    #+#             */
/*   Updated: 2024/01/29 11:01:23 by rertzer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libasm_tester.h"

void	atoi_base_tester(char *string, char *base)
{
	int i = piscine_atoi_base(string, base);
	int j = ft_atoi_base(string, base);
	printf("%s in %s gives\n", string, base);
	li_compare(i, j);
}
