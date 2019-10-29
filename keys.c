/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   keys.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: ihering- <ihering-@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/07/28 12:49:44 by ihering-       #+#    #+#                */
/*   Updated: 2019/08/01 15:17:56 by ihering-      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	key_colors(int key, t_fractol *f)
{
	if (key == SMOOTH)
		f->color = 1;
	else if (key == PSYCHE)
		f->color = 2;
	else if (key == BRAZIL)
		f->color = 3;
}

void	key_fractol(int key, t_fractol *f)
{
	if (key == RESET && f->fractol == 0)
		init_mandelbrot(f);
	else if (key == RESET && f->fractol == 1)
		init_julia(f);
	else if (key == RESET && f->fractol == 2)
		init_burningship(f);
}

void	key_menu(int key, t_fractol *f)
{
	if (key == EXIT)
		exit(EXIT_SUCCESS);
	if (key == RIGHT)
		f->width -= 10;
	else if (key == LEFT)
		f->width += 10;
	else if (key == UP)
		f->height += 10;
	else if (key == DOWN)
		f->height -= 10;
}

int		ft_keys(int key, t_fractol *f)
{
	key_colors(key, f);
	key_fractol(key, f);
	key_menu(key, f);
	if (f->fractol == 0)
		mandelbrot(f);
	else if (f->fractol == 1)
		julia(f);
	else if (f->fractol == 2)
		burningship(f);
	writemenu(f);
	return (0);
}
