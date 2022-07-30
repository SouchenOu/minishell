/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_env.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: souchen <souchen@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/22 11:21:18 by souchen           #+#    #+#             */
/*   Updated: 2022/07/30 12:30:34 by souchen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "includes/minishell.h"

int	malloc_env_tmp(t_struct *shell)
{
	shell->env.tmp_var = malloc(sizeof(char *) * (shell->env.len + 1));
	if (!shell->env.tmp_var)
		return (0);
	shell->env.tmp_con = malloc(sizeof(char *) * (shell->env.len + 1));
	if (!shell->env.tmp_con)
		return (0);
	return (1);
}

int	count_len_env(t_struct *shell)
{
	int	i;

	i = 0;
	while (shell->env.env[i])
		i++;
	shell->env.len = i;
	return i;
}

void	ft_die(char *str)
{ 
	ft_putstr_fd(str, 1);
}

void	ft_die_malloc(char *str)
{ 
	ft_putstr_fd(str, 1);
	exit(1);
}
char	*find_env_tmp(t_struct *shell, char *search)
{
	int	i;
	int	length;
	int	len_search;

	i = 0;
	shell->env.position = 0;
	//if (glob_var == 0)
	//	return (NULL);
	len_search = ft_strlen(search);
	printf("search = %s\n", search);
	while (shell->env.tmp_var[i] && i <= shell->env.len)
	{
		//printf("env_tmp[%d]=%s\n",i, shell->env.tmp_var[i]);
		length = ft_strlen(shell->env.tmp_var[i]);
		if (!ft_strncmp(shell->env.tmp_var[i], search, len_search) && length == len_search)
		{
			shell->env.position = i;
			return (shell->env.tmp_con[i]);
		}
		i++;
	}
	return (NULL);
}

char	*get_current_dir(void)
{
	size_t	size;
	char	*buf;

	size = 2000;
	buf = NULL;
	buf = getcwd(buf, size);
	return (buf);
}

int	create_env_tmp(t_struct *shell, char **my_env)
{
	int		i;
	char	**env_divise;

	//if (glob_var != 0)
	//{
		shell->env.env = my_env;
		//printf("here\n");
	//}
	//else{
	//	return(0);
	//	printf("or here\n");
	//}
	count_len_env(shell);
	printf("len !!=%d\n", shell->env.len);
	if (!malloc_env_tmp(shell))
		ft_die_malloc("No spece lift\n");
	i = 0;
	while (shell->env.env[i])
	{
		env_divise = ft_split(shell->env.env[i], '=');
		shell->env.tmp_var[i] = ft_strdup(env_divise[0]);
		if (env_divise[1])
			shell->env.tmp_con[i] = ft_strdup(env_divise[1]);
		else
			shell->env.tmp_con[i] = ft_strdup("");
		if (env_divise)
			ft_free_env(env_divise);
		i++;
	}
	//shell->env.tmp_var[shell->env.len] = 0;
	//shell->env.tmp_con[shell->env.len] = 0;
	//int k=0;
	/*while(k < shell->env.len)
	{
		shell->env.tmp_var[k] = shell->env.tmp_var[k+1];  
		shell->env.tmp_con[k] = shell->env.tmp_con[k+1];
		k++;
	}*/
	/*printf("after her\n");
	k = 0;
	while(k < shell->env.len)
	{
		printf("env[%d]=%s\n", k,shell->env.tmp_var[k]);
		k++;
	}*/
	return (1);
}
void ft_free_env(char **env)
{
	int i = 0;
	while (env[i])
	{
		free(env[i]);
		env[i] = NULL;
		i++;
	}
	free(env);
}