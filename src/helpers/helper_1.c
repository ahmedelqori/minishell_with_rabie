/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helper_1.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: meedivo <meedivo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/10 16:15:40 by meedivo           #+#    #+#             */
/*   Updated: 2024/03/10 16:18:19 by meedivo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

char    *ft_help_trim(char *input)
{
    char    *new;

    new = ft_strtrim(input, SPACE_P);
    free(input);
    return (new);
}