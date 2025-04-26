/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tafanasi <tafanasi@student.42warsaw.pl>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/26 22:26:09 by tafanasi          #+#    #+#             */
/*   Updated: 2025/04/27 00:54:41 by tafanasi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	main(int argc, char **argv)
{
	char	**map;
	int		i;

	if (argc != 2)
	{
		handle_error("Usage: ./so_long <map_file.ber>", 1);
		return (1);
	}
	printf("Map file: %s\n", argv[1]);
	map = get_map(argv[1]);
	i = 0;
	while (map[i] != NULL)
	{
		printf("Line %d: %s\n", i, map[i]);
		i++;
	}
	printf("\nMap loaded successfully.\n");
	// printf("\n");
	// void *mlx = mlx_init();
	// void *win = mlx_new_window(mlx, 640, 480, "so_long v0");
	// mlx_hook(win, 17, 0, handle_exit, NULL); // 17 = X11 DestroyNotify
	// mlx_loop(mlx);
	free_2d(map);
	return (0);
}
