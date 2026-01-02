/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_handler.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thtay <thtay@student.42singapore.sg>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/29 15:59:01 by thtay             #+#    #+#             */
/*   Updated: 2025/12/29 15:59:02 by thtay            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

//char	*pf_handle2(char flag, va_list args);

int	pf_handle(char flag, va_list args)
{
	if (flag == 'c')
		return (handle_char(va_arg(args, int)));
	else if (flag == 's')
		return (handle_str(va_arg(args, char *)));
	else if (flag == 'i' || flag == 'd')
		return (handle_int(va_arg(args, int)));
	// else if (flag == 'u')
	// 	return (handle_uint(va_arg(args, unsigned int)));
	else
		return (pf_handle2(flag, args));
}

//because norm dislikes a bulky handle
int	pf_handle2(char flag, va_list args)
{
	if (flag == 'x')
		return (handle_hex(va_arg(args, unsigned int), 0));
	else if (flag == 'X')
		return (handle_hex(va_arg(args, unsigned int), 1));
// 	else if (flag == 'p')
// 		handle_pointer();
	else if (flag == '%')
		return (handle_char('%'));
	return (0);
}
