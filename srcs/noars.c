/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   noars.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hwichoi <hwichoi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/14 18:20:39 by hwichoi           #+#    #+#             */
/*   Updated: 2023/01/14 18:26:40 by hwichoi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

void	the_noar(char	*line)
{
	free(line);
	exit(0);
}