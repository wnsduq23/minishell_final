/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hwichoi <hwichoi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/14 18:25:00 by hwichoi           #+#    #+#             */
/*   Updated: 2023/01/14 18:26:04 by hwichoi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(char *src)
{
	int		i;
	char	*copy;
	int		len;

	i = 0;
	len = ft_strlen(src);
	copy = ft_calloc((len + 1), sizeof(char));
	if (copy == NULL)
		return (NULL);
	while (src[i])
	{
		copy[i] = src[i];
		i++;
	}
	copy[i] = '\0';
	return (copy);
}

char	*ft_gc_strdup(char *src)
{
	int		i;
	char	*copy;
	int		len;

	i = 0;
	len = ft_strlen(src);
	copy = ft_gc_calloc((len + 1), sizeof(char));
	if (copy == NULL)
		return (NULL);
	while (src[i])
	{
		copy[i] = src[i];
		i++;
	}
	copy[i] = '\0';
	return (copy);
}
