/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thtay <thtay@student.42singapore.sg>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/19 21:21:34 by thtay             #+#    #+#             */
/*   Updated: 2025/12/19 21:21:36 by thtay            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// read, malloc, free
//
// Basic idea is:
// ssize_t read(int fd, void *buf, size_t nbyte);
//
// if (nbyte == 0) >> maybe error or return (0);
// Nothing left or error, return (NULL);
//
// ! while read will constantly increment the read-head per each
// ! successive call of read().
//
// [     n  ] 
//        >>>[        ]
//                  >>>[        ]
// -D BUFFER_SIZE=10
//

#include "get_next_line.h"

char	*get_next_line(int fd)
{
	static char			*stash;
	static size_t		r_idx;

	if (BUFFER_SIZE == 0)
		return (NULL);
	stash = NULL;
	r_idx = 0;
}
