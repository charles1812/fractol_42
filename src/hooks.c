#include "../inc/fractol.h"


int	zoom_hook(int keysym, int x, int y, t_list *ptr)
{
	double	tmp_x;
	double	tmp_y;

	tmp_x = x / ptr->zoom_x + ptr->x_min;
	tmp_y = y / ptr->zoom_y + ptr->y_min;
	if (keysym == Button4)
	{
		ptr->zoom_x *= 1.1;
		ptr->zoom_y *= 1.1;
		ptr->display_shift /= 1.1;
	}
	if (keysym == Button5)
	{
		ptr->zoom_x /= 1.1;
		ptr->zoom_y /= 1.1;
		ptr->display_shift *= 1.1;
	}
	ptr->x_min = tmp_x - (x / ptr->zoom_x);
	ptr->y_min = tmp_y - (y / ptr->zoom_y);
	ft_put_image_to_window(ptr);
	return (0);
}

int	key_hook(int keysym, t_list *ptr)
{
	if (keysym == XK_Escape)
		destroy_fractol(ptr);
	if (keysym == XK_f)
		ptr->color = ptr->color + 0xF0A0F0;
	if (keysym == XK_Up || keysym == XK_w)
		ptr->y_min = ptr->y_min - ptr->display_shift;
	if (keysym == XK_Down || keysym == XK_s)
		ptr->y_min = ptr->y_min + ptr->display_shift;
	if (keysym == XK_Left || keysym == XK_a)
		ptr->x_min = ptr->x_min - ptr->display_shift;
	if (keysym == XK_Right || keysym == XK_d)
		ptr->x_min = ptr->x_min + ptr->display_shift;
	ft_put_image_to_window(ptr);
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
