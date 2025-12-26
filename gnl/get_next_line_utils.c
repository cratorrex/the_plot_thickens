/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thtay <thtay@student.42singapore.sg>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/19 21:21:43 by thtay             #+#    #+#             */
/*   Updated: 2025/12/19 21:21:44 by thtay            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// read, malloc, free
//
// helper functions go here
//
// strjoin, strdup, strchr, bud_trim, strlen

#include "get_next_line.h"

//here we go again...
size_t	ft_strlen(const char *str)
{
	size_t	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

//both have been malloced. so they have to also be freed.
//malloc a new string.
//stash is now s1 cat s2.
char	*ft_strjoin(char *s1, char *s2)
{
	size_t	init;
	size_t	cat;
	char	*join;

	init = 0;
	cat = 0;
	join = malloc(ft_strlen(s1) + ft_strlen(s2) + 1);
	if (!join)
		return (NULL);
	while (s1[init])
	{
		join[init] = s1[init];
		init++;
	}
	while (s2[cat])
	{
		join[init + cat] = s2[cat];
		cat++;
	}
	join[init + cat] = '\0';
	if(!ft_strlen(s1))
		free(s1);
	free(s2);
	return (join);
}

//find \n or \0.
// char	*ft_strchr(char	*str, char c)
// {

// }

//just trim and free the front.
//similar to strndup.
char	*ft_budtrim(char *str, size_t idx, char *join)
{
	size_t	incr;
	char	*ret;

	incr = 0;
	if (idx == 0)
		return (join);
	ret = malloc(idx + 1);
	if (!ret)
		return (join);
	while (incr < idx)
	{
		ret[incr] = str[incr];
		incr ++;
	}
	ret[incr] = '\0';
	join = ft_strjoin(join, ret);
	return (join);
}

// char	*k_budtrim(char *str, size_t idx, char *join)
// {
// 	size_t	i;
// 	char	*cat;
// 	char	*ret;

// 	i = 0;
// 	if (idx == 0)
// 		return (NULL);
// 	cat = malloc(idx + 1);
// 	if (!cat)
// 		return (NULL);
// 	while (i < idx)
// 	{
// 		cat[i] = str[i];
// 		i ++;
// 	}
// 	cat[i] = '\0';
// 	join = ft_strjoin(join, cat); printf("%s| |%s", join, cat);
// 	ret = malloc(ft_strlen(str) - idx + 1);
// 	if (!ret)
// 		return (NULL);
// 	while (str[i])
// 	{
// 		ret[i - idx] = str[i];
// 		i ++;
// 	}
// 	ret[i - idx] = '\0';
// 	return (ret);
// }

//colon three c comma question mark
char	*ft_strdup(char *str)
{
	size_t	i;
	char	*new;

	new = malloc(ft_strlen(str) + 1);
	if (!new)
		return (NULL);
	i = 0;
	while (str[i])
	{
		new[i] = str[i];
		i++;
	}
	new[i] = '\0';
	return (new);
}
