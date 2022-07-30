/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pwd.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yismaili < yismaili@student.1337.ma>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/22 11:22:00 by souchen           #+#    #+#             */
/*   Updated: 2022/07/26 16:57:11 by yismaili         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "includes/minishell.h"
void	ft_pwd(t_struct *shell)
{
	char	*buf;

	buf = get_current_dir();
	if (!buf)
		return ;
	ft_putstr_fd(buf, shell->output_fd);
	ft_putstr_fd("\n", shell->output_fd);
	free(buf);
}

