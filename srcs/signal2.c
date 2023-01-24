/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signal2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hwichoi <hwichoi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/14 18:21:38 by hwichoi           #+#    #+#             */
/*   Updated: 2023/01/14 18:26:49 by hwichoi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

void	ft_ctrl_bslash(int signal)
{
	(void) signal;
	if (signal == SIGQUIT)
	{
		ft_putstr_fd(ft_strjoin(rl_prompt, rl_line_buffer), 2);
		ft_putstr_fd("  \b\b", 2);
		rl_redisplay();
	}
}

void	ft_ctrl_f_bslash(int signal)
{
	(void) signal;
	if (signal == SIGQUIT)
	{
		g_rvalue = 131;
		ft_putstr_fd("Quit: 3\n", 2);
		rl_redisplay();
	}
}
