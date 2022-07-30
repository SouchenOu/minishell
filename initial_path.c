/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initial_path.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yismaili < yismaili@student.1337.ma>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/22 11:22:12 by souchen           #+#    #+#             */
/*   Updated: 2022/07/25 22:42:41 by yismaili         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "includes/minishell.h"


// int	get_path(t_struct *shell)
// {
// 	char	*path_next;
// 	int		i;
// 	char  *tmp;

// 	path_next = ft_strdup(find_env_tmp(shell, "PATH"));
// 	if (!path_next)
// 		return (0);
// 	shell->path = ft_split(path_next, ':');
// 	i = 0;
// 	while (shell->path[i])
// 	{
// 		tmp = shell->path[i];
// 		shell->path[i] = ft_strjoin(shell->path[i], "/");
// 		free (tmp);
// 		i++;
// 	}
// 	free(path_next);
// 	return (1);
// }

int  start_create_env(t_struct *shell)
{
	extern char **environ;
	ft_check_env(environ);
	if (!create_env_tmp(shell, environ))
		return(0) ;
	// if (!get_path(shell))
	// 	ft_die("PATH not found\n");
	//shell->home = ft_strdup(find_envernement(shell, "HOME"));
	return (1);
}
