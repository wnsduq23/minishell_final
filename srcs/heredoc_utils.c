/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   heredoc_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hwichoi <hwichoi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/14 18:20:23 by hwichoi           #+#    #+#             */
/*   Updated: 2023/01/14 18:26:37 by hwichoi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

int	do_heredoc(t_lst_cmd *lst_cmd, t_minishell *data)
{
	if (lst_cmd->lst_herdoc)
	{
		if (!lst_cmd->lst_herdoc->file)
			return (return_error_syntax_2());
		else if (ft_heredoc(lst_cmd, data) == -1)
			return (-1);
	}
	return (0);
}
