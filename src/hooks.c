#include "fractol.h"

int     zoom_hook(int keysym, int x, int y, t_list *ptr)
{
    double tmp_x;
    double tmp_y;
    double center_x;
    double center_y;
     
    center_x = ptr->window_width / 2.0;
    center_y = ptr->window_height / 2.0;
    tmp_x = center_x / ptr->zoom_x + ptr->x_min;
    tmp_y = center_y / ptr->zoom_y + ptr->y_min;
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
    ptr->x_min = tmp_x - (center_x / ptr->zoom_x);
    ptr->y_min = tmp_y - (center_y / ptr->zoom_y);
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
