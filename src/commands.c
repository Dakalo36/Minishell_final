/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   commands.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kioulian <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/24 16:14:14 by kioulian          #+#    #+#             */
/*   Updated: 2016/08/22 16:44:17 by dnematan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include "environ.h"

void	ft_print_only(char *str)
{
	int	i;

	i = 0;
	if (str[i] == '"')
		i++;
	while (str[i] != '\0' && str[i] != '"')
	{
		ft_putchar(str[i]);
		i++;
	}
}
void	ft_echo(t_env *e)
{
	int		i;
	char	*str;

	i = 0;
	while (e->args[++i] != 0)
	{
		if (e->args[i][0] == '$')
		{
			str = ft_getenv(&e->args[i][1], e);
			if (str != NULL)
			{
				ft_putstr(str);
				ft_putchar(' ');
			}
		}
		else
		{
			ft_print_only(e->args[i]);
			ft_putchar(' ');
		}
	}
	ft_putchar('\n');
}

int		search_paths(t_env *e)
{
	t_search	env;

	env.paths = ft_strsplit(ft_getenv("PATH", e), ':');
	env.y = 0;
	while (env.y > -1 && env.paths[env.y] != 0)
	{
		env.dirp = opendir(env.paths[env.y]);
		while ((env.entry = readdir(env.dirp)) != NULL)
		{
			if (strcmp(env.entry->d_name, e->args[0]) == 0)
			{
				env.str = ft_strjoin(env.paths[env.y], "/");
				run_exec(ft_strjoin(env.str, env.entry->d_name), e);
				free(env.str);
				env.str = NULL;
				env.y = -2;
			}
		}
		closedir(env.dirp);
		env.y++;
	}
	free_tab(env.paths);
	return (env.y);
}

void	run_command(t_env *e)
{
	char	**tab;
	char	*path;
	int		len;

	tab = ft_strsplit(e->args[0], '/');
	len = 0;
	path = ft_strdup(e->args[0]);
	while (tab[len])
		len++;
	ft_strdel(&e->args[0]);
	e->args[0] = ft_strdup(tab[len - 1]);
	run_exec(path, e);
	free_tab(tab);
}
