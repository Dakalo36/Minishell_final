/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mem.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kioulian <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/24 13:48:55 by kioulian          #+#    #+#             */
/*   Updated: 2016/08/19 18:54:18 by kioulian         ###   ########.fr       */
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

void	tab_add(char ***environ, char *str)
{
	char	**temp;
	int		y;
	int		len;
	char	**fre;

	y = 0;
	len = 0;
	while ((*environ)[len] != 0)
		len++;
	temp = (char **)malloc(sizeof(char*) * (len + 2));
	temp[len + 1] = 0;
	while (y < len)
	{
		temp[y] = ft_strdup((*environ)[y]);
		y++;
	}
	fre = *environ;
	temp[len] = ft_strdup(str);
	*environ = temp;
	free_tab(fre);
	free(fre);
	fre = NULL;
}

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
	free(tab);
	tab = NULL;
}
