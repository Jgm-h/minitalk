/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmorcom- <jmorcom-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/15 17:31:08 by jmorcom-          #+#    #+#             */
/*   Updated: 2023/07/15 17:47:34 by jmorcom-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/minitalk.h"
#include "./libft/includes/libft.h"
#include "./libft/includes/ft_printf.h"

void	convert(char c, int pid)
{
	int	i;
	int	bit;

	bit = 0x01;
	i = 0;
	while (i != 8)
	{
		if (bit & c)
			kill(pid, SIGUSR1);
		else
			kill(pid, SIGUSR2);
		bit = bit << 1;
		usleep(100);
		i++;
	}
}

int	check_arg(char *arg)
{
	int	i;

	i = 0;
	while (arg[i])
	{
		if (arg[i] < '0' || arg[i] > '9')
			return (1);
		i++;
	}
	return (0);
}

int	main(int argc, char **argv)
{
	int	pid;
	int	i;

	i = 0;
	if (argc != 3 || check_arg(argv[1]))
	{
		ft_printf("%s", "Invalid arguments!\n");
		return (1);
	}
	pid = ft_atoi(argv[1]);
	while (argv[2][i])
		convert(argv[2][i++], pid);
	return (0);
}
