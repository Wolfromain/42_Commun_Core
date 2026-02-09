/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmin.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbouquet <rbouquet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/02 15:45:36 by rbouquet          #+#    #+#             */
/*   Updated: 2024/07/02 15:45:45 by rbouquet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_lstmin(t_stack_node *lst)
{
	int	min;

	min = INT_MAX;
	if (lst == NULL)
		return (NULL);
	while (lst)
	{
		if (lst -> next < min)
			min = lst -> next;
		lst = lst -> next;
	}
	return (min);
}