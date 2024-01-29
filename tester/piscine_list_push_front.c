/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   piscine_list_push_front.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rertzer <rertzer@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/29 11:46:28 by rertzer           #+#    #+#             */
/*   Updated: 2024/01/29 12:01:55 by rertzer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libasm_tester.h"

void	piscine_list_push_front(t_list **begin_list, void *data)
{
	t_list	*elem;

	if ((elem = piscine_create_elem(data)) == NULL)
		return;
	if (*begin_list)
		elem->next = *begin_list;
	*begin_list = elem;
}
