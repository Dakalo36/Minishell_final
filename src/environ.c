/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   environ.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kioulian <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/23 11:19:43 by kioulian          #+#    #+#             */
/*   Updated: 2016/08/21 18:32:16 by kioulian         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	get_environ(t_env *e)
{
	extern char	**environ;
	int			y;

	y = 0;
	while (environ[y])
		y++;
	e->environ = (char **)malloc(sizeof(char*) * (y + 1));
	y = 0;
	while (environ[y])
	{
		e->environ[y] = ft_strdup(environ[y]);
		y++;
	}
	e->environ[y] = 0;
}

int		ft_unsetenv(t_env *e)
{
	int	check;
	int	i;
	int	y;

	i = 0;
	check = 0;
	while (e->args[i])
	{
		y = 0;
		while (e->environ[y])
		{
			if (ft_strncmp(e->environ[y], e->args[i],
						ft_indexof(e->environ[y], '=')) == 0)
				ft_del_env(&check, e->environ, y);
			y++;
		}
		i++;
	}
	return (check);
}

void	ft_env(t_env *e)
{
	int	y;

	y = 0;
	while (e->environ[y] != 0)
	{
		ft_putstr(e->environ[y]);
		ft_putchar('\n');
		y++;
	}
}

void	ft_setenv(t_env *e)
{
	int	i;
	int	y;
	int	check;

	i = 1;
	y = 0;
	while (e->args[i])
	{
		check = 0;
		if (ft_strchr(e->args[i], '=') != NULL)
		{
			while (e->environ[y] != 0)
			{
				if ((ft_strncmp(e->environ[y], e->args[i],
							ft_indexof(e->args[i], '='))) == 0)
					e->environ[y] = ft_replace_env(&check, e->args[i],
							e->environ[y]);
				y++;
			}
			if (!check)
				e->environ = tab_add(e->environ, e->args[i]);
		}
		i++;
	}
}

char	*ft_getenv(char *str, t_env *e)
{
	int	y;

	y = 0;
	while (e->environ[y] != 0)
	{
		if (ft_strstr(e->environ[y], str) != NULL)
			return (&e->environ[y][ft_strlen(str) + 1]);
		y++;
	}
	return (NULL);
}
