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

// buffer is declared upon compilation and is thus not a VLA

#include "get_next_line.h"

char	*get_next_line(int fd)
{
	char			*stash;
	static size_t	r_idx[1025];
	static char		buffer[BUFFER_SIZE];

	if (BUFFER_SIZE == 0)
		return (NULL);
	stash = NULL;
	while (1)
	{
		r_idx[fd] = read(fd, buffer, BUFFER_SIZE); //read into buffer
		if(r_idx[fd] > 0) //if something was read (and not error)
		{
			ft_strljoin(stash, buffer, r_idx[fd]); //dup (join) into stash

		}
	}
	return (stash);
}
