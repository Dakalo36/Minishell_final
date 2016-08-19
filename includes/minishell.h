/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kioulian <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/20 18:32:01 by kioulian          #+#    #+#             */
/*   Updated: 2016/08/17 18:11:15 by kioulian         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# include <stdlib.h>
# include "../libft/includes/libft.h"

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
void			tab_add(char ***environ, char *str);
void			ft_setenv(t_env *e);

#endif
