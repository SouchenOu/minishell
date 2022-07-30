/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arguments.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yismaili < yismaili@student.1337.ma>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/22 11:20:16 by souchen           #+#    #+#             */
/*   Updated: 2022/07/29 18:25:03 by yismaili         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "includes/minishell.h"

char	*ft_remove_quot(char *s1, char c)
{
	char	*dst = NULL;
	int		len = 0;
	int		i;

	i = 0;
	if (!s1 || !c)
		return (NULL);
	while (s1[i])
	{
		if(s1[i] != c)
		{
			len++;
		}
		i++;
	}
	i = 0;
	int j = 0;
	dst = (char *)malloc((len + 1) * sizeof(char));
	while (s1[i])
	{
		if(s1[i] != c)
		{
			dst[j] = s1[i];
			j++;
		}
		i++;
	}
	return (dst);
}

int	find_char(char *string, char needle)
{
	int	i;

	i = 0;
	while (string[i])
	{
		if (string[i] == needle)
			return (i);
		i++;
	}
	return (i);
}

char	*ft_split_cmd(char *cmd)
{
	char	*join = NULL;

	if (ft_strchr(cmd, '\"'))
		join = ft_remove_quot(cmd, '\"');
	else if (ft_strchr(cmd, '\''))
		join = ft_remove_quot(cmd, '\'');
	return (join);
}

void	arguments_func(t_struct *shell)
{
	t_arg	*arg;
	char *cmd_joined = NULL;
	char **spl =  NULL;
	char **spled;
	int i = 0;

	arg = init_arg();
	shell->arguments = NULL;
	if (shell->line_commande)
	{
		arg->position = find_char(shell->line_commande, ' ');
		shell->arg.all_cmd = ft_strtrim(&(shell->line_commande)[arg->position], " ");
		shell->arg.txt_toprint = ft_strtrim(&(shell->line_commande)[arg->position], " ");
		if (ft_strchr(shell->line_commande, '\"') || ft_strchr(shell->line_commande, '\''))
		{
			cmd_joined = ft_split_cmd(shell->line_commande);
			shell->arguments = ft_split(cmd_joined, ' ');
			spled = ft_split(cmd_joined, '|');
			free(cmd_joined);
		}
		else
		{
			shell->arguments = ft_split(shell->line_commande, ' ');
			spl = ft_split(shell->line_commande, '|');
			i = 0;
			while (spl[i])
			{
				cmd_joined = ft_strjoin(spl[i], spl[i +1]);
				i++;
			}
			spled = ft_split(cmd_joined, ' ');
			ft_free_cmd(spl);
			free(spl);
			free(cmd_joined);
		}
		i = 0;
		shell->cmd_splited =(char **)malloc(sizeof(char *) * 1000000);
		while (spled[i])
		{
			shell->cmd_splited[i] = ft_strdup(spled[i]);
			i++;	
		}
		free_arg(arg);
	}
}