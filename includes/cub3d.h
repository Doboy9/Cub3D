/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kprigent <kprigent@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/20 22:56:31 by kprigent          #+#    #+#             */
/*   Updated: 2024/05/15 11:54:21 by kprigent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include "../mlx/mlx.h"
# include "../mlx/mlx_int.h"
# include "libft.h"
# include <stdint.h>
# include <math.h>

# define WIDTH 1920
# define HEIGHT 1080
# define EDGE 20
# define FOV 60
# define PI 3.14159265

# define NORTH 0
# define SOUTH 1
# define EAST 2
# define WEST 3

# define RESET   "\x1B[0m"
# define RED     "\x1B[31m"
# define GREEN   "\x1B[32m"
# define YELLOW  "\x1B[33m"
# define BLUE    "\x1B[34m"
# define MAGENTA "\x1B[35m"
# define CYAN    "\x1B[36m"
# define WHITE   "\x1B[37m"

# define R   "\x1B[31m"
# define G   "\x1B[32m"
# define Y   "\x1B[33m"
# define RESET "\x1B[0m"


typedef struct s_vars {
    void    *mlx;
    void    *win;

////////////IMG MENUE HANDLE////////////////    

    void    *play_click;
    void    *play_selec;
	int		play_button_x;
	int		play_button_y;
    int        solong_x;
    int        solong_y;
    int        title_x;
    int        title_y;

///////////PARISNG HANDLE////////////////////

    char **texture;
	int **texture_N;
	int **texture_S;
	int **texture_E;
	int **texture_W;
	double	pos_x;
	double	pos_y;
    int        line_map;
    int        no;
    int        so;
    int        we;
    int        ea;
    int        f;
    int        c;

////////////////////
    void    *title;
    void    *you_win;
    char    **map;
	int		celing_color;
	int		floor_color;
    char    *line;
    int        width;
    int        height;
    int        victory;
    int        one;
    int        p;
    int        e;
    int        wrong;
    int        start;
    int        button_clicked;
    int        nb_of_collectible;
    int        l;
    int        ll;
    int        p_y;
    int        p_x;
    int        map_x;
    int        map_y;
///////////////////////////
    float        play_x;
    float        play_y;
	int				bits_per_pixel;
	int				line_length;
	int				endian;
	void			*img;
	void			*addr;
	int				x_map;
	int				y_map;
	double		rotate_x1;
	double		rotate_y1;
	double			x0;
	double			x1;
	double			y0;
	double			y1;
	double			c2;
	float			ray_x0;
	float			ray_y0;
	float			ray_y;
	float			ray_x;
	float			ray_x1;
	float			ray_y1;
	int				x;
	int				y;
	double			angle;
	double			vision_angle;
	double			dx;
	double			dy;
	double			incx;
	double			incy;
	double			rotate;
	int			length_x;
	int			length_y;
	int			zoom;
	int			shift_x;
	int			shift_y;
	int			bool;
	double long	cos;
	double long	sin;
	uint32_t	color;
	uint32_t	color1;

}	t_vars;

typedef struct s_point
{
	int	x;
	int	y;
	int	pe;
	int	c;

}	t_point;





void	ft_draw_line_x(t_vars *vars);
void	ft_draw_line_y(t_vars *vars);
void	ft_draw_horizontal(t_vars *vars);
void	ft_draw_vertical(t_vars *vars);
int		ft_draw_line_bresenham(t_vars *vars);
void	draw_rays(t_vars *vars);
void	redraw_grid_wo_p(t_vars *vars);
void	rotation_matrix(t_vars *vars);
double	ft_absolute_number(double value);
double	ft_sign(double value);


////// EXEC //////////////////
int		exec(t_vars *vars);
void	draw_player(t_vars *vars);
void	draw_floor_tile(t_vars *vars);
void	draw_wall_tile(t_vars *vars);
void	my_mlx_pixel_put(t_vars *vars, int x, int y, int color);
void	draw_rays(t_vars *vars);
int		check_walls2(t_vars *vars);
int		check_walls(t_vars *vars);
void	draw_grid(t_vars *vars);
void	redraw_player(t_vars *vars);
void	redraw_grid(t_vars *vars);
int		check_walls_ray(t_vars *vars);
int		check_walls_path(t_vars *vars);

////// MENU AND PARSING //////

int        count_c(t_vars *vars);
void    free_map(t_vars *vars);
int        is_square(t_vars *vars);
void    go_in_game(t_vars *vars);
void    event_game(t_vars *vars);
int        mouse_click(int button, int x, int y, t_vars *vars);
int        mouse_over(int x, int y, t_vars *vars);
int        check_error(char *map, t_vars *vars);
void    find_p(t_vars *vars);
void    find_a_way(t_vars *vars, int x, int y);
int        nb_line(int fd);
int        check_nsew(t_vars *vars);
void    free_vars(t_vars *vars);
void    free_modified_map(t_vars *vars);
void    destroy_image(t_vars *vars);
int        close_with_x(t_vars *vars);
int        close_with_esc(int keycode, t_vars *vars);
int        parsing(t_vars *vars, char **argv, int argc);
int        check_map(char *map, t_vars *vars);
int        check_param(char *map, t_vars *vars);
int   	  check_param_valid(t_vars *vars);
char     *remove_space(char *tab);
void     free_exit(t_vars *vars);
int check_param(char *map, t_vars *vars);

////// GAME /////

#endif
