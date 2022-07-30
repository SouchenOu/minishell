/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cd.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yismaili < yismaili@student.1337.ma>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/22 11:21:32 by souchen           #+#    #+#             */
/*   Updated: 2022/07/29 21:23:47 by yismaili         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "includes/minishell.h"

bool	there_is_home(t_struct *shell)
{
	if (find_env_tmp(shell, "HOME"))
		return (true);
	else
		return (false);
}

void    replace_oldpwd(t_struct *env)
{
    char    *buff = NULL;
	int		i = 0;
   
    buff = getcwd(buff, sizeof(buff));
	if (glob_var == 0)
	{
		 env->env.tmp_con[0] = ft_strdup(buff);
		 return ;
	}
    while (env->env.tmp_var[i])
    {
        if (!ft_strcmp(env->env.tmp_var[i], "OLDPWD"))
        {
                free(env->env.tmp_con[i]);
                env->env.tmp_con[i] = ft_strdup(buff);
				free(buff);
            return ;
        }
        i++;
    }
	free(buff);
}

void    replace_pwd(t_struct *env)
{
    char    *buff = NULL;
	int		i = 0;
   
    buff = getcwd(buff, sizeof(buff));
	if (glob_var == 0)
	{
		 env->env.tmp_con[0] = ft_strdup(buff);
		 return ;
	}
    while (env->env.tmp_var[i])
    {
        if (!ft_strcmp(env->env.tmp_var[i], "PWD"))
        {
                free(env->env.tmp_con[i]);
                env->env.tmp_con[i] = ft_strdup(buff);
				free(buff);
            return ;
        }
        i++;
    }
	free(buff);
}

int	ft_cd(t_struct *shell)
{
	char	*arg_aux = NULL;
	//bool	home;
	char	*current_path = NULL;
	char	*old_path = NULL;

	if (glob_var == 0)
	{
		ft_die("PWD not fuond\n");
		return (0);
	}
	//home = there_is_home(shell);
	if (!ft_strcmp(shell->arguments[1], "-"))
	{
		int i = 0;
		current_path = getcwd(current_path, sizeof(current_path));
		while (shell->env.tmp_var[i]) 
		{
			if (!ft_strcmp(shell->env.tmp_var[i], "OLDPWD"))
			{
				old_path = ft_strdup(shell->env.tmp_con[i]);
				break;
			}
			i++;
		}
		if (!ft_strcmp(current_path, old_path))
		{
			ft_putstr_fd("Minishell: cd: OLDPWD not set\n", 2);
			//g_status = 1;
		}
		else
		{
			if (ft_strcmp(old_path, current_path))
			{
				replace_oldpwd(shell);
				if (chdir(old_path) == -1)
				{
					ft_not_found(shell->arguments[1]);
					//g_status = 1;
				}
				ft_putstr_fd(current_path, shell->output_fd);
				printf("\n");
				replace_pwd(shell);
			}
		}
		free(old_path);
		old_path = NULL;
		free(current_path);
		old_path = NULL;
		return(0);
	}
	if (shell->arguments[1])
	{
		arg_aux = ft_strdup(shell->arg.all_cmd);
	}
	// else
	// {
	// 	if (home == true)
	// 	{
	// 		arg_aux = ft_strdup(shell->home);
	// 	}
	// 	else
	// 	{
	// 		printf("Error/ home not set\n");
	// 		return (1);
	// 	}
	// }
	replace_oldpwd(shell);
	if (chdir(arg_aux) == -1)
	{
		ft_not_found(shell->arguments[1]);
		// g_status = 1;
	}
	replace_pwd(shell);
	free(arg_aux);
	return (0);
}
void ft_not_found(char *dir)
{
	if (dir)
	{
		ft_putstr_fd("Minishell: cd: ", 2);
		ft_putstr_fd(dir, 2);
		ft_putstr_fd(": no such file or directory\n", 2);
	}
}