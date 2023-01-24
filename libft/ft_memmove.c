/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hwichoi <hwichoi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/14 18:24:17 by hwichoi           #+#    #+#             */
/*   Updated: 2023/01/14 18:24:17 by hwichoi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t size)
{
	size_t	i;
	char	*d;
	char	*s;

	i = 0;
	d = (char *)dst;
	s = (char *)src;
	if (!(dst || src) || size == 0)
		return (dst);
	if (s < d)
	{
		while (size-- > 0)
		{
			d[size] = s[size];
		}
	}
	else
	{
		while (i < size)
		{
			d[i] = s[i];
			i++;
		}
	}
	return (dst);
}
