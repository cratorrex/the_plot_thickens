/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thtay <thtay@student.42singapore.sg>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/19 21:21:20 by thtay             #+#    #+#             */
/*   Updated: 2025/12/19 21:21:22 by thtay            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// read, malloc, free
//
//

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 16
# endif

# include <unistd.h>
# include <stdlib.h>
# include <stdarg.h>
# include <stdio.h>

char	*get_next_line(int fd);

size_t	ft_strlen(const char *str);
char	*ft_strdup(char *str);
char	*ft_budtrim(char *str, size_t idx, char *join);
//char	*ft_strchr(char	*str, char c);
char	*ft_strjoin(char *s1, char *s2);

//

#endif
