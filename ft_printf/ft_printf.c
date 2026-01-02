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

//pass[0] >> pass[1]
static int	first_pass(const char *str, va_list control)
{
	int	flag;

	while (*str)
	{
		if (*str == '%')
		{
			str++;
			flag = pf_echr(*str, control);
			if (flag == -1)
				return (-1);
			str++;
			continue ;
		}
		str++;
	}
	return (0);
}

static int	second_pass(const char *str, va_list control)
{
	int		incr;

	incr = 0;
	while (*str)
	{
		if (*str == '%')
		{
			str++;
			incr += pf_handle(*str, control);
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

int	ft_printf(const char *str, ...)
{
	va_list	control;
	va_list	copy;

	va_start(control, str);
	va_copy(copy, control);
	if (!str)
		return (-1);
	if (first_pass(str, control) > -1)
		return (second_pass(str, copy));
	return (-1);
}
