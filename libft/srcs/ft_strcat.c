/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strcat.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: ihering- <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/01/13 11:09:54 by ihering-       #+#    #+#                */
/*   Updated: 2019/07/01 10:11:07 by ihering-      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

char	*ft_strcat(char *s1, const char *s2)
{
	char *s11;
	char *s22;

	s11 = s1;
	s22 = (char*)s2;
	while (*s11 != '\0')
		s11++;
	while (*s22 != '\0')
	{
		*s11 = *s22;
		s11++;
		s22++;
	}
	*s11 = '\0';
	return (s1);
}
