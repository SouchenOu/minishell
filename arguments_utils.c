/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arguments_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yismaili < yismaili@student.1337.ma>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/22 11:20:07 by souchen           #+#    #+#             */
/*   Updated: 2022/07/29 18:10:46 by yismaili         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "includes/minishell.h"


t_arg	*init_arg(void)
{
	t_arg	*arg;

	arg = (t_arg *)malloc(sizeof(t_arg));
	arg->first = NULL;
	arg->all_cmd = NULL;
	arg->txt_toprint = NULL;
	arg->i = 0;
	arg->init = 0;
	arg->len = 1;
	arg->position = 0;
	return (arg);
}

void	free_arg(t_arg *arg)
{
	if (arg->first != NULL)
	{
		free(arg->first);
		arg->first = NULL;
	}
	if (arg-> all_cmd != NULL)
	{
		free(arg->all_cmd);
		arg->all_cmd = NULL;
	}
	if(arg-> txt_toprint != NULL)
	{
		free(arg->txt_toprint);
		arg->txt_toprint= NULL;
	}
	free(arg);
}

