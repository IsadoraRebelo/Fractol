/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_error.c                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: ihering- <ihering-@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/07/03 11:16:41 by ihering-       #+#    #+#                */
/*   Updated: 2019/07/03 11:19:16 by ihering-      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

void	ft_error(char *str)
{
	ft_putendl(str);
	exit(0);
}
