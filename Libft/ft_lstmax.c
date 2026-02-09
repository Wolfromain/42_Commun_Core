/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmax.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbouquet <rbouquet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/02 15:43:50 by rbouquet          #+#    #+#             */
/*   Updated: 2024/11/16 10:13:30 by rbouquet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_lstmax(t_stack_node *lst)

{
	int max;

	max = INT_MIN;
	if (lst == NULL)
		return (NULL);
	while (lst)
	{
		if (lst->next > max)
			max = lst->next;
		lst = lst->next;
	}
	return (max);
}
