/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   divise_commande.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yismaili < yismaili@student.1337.ma>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/22 11:21:25 by souchen           #+#    #+#             */
/*   Updated: 2022/07/26 21:53:21 by yismaili         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/minishell.h"

void	initial_divise(t_struct *shell)
{
	shell->divise.number_command = 0;
	shell->divise.initial = 0;
	shell->divise.quote = 0;
	shell->divise.pipe = 0;
	shell->cmp = 0;
}

void	divise_commande(t_struct *shell, char *commande_read)
{
	int	i;
	int len;

	i = 0;
	len = 0;
	initial_divise(shell);
	while (i < (int)ft_strlen(commande_read))
	{
		if (shell->divise.quote == 0 && \
				(commande_read[i] == Double_Quote || commande_read[i] == QUOTE))
			shell->divise.quote++;
		if (commande_read[i] == '|' || \
				commande_read[i] == '<' || commande_read[i] == '>')
		{
			if (commande_read[i] == '|')
				shell->divise.pipe++;
			if (i > 1 )
			{
				shell->commands[shell->divise.number_command] = \
					ft_substr(commande_read, shell->divise.initial, len);
				shell->divise.initial = i;
				len = 0;
				shell->divise.number_command++;
			}
		}
		i++;
		len++;
	}
	next (i, shell, commande_read);
}

void	next(int i, t_struct *shell, char *commande_read)
{
	if (ft_strlen(commande_read) > 0)
	{
		shell->commands[shell->divise.number_command] = \
			ft_substr(commande_read, shell->divise.initial, i);
		shell->divise.number_command++;
	}
	shell->commands[shell->divise.number_command] = NULL;
}
