/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_serv.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsousa <dsousa@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/09 12:20:53 by dsousa            #+#    #+#             */
/*   Updated: 2014/02/09 20:13:26 by dsousa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <unistd.h>
#include "libft.h"
#include "minitalk.h"

void		add_elem(char c, t_serv **list)
{
	t_serv		*new;

	if (!((*list)->data))
	{
		(*list)->data = c;
		(*list)->start = *list;
		(*list)->next = NULL;
	}
	else
	{
		new = (t_serv *)malloc(sizeof(t_serv));
		new->start = *list;
		new->data = c;
		new->next = NULL;
		while ((*list)->next)
		{
			(*list) = (*list)->next;
		}
		(*list)->next = new;
		*list = (*list)->start;
	}
}

void		print_list(t_serv **list)
{
	t_serv		*tmp;

	while ((*list)->next)
	{
		write(1, &(*list)->data, 1);
		*list = (*list)->next;
	}
	write(1, &(*list)->data, 1);
	write(1, "\n", 1);
	*list = (*list)->start;
	while ((*list))
	{
		tmp = (*list)->next;
		(*list)->data = 0;
		(*list)->start = NULL;
		(*list)->next = NULL;
		free(*list);
		*list = tmp;
	}
	free(tmp);
}
