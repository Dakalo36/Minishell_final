/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kioulian <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/20 18:32:01 by kioulian          #+#    #+#             */
/*   Updated: 2016/08/22 16:12:07 by dnematan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# include <stdlib.h>
# include "../libft/includes/libft.h"
# include <dirent.h>

typedef struct	s_env
{
	char		**environ;
	char		*line;
	char		**args;
}				t_env;

char			*ft_getenv(char *str, t_env *e);
void			ft_env(t_env *e);
void			free_tab(char **tab);
int				search_paths(t_env *e);
void			run_exec(char *path, t_env *e);
void			ft_echo(t_env *e);
char			**tab_add(char **environ, char *str);
void			ft_setenv(t_env *e);
void			get_environ(t_env *e);
char			*ft_replace_env(int *check, char *str, char *tab);
void			run_command(t_env *e);
int				ft_unsetenv(t_env *e);
void			ft_del_env(int *check, char **environ, int index);

#endif
