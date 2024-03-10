/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_signals.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: meedivo <meedivo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/10 15:52:10 by meedivo           #+#    #+#             */
/*   Updated: 2024/03/10 15:52:18 by meedivo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

void    ft_handle_sigint(int sig)
{
    if (sig != SIGINT)
        return;
    printf("\n");
    rl_replace_line("",0);
    rl_on_new_line();
    rl_redisplay();
}

void    ft_signals(void)
{
    signal(SIGQUIT, SIG_IGN);
    signal(SIGINT, ft_handle_sigint);
}