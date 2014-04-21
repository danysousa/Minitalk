/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsousa <dsousa@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/08 11:56:08 by dsousa            #+#    #+#             */
/*   Updated: 2014/02/09 20:46:26 by dsousa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <signal.h>
#include <unistd.h>
#include "libft.h"

void	binary(char a, int pid)
{
	int		i;
	char	octet[9];

	ft_memset(octet, '\0', 9);
	i = 7;
	while (i >= 0 && a)
	{
		octet[i] = (a % 2) + 30;
		a /= 2;
		i--;
	}
	while (i >= 0)
		octet[i--] = 30;
	i = 0;
	while (i < 8)
	{
		if (octet[i] == 31)
			kill(pid, SIGUSR2);
		if (octet[i] == 30)
			kill(pid, SIGUSR1);
		i++;
		usleep(20);
	}
}

int		check_pid(char *pid)
{
	int	i;

	i = 0;
	while (pid[i] && pid[i] >= 48 && pid[i] <= 57)
		i++;
	if (!pid[i])
		return (1);
	return (0);
}

void	handler(int sig)
{
	(void)sig;
	ft_putendl("\033[1;32mPong!\033[0;m");
}

int		main(int ac, char **av)
{
	int					i;
	int					smart_sleep;

	i = 0;
	signal(SIGUSR1, handler);
	if (ac == 3 && check_pid(av[1]))
	{
		if (!av[2][0])
		{
			ft_putendl_fd("error: empty string", 2);
			return (-1);
		}
		smart_sleep = ft_strlen(av[2]) * 0.003;
		while (av[2][i])
		{
			binary(av[2][i], ft_atoi(av[1]));
			usleep(smart_sleep);
			i++;
		}
		binary(4, ft_atoi(av[1]));
	}
	else
		ft_putendl_fd("usage : ./client [pid] [message]", 2);
	return (0);
}
