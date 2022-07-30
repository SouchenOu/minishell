/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_echo.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yismaili < yismaili@student.1337.ma>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/22 11:21:38 by souchen           #+#    #+#             */
/*   Updated: 2022/07/29 12:27:14 by yismaili         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "includes/minishell.h"

void	ft_echo(t_struct *shell)
{
	int i = 1;

	while (shell->arguments[i])
	{
		if (!ft_strncmp(shell->arguments[1], "-n", 2) && i == 1)
		{
			i++;
		}
		if (shell->arguments[i])
		{
			print_echo(shell, shell->arguments[i]);
			ft_putstr_fd(" ", shell->output_fd);
		}
		i++;
	}
	if (ft_strncmp(shell->arguments[1], "-n", 2))
		ft_putstr_fd("\n", shell->output_fd);
}


void	print_echo(t_struct *shell ,char *echo_print)
{
	size_t i;
	char **splted;

	i = 0;
	if (!ft_strcmp(echo_print, "$?"))
	{
		ft_putnbr_fd(g_status, shell->output_fd);
		printf("\n");
	}
	else 
	{
		if (!ft_strncmp(echo_print, "$", 1))
		{
				splted = ft_split(echo_print, '$');
				if (!getenv(splted[0]))
					return	;
				while (shell->env.tmp_var[i])
				{
					if (!ft_strcmp(shell->env.tmp_var[i], splted[0]))
					{
						ft_free_cmd(splted);
						free(splted);
						ft_putstr_fd(shell->env.tmp_con[i], shell->output_fd);
						//g_status = 0;
						return ;
					}
					i++;
				}
				ft_free_cmd(splted);
				free(splted);
		}
		else
		{
			ft_putstr_fd(echo_print,shell->output_fd);
		//	g_status = 0;
		}
	}
}
