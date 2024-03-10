/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_syntax_error.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: meedivo <meedivo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/10 16:22:00 by meedivo           #+#    #+#             */
/*   Updated: 2024/03/10 17:42:01 by meedivo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/minishell.h"

static int escape_quote (char *s, int i)
{
    if (s[i] == '"')
    {
        i++;
        while (s[i] != '"' && s[i])
            i++;
        if (!s[i])
            return -1;
        else
            i++;
    }
    else if (s[i] == '\'')
    {
        i++;
        while (s[i] != '\'' && s[i])
            i++;
        if (!s[i])
            return -1;
        else
            i++;
    }
    return i;
}

int check_pipe(char *s, int i)
{
    if (s[i] == '|')
    {
        i++;
        while (s[i] == ' ')
            i++;
        if (!s[i])
            return -1;
    }
    return i;
}

int join_line(char *s)
{
    int i = 0;
    while (s[i])
    {
        if (s[i] == '"' || s[i] == '\'')
        {
            if (escape_quote(s, i) > 0)
                i = escape_quote(s, i);
            else
                return (0);
        }
        else if (s[i] == '|')
        {
            if (check_pipe(s, i) < 0)
                return 0;
            else
                i = check_pipe(s, i);
        }
        else if (s[i])
            i++;
    }
    return 1;
}

int is_cursed(char c)
{
    if (c == '|' || c == '&' || c == '-' || c == '>' || c == '<')
        return 1;
    return 0;
}
int find_export(char *str)
{
    int i = 0;
    char *s = "export";
    while (str[i])
    {
        int k = 0;
        while(str[i+k] && s[k] && str[i + k] == s[k])
            k++;
        if (!s[k] && str[i + k] == ' ')
            return i;
        i++;
    }
    return -1;
}
int check_2(char *str)
{
    int i = 0;
    while ( str[i])
    {
        if (find_export(str + i) >= 0)
        {
            i = find_export(str + i) + ft_strlen("export");
            while (str[i] && str[i] != '=')
                i++;
            if (str[i] == '=' && str[i - 1] == ' ')
                return 0;
        }
        if (str[i])
            i++;
    }
    return 1;
}

int check_line(char *str)
{
    int i = 0;
    int count = 0;
    while (str[i])
    {
        if (i == 0 && str[i] == '|')
            return 0;
        if (str[i] == '>')
        {
            i++;
            while (str[i] == ' ')
                i++;
            if (str[i] &&str[i]!='>' && is_cursed(str[i]))
                return 0;
            while (str[i] == ' ' || str[i] == '>')
            {
                if (str[i] == ' ' && (str[i + 1] == '<' || str[i + 1] == '>' || str[i + 1] == '|'))
                    return 0;
                if (str[i] == '>')
                    count++;
                i++;
            }
            if (count > 1)
                return 0;
        }
        else if (str[i] == '<')
        {
            i++;
            while (str[i] == ' ')
                i++;
            if (str[i] &&str[i]!='<' && is_cursed(str[i]))
                return 0;
            while (str[i] == ' ' || str[i] == '<')
            {
                if (str[i] == ' ' && (str[i + 1] == '<' || str[i + 1] == '>' || str[i + 1] == '|'))
                    return 0;
                if (str[i] == '<')
                    count++;
                i++;
            }
            if (count > 1)
                return 0;
        }
        else if (str[i] == '|')
        {
            i++;
            count = 0;
            while (str[i] == ' ')
                i++;
            if (str[i] == '|')
                return 0;
        }
        if (str[i])
            i++;
    }
    if (!check_2(str))
        return 0;
    return 1;
}