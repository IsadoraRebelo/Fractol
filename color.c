/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   color.c                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: ihering- <ihering-@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/07/23 10:24:23 by ihering-       #+#    #+#                */
/*   Updated: 2019/07/29 13:11:34 by ihering-      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	put_pixel(int w, int h, int color, t_fractol *f)
{
	int		i;

	i = (w * 4) + (h * S_WIDTH) * 4;
	f->data[i] = color;
	f->data[i + 1] = color >> 8;
	f->data[i + 2] = color >> 16;
}

int		standard(int n)
{
	int		c;
	int		r;
	int		g;
	int		b;

	r = (n * 5);
	g = (255 - (n * 2));
	b = (255 - (n * 5));
	c = (r << 16) + (g << 8) + b;
	return (c);
}

int		psychedelic(int n)
{
	int		c;
	int		r;
	int		g;
	int		b;
	int		ct;

	ct = n + 1 - (log(2) / n / log(2));
	r = (sin(0.016 * ct + 4) * 230 + 25);
	g = (sin(0.013 * ct + 2) * 230 + 25);
	b = (sin(0.01 * ct + 1) * 230 + 25);
	c = r * g * b * 255;
	return (c);
}

int		brazil(int n)
{
	int		c;
	int		r;
	int		g;
	int		b;

	r = (n * 5);
	g = (255 - (n * 2));
	b = (255 - (n * 5));
	c = (r << 16) + (g << 8) + (b << 20);
	return (c);
}

int		colors(int n, t_fractol *f)
{
	int c;

	c = 0x000000;
	if (n == f->max_int)
		return (0x000000);
	else if (f->color == 1)
		c = standard(n);
	else if (f->color == 2)
		c = psychedelic(n);
	else if (f->color == 3)
		c = brazil(n);
	return (c);
}
