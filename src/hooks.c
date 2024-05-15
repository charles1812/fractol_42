/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cspreafi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/06 11:00:37 by cspreafi          #+#    #+#             */
/*   Updated: 2024/05/06 11:00:41 by cspreafi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	ft_zoom_hook(int keysym, int x, int y, t_list *ptr)
{
	double	tmp_x;
	double	tmp_y;
	double	center_x;
	double	center_y;

	center_x = (ptr->window_width / 10.0) * 5.7;
	center_y = ptr->window_height / 2.0;
	tmp_x = center_x / ptr->zoom_x + ptr->x_min;
	tmp_y = center_y / ptr->zoom_y + ptr->y_min;
	if (keysym == Button4)
	{
		ptr->zoom_x *= 1.05;
		ptr->zoom_y *= 1.05;
	}
	if (keysym == Button5)
	{
		ptr->zoom_x /= 1.05;
		ptr->zoom_y /= 1.05;
	}
	ptr->x_min = tmp_x - (center_x / ptr->zoom_x);
	ptr->y_min = tmp_y - (center_y / ptr->zoom_y);
	ft_put_image_to_window(ptr);
	return (0);
}

int	key_hook(int keysym, t_list *ptr)
{
	if (keysym == XK_Escape)
		destroy_fractol(ptr);
	return (0);
}

void	ft_draw_pixels(int x, int y, int color, t_list *ptr)
{
	int	i;
	int	*ptr2;

	if (x >= 0 && x < ptr->window_width && y >= 0 && y < ptr->window_height)
	{
		i = y * ptr->img->line_length + x * ptr->img->bits_per_pixel / 8;
		ptr2 = (int *)&ptr->img->data[i];
		*ptr2 = color;
	}
	else
		perror("you  are out of the window");
}

void	destroy_fractol(t_list *ptr)
{
	mlx_destroy_image(ptr->mlx_ptr, ptr->img->mlx_img);
	mlx_destroy_window(ptr->mlx_ptr, ptr->mlx_win);
	mlx_destroy_display(ptr->mlx_ptr);
	free(ptr->img);
	free(ptr->mlx_ptr);
	free(ptr);
	exit(0);
}
