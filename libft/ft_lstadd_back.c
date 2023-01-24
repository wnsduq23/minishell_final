/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hwichoi <hwichoi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/14 18:23:24 by hwichoi           #+#    #+#             */
/*   Updated: 2023/01/14 18:26:16 by hwichoi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_back(t_list **alst, t_list *new)
{
	t_list	*start;

	if (*alst == NULL)
	{
		(*alst) = new;
		return ;
	}
	start = *alst;
	*alst = ft_lstlast(*alst);
	(*alst)->next = new;
	*alst = start;
}
