/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mem.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kioulian <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/24 13:48:55 by kioulian          #+#    #+#             */
/*   Updated: 2016/07/24 15:49:52 by kioulian         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

void	run_exec(char *path, t_env *e)
{
	pid_t	pid;
	int		status;

	pid = fork();
	if (pid == 0)
	{
		if (execve(path, e->args, e->environ) == -1)
			ft_putstr("Error\n");
	}
	else
		waitpid(pid, &status, WUNTRACED);
	free(path);
	path = NULL;
}

char	**tab_add(char **tab, char *str)

void	free_tab(char **tab)
{
	int	y;

	y = 0;
	while (tab[y] != 0)
	{
		free(tab[y]);
		tab[y] = NULL;
		y++;
	}
}
