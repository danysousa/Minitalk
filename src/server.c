/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsousa <dsousa@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/08 11:49:28 by dsousa            #+#    #+#             */
/*   Updated: 2014/02/09 20:18:40 by dsousa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <signal.h>
#include <unistd.h>
#include <stdlib.h>
#include "minitalk.h"
#include "libft.h"

static int		ft_pow(int nb, int power)
{
	int		save;

	save = nb;
	if (power == 0)
		return (1);
	while (power > 1)
	{
		nb = nb * save;
		power--;
	}
	return (nb);
}

static void		reverse_bin(char *octet, pid_t pid)
{
	static t_serv	*list;
	int				i;
	int				ascii;

	if (!list)
		list = (t_serv *)malloc(sizeof(t_serv));
	ascii = 0;
	i = 0;
	while (i < 8)
	{
		ascii = (octet[7 - i] == 49) ? (ascii + ft_pow(2, i)) : ascii;
		i++;
	}
	if (ascii == 4)
	{
		usleep(20);
		kill(pid, SIGUSR1);
		print_list(&list);
	}
	else
		add_elem((char)ascii, &list);
}

static void		count(int sig, siginfo_t *siginfo, void *context)
{
	static char			octet[9];
	static int			i = 0;

	if (i == 0)
		ft_memset(octet, '\0', 9);
	if (i <= 7)
	{
		octet[i] = (sig + 18);
		i++;
		if (i == 8)
			reverse_bin(octet, siginfo->si_pid);
	}
	else
	{
		i = 0;
		count(sig, siginfo, context);
	}
}

int				main(void)
{
	struct sigaction	act;

	act.sa_sigaction = &count;
	act.sa_flags = SA_SIGINFO;
	ft_putstr("\033[1;33mPID: \033[0;31m");
	ft_putnbr(getpid());
	ft_putstr("\033[0;m");
	sigaction(SIGUSR1, &act, NULL);
	sigaction(SIGUSR2, &act, NULL);
	write (1, "\n", 1);
	while (1)
		;
	return (0);
}
