/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   echo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hwichoi <hwichoi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/14 18:18:53 by hwichoi           #+#    #+#             */
/*   Updated: 2023/01/14 18:26:31 by hwichoi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

int	ft_flag(char *arg)
{
	int	i;

	i = 0;
	if (!arg)
		return (0);
	if (arg[i] == '-' && arg[i + 1] != '\0')
	{
		i++;
		while (arg[i])
		{
			if (arg[i] == 'n')
				i++;
			else
				return (0);
		}
		return (1);
	}
	return (0);
}

void	ft_echo(char **args)
{
	int	i;
	int	flag;

	i = 1;
	flag = ft_flag(args[i]);
	if (flag)
		while (ft_flag(args[i]))
			i++;
	while (args[i])
	{
		ft_putstr_fd(args[i], 1);
		if (args[i + 1])
			ft_putchar_fd(' ', 1);
		i++;
	}
	if (!flag)
		ft_putchar_fd('\n', 1);
}
