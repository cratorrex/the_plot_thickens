/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gnl_tests.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thtay <thtay@student.42singapore.sg>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/24 21:21:43 by thtay             #+#    #+#             */
/*   Updated: 2025/12/24 21:21:44 by thtay            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "gnl/get_next_line.h"

// char *join_t1(void)
// {
// 	char *str1 = ft_strdup("somewhere\n");
// 	char *str2 = ft_strdup("out there");
// 	return (ft_strjoin(str1, str2));
// }

// char *join_acav(char *s1, char *s2)
// {
// 	char *str1 = ft_strdup(s1);
// 	char *str2 = ft_strdup(s2);
// 	return (ft_strjoin(str1, str2));
// }

char *trim_t1(char *stastr)
{
	//char *str1 = ft_strdup("I'm on the top of the world,");
	char *str2 = ft_strdup(" looking down on creation");
	char *str3 = ft_strjoin(stastr, str2);
	
	char *str4 = ft_budtrim(str3, BUFFER_SIZE, stastr);
	printf("%s\n%s\n", stastr, str3);
	free(str3);
	return (str4);
}



int main(void)
{
	//////////////////////////////////
	//                             ///
	//  individual function tests  ///
	//                             ///
	//////////////////////////////////

	static char *stastr;
	if(stastr == NULL)
		stastr = ft_strdup("");
	stastr = ft_strdup("hello world there is life.");
	stastr = trim_t1(stastr);
	//printf("JoinT1:\n%s\n-----\n", join_t1());
	printf("TrimT1:\n%s\n-----\n", stastr);
	free(stastr);
}