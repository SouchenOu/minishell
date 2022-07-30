/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: souchen <souchen@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/22 11:30:46 by souchen           #+#    #+#             */
/*   Updated: 2022/07/30 12:19:28 by souchen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef MINISHELL_H
# define MINISHELL_H

# include "../libft/libft.h"
# include <stdio.h>
# include <stdbool.h>
# include </Users/souchen/goinfre/.brew/opt/readline/include/readline/readline.h>
# include </Users/souchen/goinfre/.brew/opt/readline/include/readline/history.h>
# include <sys/wait.h>
# include <signal.h>
# include <fcntl.h>
#include <dirent.h>


# define Double_Quote '\"'
# define QUOTE '\''
# define D_QUOTE_S "\""
# define QUOTE_S "\'"
# define WHITE "\001\033[0m\002"
# define GREEN "\001\033[1;32m\002"
# define RED "\033[0;31m"

int glob_var;
int g_status;

typedef struct s_env
{
	char	**env;
	int		len;
	char	**tmp_var;
	char	**tmp_con;
	int		position;;
}			t_env;
typedef struct s_divise
{
	int		number_command;
	int		initial;
	int		len;
	int		quote;
	int		pipe;
}			t_divise;

typedef struct s_arg
{
	char	*all_cmd;
	char	*to_exec;
	char    *txt_toprint;
	char	quote;
	char	*seconde;
	char	*first;
	int		i;
	int		init;
	int		len;
	int		position;
}			t_arg;

typedef struct s_struct
{
	int	builtin_exist;
	int		last_redir;
	int		output_fd;
	int		input_fd;
	int		cmp;
	char	*line_commande;
	char	*commande_tape;
	char	*home;
		pid_t	pid;
	char	*commands[600000];
	char	**arguments;
	char	**cmd_splited;
	///char	**path;
	t_env	env_aux;
	t_env	env;
	t_divise divise;
	t_arg	arg;
}			t_struct;

int		builtin_exist(t_struct *shell);
void	run_builtin(t_struct *shell);
int		count_len_env(t_struct *shell);
void	ft_exit(t_struct *shell);
void	free_line(char *line_read);
void	free1(char **array);
void	free2(char **array);
void	ft_unset(t_struct *shell);
void	remove_env(t_struct *shell);
//int		get_path(t_struct *shell);
void	print_welcome(void);
char	*get_current_dir(void);
char	*create_prompt(void);
void	run_commands(t_struct *shell);
void	run_commande_next(t_struct *shell);
void	fun_redirection(t_struct *shell);
void	execution(t_struct *shell);
void	divise_commande(t_struct *shell, char *in);
void	arguments_func(t_struct *shell);
int		argument_find_char(char *string, char needle);
void	free_arg(t_arg *arg);
void	finish_put_arg(t_struct *shell, t_arg *arg);
void 	init_divise_struct(t_struct *shell);
t_arg	*init_arg();
void 	ft_env(t_struct *shell);
void 	ft_export(t_struct *shell);
bool 	there_is_home(t_struct *shell);
int 	ft_cd(t_struct *shell);
void 	ft_pwd();
void 	ft_echo(t_struct *shell);
int 	init_echo(t_struct *shell, int n);
void 	print_echo(t_struct *shell,char* shell_print);
void 	ft_export(t_struct *shell);
void 	verify_if_env_exists(t_struct *shell, char **env_aux);
void 	export_to_env(t_struct *shell, char *new_elem_tab1, char *new_elem_tab2);
void 	pipe_next(t_struct *shell, int i, char *command);
void 	inredirection(t_struct *shell);
void 	outredirection(t_struct *shell);
void 	next_run_commands(t_struct *shell);
void 	next(int i, t_struct *shell, char*commande_read);
char 	*execute_cmd(t_struct *shell, char **path);
void 	output_input(t_struct *shell);
void 	check_to_execute(t_struct *shell);
void    sig_handler(int signum);
void 	cmd_not_found(char *cmd);
int 	check_export(t_struct *export);
int 	ft_search(t_struct *env, char *var);
int 	malloc_env_tmp(t_struct *shell);
char	*find_env_tmp(t_struct *shell, char *search);
int		commande_tape(t_struct	*shell);
int		malloc_env_aux_tmp(t_struct *shell);
void	ft_die(char *str);
int		create_env_tmp(t_struct *shell, char **my_env);
int  	start_create_env(t_struct *shell);
void	ft_die_malloc(char *str);
void	ft_check_env(char **env);
void ft_free_env(char **env);
void	ft_free_cmd(char **cmd);
int	line_empty(char *input);
void ft_not_found(char *dir);
char	*ft_split_cmd(char *cmd);
int ft_serch_in_env(t_struct *env, char	*var, char *con);
#endif