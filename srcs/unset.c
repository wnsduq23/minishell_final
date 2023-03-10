/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unset.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hwichoi <hwichoi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/14 18:21:42 by hwichoi           #+#    #+#             */
/*   Updated: 2023/01/14 18:26:50 by hwichoi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

int	check_arg_unset(char *args)
{
	int		j;

	j = 0;
	while (args[j])
	{
		if (!ft_isalpha(args[0]) && !(args[0] == '_'))
			return (return_error_export("unset: `", args,
					"': not a valid identifier", 1));
		if (ft_isalnum(args[j]) || args[j] == '_' || ft_isspace(j))
			j++;
		else
			return (return_error_export("unset: `", args,
					"': not a valid identifier", 1));
	}
	return (0);
}

char	**feed_temp(t_minishell *data, char **temp)
{
	int	i;
	int	j;

	j = 0;
	i = 0;
	while (data->new_env[i])
	{
		if (ft_strlen(data->new_env[i]) == 0)
			i++;
		else
		{
			temp[j] = ft_gc_strdup(data->new_env[i]);
			j++;
			i++;
		}
	}
	temp[j] = NULL;
	return (temp);
}

int	ft_unset(t_minishell *data, char **args)
{
	int		i;
	char	**temp;
	int		j;

	i = 0;
	temp = ft_gc_calloc(sizeof(char *), (size_t)ft_destlen(data->new_env));
	while (args[++i])
	{
		if (!check_arg_unset(args[i]))
		{
			j = find_in_env(data, args[i]);
			if (j <= ft_destlen(data->new_env) && j >= 0)
			{
				if (data->new_env[j])
				{
					data->new_env[j] = ft_gc_strdup("");
					data->new_env = feed_temp(data, temp);
				}
			}
			else
				return (-1);
		}
	}
	return (0);
}
