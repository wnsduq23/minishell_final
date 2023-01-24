/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pwd.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hwichoi <hwichoi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/14 18:21:08 by hwichoi           #+#    #+#             */
/*   Updated: 2023/01/14 18:26:45 by hwichoi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

int	ft_pwd(t_minishell *data)
{
	data->pwd = ft_gc_strdup(getcwd(NULL, 0));
	ft_putendl_fd(data->pwd, 1);
	exit (0);
	return (0);
}
