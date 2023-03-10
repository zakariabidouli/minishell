/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   constructor.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zbidouli <zbidouli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/18 00:03:30 by zbidouli          #+#    #+#             */
/*   Updated: 2023/02/18 21:15:51 by zbidouli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_cmd	*exec_c(void)
{
	t_exec_c	*cmd;

	cmd = malloc(sizeof(t_exec_c));
	if (!cmd)
		terminated("error allocation command");
	ft_memset(cmd, 0, sizeof(t_cmd *));
	cmd->id = EXEC_ID;
	return ((t_cmd *)cmd);
}

t_cmd	*redir_c(t_cmd *sub_cmd, char *file, char *efile, int flag)
{
	t_redir_c	*cmd;

	cmd = malloc(sizeof(t_redir_c));
	if (!cmd)
		terminated("error allocation command");
	ft_memset(cmd, 0, sizeof(t_cmd *));
	cmd->id = REDIR_ID;
	cmd->cmd = sub_cmd;
	cmd->file = file;
	cmd->efile = efile;
	cmd->flag = flag;
	cmd->fd = set_fd(flag);
	return ((t_cmd *)cmd);
}

t_cmd	*pipe_c(t_cmd *left, t_cmd *right)
{
	t_pipe_c	*cmd;

	cmd = malloc(sizeof(t_pipe_c));
	if (!cmd)
		terminated("error allocation command");
	ft_memset(cmd, 0, sizeof(t_cmd *));
	cmd->id = PIPE_ID;
	cmd->left = left;
	cmd->right = right;
	return ((t_cmd *)cmd);
}

t_cmd	*list_c(t_cmd *left, t_cmd *right)
{
	t_list_c	*cmd;

	cmd = malloc(sizeof(t_list_c));
	if (!cmd)
		terminated("error allocation command");
	ft_memset(cmd, 0, sizeof(t_cmd *));
	cmd->id = LIST_ID;
	cmd->left = left;
	cmd->right = right;
	return ((t_cmd *)cmd);
}

t_cmd	*back_c(t_cmd *backcmd)
{
	t_back_c	*cmd;

	cmd = malloc(sizeof(t_back_c));
	if (!cmd)
		terminated("error allocation command");
	ft_memset(cmd, 0, sizeof(t_cmd *));
	cmd->id = BACK_ID;
	cmd->cmd = backcmd;
	return ((t_cmd *)cmd);
}
