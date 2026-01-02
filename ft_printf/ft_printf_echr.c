/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_echr.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thtay <thtay@student.42singapore.sg>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/02 15:06:40 by thtay             #+#    #+#             */
/*   Updated: 2026/01/02 15:06:42 by thtay            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

//mostly just to parse
static int	type_int(int arg)
{
	if (arg)
		return (0);
	return (0);
}

//mostly just to parse (electric boogaloo)
static int	type_uint(unsigned int arg)
{
	if (arg)
		return (0);
	return (0);
}

//it should print. if NULL, print "(null)" [6]. actually...
static int	type_str(char *arg)
{
	if (arg)
		return (0);
	return (0);
}

int	pf_echr(char flag, va_list args)
{
	if (flag == '\0')
		return (-1);
	if (flag == '%')
		return (0);
	if (flag == 'c' || flag == 'i' || flag == 'd')
		return (type_int(va_arg(args, int)));
	if (flag == 'u' || flag == 'x' || flag == 'X')
		return (type_uint(va_arg(args, unsigned int)));
	if (flag == 's')
		return (type_str(va_arg(args, char *)));
	return (-1);
}
