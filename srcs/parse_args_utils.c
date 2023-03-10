/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_args_utils.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hwichoi <hwichoi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/14 18:20:55 by hwichoi           #+#    #+#             */
/*   Updated: 2023/01/14 18:26:43 by hwichoi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

void	ft_copy_char(char *line, t_var *var)
{
	var->lst_cmd->args[var->j] = ft_add_char(
			var->lst_cmd->args[var->j], line[var->i]);
	var->i++;
}

char	*ft_add_char(char *s1, char c)
{
	int		i;
	char	*str;

	i = 0;
	if (!s1)
		return (ft_gc_strdup(&c));
	if (!c)
		return (s1);
	str = ft_gc_calloc((ft_strlen(s1) + 2), sizeof(char));
	while (s1[i])
	{
		str[i] = s1[i];
		i++;
	}
	str[i] = c;
	i++;
	str[i] = '\0';
	ft_gc_free(s1);
	return (str);
}

void	ft_init_var(t_var *var)
{
	var->lst_cmd = ft_create_cell(NULL);
	var->lst_cmd->args[0] = ft_gc_calloc(1, sizeof(char) * 1);
	var->output = 0;
	var->i = 0;
	var->j = 0;
	var->tab_size = DEFAULT_TAB_SIZE;
	var->temp = NULL;
}

void	ft_write_char_output(char *line, t_var *var)
{
	if (var->output == 0)
	{
		var->lst_cmd->args[var->j] = ft_add_char(
				var->lst_cmd->args[var->j], line[var->i]);
		var->i++;
	}
	else if (var->output == 1)
	{
		var->lst_cmd->lst_in->file = ft_add_char(
				var->lst_cmd->lst_in->file, line[var->i]);
		var->i++;
	}
	else if (var->output == 2)
	{
		var->lst_cmd->lst_out->file = ft_add_char(
				var->lst_cmd->lst_out->file, line[var->i]);
		var->i++;
	}
	else if (var->output == 3)
	{
		var->lst_cmd->lst_herdoc->file = ft_add_char(
				var->lst_cmd->lst_herdoc->file, line[var->i]);
		var->i++;
	}
}

void	ft_write_string_output(int k, t_var *var, char **env, int n)
{
	if (var->output == 0)
	{
		var->lst_cmd->args[var->j] = ft_strjoin_free_s1(
				var->lst_cmd->args[var->j], &env[k][n + 1]);
	}
	else if (var->output == 1)
	{
		var->lst_cmd->lst_in->file = ft_strjoin_free_s1(
				var->lst_cmd->lst_in->file, &env[k][n + 1]);
	}
	else if (var->output == 2)
	{
		var->lst_cmd->lst_out->file = ft_strjoin_free_s1(
				var->lst_cmd->lst_out->file, &env[k][n + 1]);
	}
	else if (var->output == 3)
	{
		var->lst_cmd->lst_herdoc->file = ft_strjoin_free_s1(
				var->lst_cmd->lst_herdoc->file, &env[k][n + 1]);
	}
}
