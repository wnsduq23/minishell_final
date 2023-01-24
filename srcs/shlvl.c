/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shlvl.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hwichoi <hwichoi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/14 18:21:30 by hwichoi           #+#    #+#             */
/*   Updated: 2023/01/14 18:26:48 by hwichoi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

char	**replace_exist_line_2(t_minishell *data, char *args, char **dest)
{
	char	**split;
	char	*temp;
	int		shlvl;

	if (args)
	{
		temp = ft_gc_strdup(args);
		split = ft_split(temp, '=');
		shlvl = ft_atoi(split[1]) + 1;
		temp = ft_strjoin("SHLVL=", ft_itoa(shlvl));
		ft_free_split(split);
	}
	else
		temp = ft_gc_strdup("SHLVL=1");
	if (is_in_env(data, "SHLVL"))
		dest[find_in_env(data, "SHLVL")] = ft_gc_strdup(temp);
	else
	{
		data->pwd = getcwd(NULL, 0);
		dest = ft_addline(dest, ft_strjoin("PWD=", data->pwd));
		free(data->cd_pwd);
		dest = ft_addline(dest, temp);
	}
	return (dest);
}

void	oldpwd(t_minishell *data)
{
	if (is_in_env(data, "OLDPWD"))
	{
		data->new_env[find_in_env(data, "OLDPWD")]
			= ft_strjoin("OLDPWD=",
				data->cd_pwd);
		free(data->cd_pwd);
	}
	else
	{
		data->pwd = getcwd(NULL, 0);
		data->new_env = ft_addline(data->new_env,
				ft_strjoin("OLDPWD=", data->cd_pwd));
		free(data->cd_pwd);
	}
}
