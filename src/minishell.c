/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: meedivo <meedivo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/10 15:49:14 by meedivo           #+#    #+#             */
/*   Updated: 2024/03/10 17:23:48 by meedivo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"


void    minishell(t_env *env)
{
    char *input;

    while(1)
    {
        ft_signals();
        input = readline(BOLDYELLOW MINISHELL_PROMPT RESET);
        
        if (input == NULL)
        {
            ft_clear_env(&env);
            exit(0);
        }
        if (*input)
            add_history(input);
        input = ft_help_trim(input);
        if (!join_line(input) || !check_line(input))
            printf(BOLDRED"Syntax Error\n");
        else
            printf("%s\n",input);
        free(input);
    }
}


int main(int ac ,char **av ,char **env_arr)
{
    t_env *env;
    
    (void)ac;
    (void)**av;
    env = NULL;
    env = ft_create_env(env_arr);
    minishell(env);
}