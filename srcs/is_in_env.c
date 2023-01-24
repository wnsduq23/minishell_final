/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_in_env.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hwichoi <hwichoi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/14 18:20:31 by hwichoi           #+#    #+#             */
/*   Updated: 2023/01/14 18:26:39 by hwichoi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

int	is_in_env(t_minishell *data, char *arg)
{
	int		i;
	char	**split;

	split = ft_split(arg, '=');
	i = 0;
	while (data->new_env[i])
	{
		if ((!ft_strncmp(data->new_env[i], split[0], ft_strlen(split[0])) \
		&& data->new_env[i][ft_strlen(split[0])] == '=')
		|| (!ft_strncmp(data->new_env[i], split[0], ft_strlen(split[0])) \
		&& data->new_env[i][ft_strlen(split[0])] == '\0'))
		{
			ft_free_split(split);
			return (1);
		}
		i++;
	}
	ft_free_split(split);
	return (0);
}
