/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_env.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: meedivo <meedivo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/10 15:57:15 by meedivo           #+#    #+#             */
/*   Updated: 2024/03/10 16:01:26 by meedivo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "../../../includes/minishell.h"

// ========= CREATE NEW ENV NODE =========

t_env	*ft_new_node_env(char *key, char *value)
{
	t_env *node;

	node = malloc(sizeof(t_env));
	if (node == NULL)
		return (NULL);
	node->key = key;
	node->value = value;
	node->next = NULL;
	return (node);
}

// ========= ADD NODE BACK TO ENV LIST =========

void	ft_addenv_back(t_env **env, t_env *node)
{
	t_env	*tmp;

	tmp = (*env);
	if (node == NULL)
		return ;
	if ((*env) == NULL)
		(*env) = node;
	else
	{
		while (tmp->next)
			tmp = tmp->next;
		tmp->next = node;
	}
}

// ========= GET KEY FROM ENV =========

char	*ft_get_key_env(char *str)
{
	int		i;
	int 	j;
	char	*key;

	i = -1;
	while (str[++i])
		if (str[i] == '=')
			break;
	key = malloc(sizeof(char) * (i + 1));
	if (key == NULL)
		return (NULL);
	j = 0;
	while (j < i)
	{
		key[j] = str[j];
		j++;
	}
	key[j] = '\0';
	return (key);
}

// ========= GET KEY FROM ENV =========

char	*ft_get_value_env(char *str)
{
	int		i;
	char	*value;

	i = -1;
	while (str[++i])
		if (str[i] == '=')
			break;
	value = ft_strdup(str + i + 1);
	return (value);
}

t_env	*ft_clear_env(t_env **env)
{
	t_env *tmp;

	if (!env)
		return (NULL);
	while (*env)
	{
		free((*env)->key);
		free((*env)->value);
		tmp = (*env);
		(*env) = (*env)->next;
		free(tmp);
	}
	
	return (NULL);
}

// ========= CREATE NEW ENV =========


t_env	*ft_create_env(char **env_arr)
{
	t_env	*env;
	t_env	*node;
	char	*key;
	char	*value;
	int		i;

	i = 0;
	env = NULL;
	if (!env_arr)
		return (NULL);
	while (env_arr[i])
	{
		key = ft_get_key_env(env_arr[i]);
		value = ft_get_value_env(env_arr[i]);	
		node = ft_new_node_env(key, value);
		if (node == NULL)
		{
			free(key);
			free(value);
			return (ft_clear_env(&env));
		}
		ft_addenv_back(&env, node);
		i++;		
	}
	return (env);
}

// ========= PRINT ENV =========


void	ft_print_env(t_env *env)
{
	while (env)
	{
		printf("%s=%s\n",env->key,env->value);
		env = env->next;
	}
}