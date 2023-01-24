/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hwichoi <hwichoi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/14 18:22:46 by hwichoi           #+#    #+#             */
/*   Updated: 2023/01/14 18:26:22 by hwichoi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t elementCount, size_t elementSize)
{
	void	*ptr;

	ptr = malloc(elementCount * elementSize);
	if (ptr == NULL)
	{
		ft_gc_destroy();
		exit(1);
	}
	ft_bzero(ptr, elementCount * elementSize);
	return (ptr);
}
