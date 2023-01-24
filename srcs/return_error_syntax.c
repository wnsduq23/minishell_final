/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   return_error_syntax.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hwichoi <hwichoi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/14 18:21:16 by hwichoi           #+#    #+#             */
/*   Updated: 2023/01/14 18:26:46 by hwichoi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

int	return_error_syntax(void)
{
	ft_putstr_fd("minishell: syntax error near unexpected token `|'\n", 2);
	g_rvalue = 258;
	return (-1);
}

int	return_error_syntax_redir(void)
{
	ft_putstr_fd("minishell: syntax error near unexpected token `newline\"\n", 2);
	g_rvalue = 258;
	return (-1);
}

int	return_error_syntax_2(void)
{
	ft_putstr_fd("minishell: error syntax unexpected symbol\n", 2);
	g_rvalue = 2;
	return (-1);
}

int	return_error_fork(void)
{
	ft_putstr_fd("minishell: fork: Resource temporarily unavailable\n", 2);
	g_rvalue = 1;
	return (-1);
}
