/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsousa <dsousa@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/08 11:54:00 by dsousa            #+#    #+#             */
/*   Updated: 2014/02/09 16:16:58 by dsousa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINITALK_H
# define MINITALK_H

# include <sys/types.h>

typedef struct			s_serv
{
	char				data;
	pid_t				pid;
	struct s_serv		*next;
	struct s_serv		*start;
}						t_serv;

void		add_elem(char c, t_serv **list);
void		print_list(t_serv **list);

#endif /* MINITALK */
