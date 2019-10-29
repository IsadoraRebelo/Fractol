/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   menu.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: ihering- <ihering-@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/07/21 15:09:44 by ihering-       #+#    #+#                */
/*   Updated: 2019/08/01 15:25:26 by ihering-      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	ft_menu(t_fractol *f)
{
	int		i;

	i = 0;
	mlx_string_put(f->mlx, f->win, 30, i += 20, 0x9B9B9B, "WELCOME TO FRACTOL");
	mlx_string_put(f->mlx, f->win, 30, i += 30, 0x9B9B9B, "Controls:");
	if (f->fractol == 0)
		mlx_string_put(f->mlx, f->win, 30, i += 30, 0x9B9B9B, "You Choose \
						the Mandelbrot Set");
	if (f->fractol == 2)
		mlx_string_put(f->mlx, f->win, 30, i += 30, 0x9B9B9B, "You Choose \
						the Burning Ship Set");
	mlx_string_put(f->mlx, f->win, 30, i += 30, 0x9B9B9B, "Move: Use Arrows");
	mlx_string_put(f->mlx, f->win, 30, i += 30, 0x9B9B9B, "Zoom: Scroll");
	mlx_string_put(f->mlx, f->win, 30, i += 30, 0x9B9B9B, "R: Reset");
	mlx_string_put(f->mlx, f->win, 30, i += 30, 0x9B9B9B, "ESC: Quit");
	mlx_string_put(f->mlx, f->win, 1150, i -= 180, 0x9B9B9B, "Colors:");
	mlx_string_put(f->mlx, f->win, 1100, i += 30, 0x9B9B9B, "S: Color Set \
					Standard");
	mlx_string_put(f->mlx, f->win, 1100, i += 30, 0x9B9B9B, "P: Color Set \
					Psychedelic");
	mlx_string_put(f->mlx, f->win, 1100, i += 30, 0x9B9B9B, "B: Color Set \
					Brazil");
}

void	ft_juliamenu(t_fractol *f)
{
	int		i;

	i = 0;
	mlx_string_put(f->mlx, f->win, 30, i += 20, 0x9B9B9B, "WELCOME TO FRACTOL");
	mlx_string_put(f->mlx, f->win, 30, i += 20, 0x9B9B9B, "You Choose \
					the Julia Set");
	mlx_string_put(f->mlx, f->win, 30, i += 30, 0x9B9B9B, "Controls:");
	mlx_string_put(f->mlx, f->win, 30, i += 30, 0x9B9B9B, "Move: Use Arrows");
	mlx_string_put(f->mlx, f->win, 30, i += 30, 0x9B9B9B, "Zoom: Scroll");
	mlx_string_put(f->mlx, f->win, 30, i += 30, 0x9B9B9B, "Left Button: \
					Lock / Unlock");
	mlx_string_put(f->mlx, f->win, 30, i += 30, 0x9B9B9B, "R: Reset");
	mlx_string_put(f->mlx, f->win, 30, i += 30, 0x9B9B9B, "ESC: Quit");
	mlx_string_put(f->mlx, f->win, 1150, i -= 200, 0x9B9B9B, "Colors:");
	mlx_string_put(f->mlx, f->win, 1100, i += 30, 0x9B9B9B, "S: Color Set \
					Standard");
	mlx_string_put(f->mlx, f->win, 1100, i += 30, 0x9B9B9B, "P: Color Set \
					Psychedelic");
	mlx_string_put(f->mlx, f->win, 1100, i += 30, 0x9B9B9B, "B: Color Set \
					Brazil");
}

void	writemenu(t_fractol *f)
{
	if (f->fractol == 0 || f->fractol == 2)
		ft_menu(f);
	else if (f->fractol == 1)
		ft_juliamenu(f);
}
