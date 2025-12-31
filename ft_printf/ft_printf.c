/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thtay <thtay@student.42singapore.sg>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/19 21:36:29 by thtay             #+#    #+#             */
/*   Updated: 2025/12/19 21:36:32 by thtay            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//////////////////////////////////////////////||
//                                            ||
//   malloc, free, write    <-- libft         ||
//   va_start, va_arg, va_copy, va_end        ||
//                                            |||||||||
//   c char       d decimal     x small hex          ||
//   s string     i integer     X UPPER HEX          ||
//   p pointer    u unsigned    % Control / escape   ||
//                                                   ||
/////////////////////////////////////////////////////||

#include "ft_printf.h"

int	ft_printf(const char *str, ...)
{
	int		incr;
	va_list	control;

	if (!str)
		return (-1);
	incr = 0;
	va_start(control, str);
	while (*str)
	{
		if (*str == '%')
		{
			str++;
			incr += pf_handle(*str, control);
			if(*str == '\0')
				break ;
			str++;
			continue ;
		}
		ft_putchar_fd(*str, 1);
		str++;
		incr++;
	}
	va_end(control);
	return (incr);
}
