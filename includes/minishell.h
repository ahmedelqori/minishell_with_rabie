/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: meedivo <meedivo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/10 15:47:38 by meedivo           #+#    #+#             */
/*   Updated: 2024/03/10 17:23:33 by meedivo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL
#define MINISHELL


/*========================= LIBRARY =========================*/

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <signal.h>
#include <readline/readline.h>
#include <readline/history.h>
#include <sys/wait.h>
#include <fcntl.h>
#include "../libft/libft.h"

/*========================= COLORS =========================*/


#define RESET "\033[0m"
#define BLACK "\033[30m"
#define RED "\033[31m"
#define GREEN "\033[32m"
#define YELLOW "\033[33m"
#define BLUE "\033[34m"
#define MAGENTA "\033[35m"
#define CYAN "\033[36m"
#define WHITE "\033[37m"
#define BOLDBLACK "\033[1m\033[30m"
#define BOLDRED "\033[1m\033[31m"
#define BOLDGREEN "\033[1m\033[32m"
#define BOLDYELLOW "\033[1m\033[33m"
#define BOLDBLUE "\033[1m\033[34m"
#define BOLDMAGENTA "\033[1m\033[35m"
#define BOLDCYAN "\033[1m\033[36m"
#define BOLDWHITE "\033[1m\033[37m"

/*========================= MACROS =========================*/

#define MINISHELL_PROMPT "MiniShell $> "
#define HOME "HOME"
#define PWD "PWD"
#define OLDPWD "OLDPWD"

#define SPACE_P " "
#define SPACE_C ' '
#define PIPE '|'
#define INPUT '<'
#define OUTPUT '>'
#define APPEND ">>"
#define HERE_DOC "<<"

typedef struct s_env
{
	char		 *key;
	char		 *value;
	struct s_env *next;
}       t_env;

/*========================= SIGNALS =========================*/

void    ft_signals(void);

/*========================= ENV =========================*/

t_env	*ft_new_node_env(char *key, char *value);
t_env	*ft_create_env(char **env_arr);
t_env	*ft_clear_env(t_env **env);
void	ft_addenv_back(t_env **env, t_env *node);
void	ft_print_env(t_env *env);
char	*ft_get_key_env(char *str);
char	*ft_get_value_env(char *str);

/*========================= HELPER 1 =========================*/

char    *ft_help_trim(char *input);
/*========================= PARSING  =========================*/

int join_line(char *s);
int check_line(char *str);


#endif