/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rterp.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hwichoi <hwichoi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/14 18:21:23 by hwichoi           #+#    #+#             */
/*   Updated: 2023/01/14 18:26:48 by hwichoi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

int	rterp(char *arg)
{
	ft_putstr_fd("minishell: ", 2);
	ft_putstr_fd(arg, 2);
	ft_putstr_fd(": Permission denied\n", 2);
	g_rvalue = 1;
	return (-1);
}

int	rterf(char *arg)
{
	ft_putstr_fd("minishell: ", 2);
	ft_putstr_fd(arg, 2);
	ft_putstr_fd(": No such file or directory\n", 2);
	g_rvalue = 1;
	return (-1);
}
