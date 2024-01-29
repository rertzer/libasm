/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   piscine_create_element.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rertzer <rertzer@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/29 11:47:23 by rertzer           #+#    #+#             */
/*   Updated: 2024/01/29 11:47:30 by rertzer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libasm_tester.h"

t_list	*piscine_create_elem(void *data)
{
	t_list	*mylist;

	mylist = malloc(sizeof(t_list));
	if (! mylist)
		return (NULL);
	mylist->data = data;
	mylist->next = NULL;
	return (mylist);
}
