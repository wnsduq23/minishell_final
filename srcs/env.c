/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hwichoi <hwichoi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/14 18:19:05 by hwichoi           #+#    #+#             */
/*   Updated: 2023/01/14 18:26:32 by hwichoi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

void	env(t_minishell *data)
{
	int		i;
	char	**dest;

	dest = data->new_env;
	i = 0;
	while (dest[i])
	{
		if (ft_strchr(dest[i], '='))
			ft_putendl_fd(dest[i], 1);
		i++;
	}
	exit(0);
}
