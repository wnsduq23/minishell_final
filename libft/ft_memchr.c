/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hwichoi <hwichoi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/14 18:24:06 by hwichoi           #+#    #+#             */
/*   Updated: 2023/01/14 18:24:06 by hwichoi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *memoryBlock, int searchedChar, size_t size)
{
	char	*str_mb;
	size_t	i;

	str_mb = (char *)memoryBlock;
	i = 0;
	while (i < size)
	{
		if (str_mb[i] == (char)searchedChar)
			return ((void *)&str_mb[i]);
		i++;
	}
	return (NULL);
}
