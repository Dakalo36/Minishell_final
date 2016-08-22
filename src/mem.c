/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mem.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kioulian <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/24 13:48:55 by kioulian          #+#    #+#             */
/*   Updated: 2016/08/21 18:26:20 by kioulian         ###   ########.fr       */
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
		{
			ft_putstr("Command not found\n");
			exit(1);
		}
	}
	else
		waitpid(pid, &status, WUNTRACED);
	free(path);
	path = NULL;
}

char	**tab_add(char **environ, char *str)
{
	char	**temp;
	int		y;
	int		len;

	y = 0;
	len = 0;
	while (environ[len] != 0)
		len++;
	temp = (char **)malloc(sizeof(char*) * (len + 2));
	temp[len + 1] = 0;
	while (y < len)
	{
		temp[y] = ft_strdup(environ[y]);
		y++;
	}
	temp[len] = ft_strdup(str);
	free_tab(environ);
	return (temp);
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

char	*ft_replace_env(int *check, char *str, char *tab)
{
	char	*temp;

	*check = 1;
	free(tab);
	tab = NULL;
	temp = ft_strdup(str);
	return (temp);
}

void	ft_del_env(int *check, char **environ, int index)
{
	*check = 1;
	while (environ[index])
	{
		ft_strdel(&environ[index]);
		if (environ[index + 1])
			environ[index] = ft_strdup(environ[index + 1]);
		index++;
	}
}
