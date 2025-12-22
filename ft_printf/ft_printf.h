/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thtay <thtay@student.42singapore.sg>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/19 21:22:01 by thtay             #+#    #+#             */
/*   Updated: 2025/12/19 21:22:02 by thtay            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/////////////////////////////////////////////|
//                                          ||
//   malloc, free, write                    ||
//                                          ||
//   va_start, va_arg, va_copy, va_end      ||
//                                          ||
//||||||||||||||||||||||||||||||||||||||||||||

//////////////|  ////////////////////////////////////////////////////||
//           ||  //  c char       d decimal     x small hex          ||
//  libft.h  ||  //  s string     i integer     X UPPER HEX          ||
//           ||  //  p pointer    u unsigned    % Control / escape   ||
//|||||||||||||  ////////////////////////////////////////////////////||

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <stdlib.h>
# include <stdarg.h>
# include <stdio.h>

int	ft_printf(const char *, ...);

#endif
