/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtins.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hwichoi <hwichoi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/14 18:15:39 by hwichoi           #+#    #+#             */
/*   Updated: 2023/01/14 18:26:29 by hwichoi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

int	is_builtin(t_lst_cmd *lst_cmd)
{
	if (lst_cmd->args[0] == NULL)
	{
		return (0);
	}
	if ((ft_strncmp(lst_cmd->args[0], "env",
				ft_strlen(lst_cmd->args[0]) + 1) == 0)
		|| (ft_strncmp(lst_cmd->args[0], "pwd",
				ft_strlen(lst_cmd->args[0]) + 1) == 0)
		|| (ft_strncmp(lst_cmd->args[0], "echo",
				ft_strlen(lst_cmd->args[0]) + 1) == 0))
	{
		return (1);
	}
	else if (ft_strncmp(lst_cmd->args[0], "cd",
			ft_strlen(lst_cmd->args[0]) + 1) == 0
		|| (ft_strncmp(lst_cmd->args[0], "exit",
				ft_strlen(lst_cmd->args[0]) + 1) == 0)
		|| (ft_strncmp(lst_cmd->args[0], "export",
				ft_strlen(lst_cmd->args[0]) + 1) == 0)
		|| (ft_strncmp(lst_cmd->args[0], "unset",
				ft_strlen(lst_cmd->args[0]) + 1) == 0))
		return (2);
	else
		return (0);
}

void	do_builtin(t_minishell *data, t_lst_cmd *lst_cmd)
{
	if (ft_strncmp(lst_cmd->args[0], "cd", ft_strlen("cd")) == 0)
		ft_cd(data, lst_cmd->args, lst_cmd);
	if (ft_strncmp(lst_cmd->args[0], "env", ft_strlen("env")) == 0)
		env(data);
	if (ft_strncmp(lst_cmd->args[0], "unset", ft_strlen("unset")) == 0)
		ft_unset(data, lst_cmd->args);
	if (ft_strncmp(lst_cmd->args[0], "pwd", ft_strlen("pwd")) == 0)
		ft_pwd(data);
	if (ft_strncmp(lst_cmd->args[0], "export", ft_strlen("export")) == 0)
		ft_export(data, lst_cmd);
	if (ft_strncmp(lst_cmd->args[0], "exit", ft_strlen("exit")) == 0)
		ft_exit(lst_cmd);
	if (ft_strncmp(lst_cmd->args[0], "echo", ft_strlen("echo")) == 0)
		ft_echo(lst_cmd->args);
}
