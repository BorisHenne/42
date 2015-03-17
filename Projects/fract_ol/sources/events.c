/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbalestr <jbalestr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/02 20:10:28 by jbalestr          #+#    #+#             */
/*   Updated: 2015/03/10 13:12:59 by jbalestr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"
#include <mlx.h>

int			key_hook_press(int keycode, t_env *e)
{
	if (keycode == ESC)
		ft_envdel(e);
	else if (keycode == LEFT)
		e->offset_x -= 0.1f / e->zoom;
	else if (keycode == RIGHT)
		e->offset_x += 0.1f / e->zoom;
	else if (keycode == UP)
		e->offset_y -= 0.1f / e->zoom;
	else if (keycode == DOWN)
		e->offset_y += 0.1f / e->zoom;
	else if (keycode == KEY_R)
		init_var(e);
	else if (keycode == TAB)
		e->current_fractal = (e->current_fractal + 1) % NB_FRACTAL;
	key_press_color_fractal(keycode, e);
	expose_hook(e);
	return (0);
}

int			mouse_hook_press(int button, int x, int y, t_env *e)
{
	if (button == 1)
	{
		e->click_pos_x = x;
		e->click_pos_y = y;
	}
	else if (button == 5)
		e->zoom += e->zoom * 0.1f;
	else if (button == 4)
		e->zoom -= e->zoom * 0.1f;
	update_zoom(e);
	expose_hook(e);
	return (0);
}

int			mouse_hook_move(int x, int y, t_env *e)
{
	e->move_pos_x = x;
	e->move_pos_y = y;
	e->mouse_x = x / (double)WIDTH;
	e->mouse_y = y / (double)HEIGHT;
	e->julia_cx = -0.8 + e->mouse_x * 1.1;
	e->julia_cy = 0.3 - e->mouse_y * 0.32;
	if (x % 5 == 0 || y % 5 == 0)
		expose_hook(e);
	return (0);
}

int			expose_hook(t_env *e)
{
	draw(e);
	mlx_put_image_to_window(e->mlx, e->win, e->screen.ptr, 0, 0);
	return (0);
}
