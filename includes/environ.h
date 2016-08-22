/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   environ.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kioulian <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/24 15:23:45 by kioulian          #+#    #+#             */
/*   Updated: 2016/08/22 16:05:26 by dnematan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ENVIRON_H
# define ENVIRON_H
# include <dirent.h>

typedef struct	s_search
{
	int				y;
	char			**paths;
	DIR				*dirp;
	struct dirent	*entry;
	char			*str;
}				t_search;

#endif
