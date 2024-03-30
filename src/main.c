/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdameros <tdameros@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/29 22:35:32 by tdameros          #+#    #+#             */
/*   Updated: 2024/03/29 22:35:34 by tdameros         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>

#include "game.h"
#include "error.h"

static int	get_fd(int argc, char **argv);

int	main(int argc, char **argv)
{
	int		fd;
	t_game	game;

	fd = get_fd(argc, argv);
	if (fd == -1)
	{
		print_error(GENERIC_ERROR);
		return (1);
	}
	if (init_game(&game, fd) == -1)
	{
		print_error(GENERIC_ERROR);
		return (1);
	}
	printf("Start game\n");
	start_game(&game);
	return (0);
}

static int	get_fd(int argc, char **argv)
{
	int	fd;

	fd = STDIN_FILENO;
	if (argc >= 3)
		return (-1);
	if (argc == 2)
		fd = open(argv[1], O_RDONLY);
	if (fd == -1)
		return (-1);
	return (fd);
}
