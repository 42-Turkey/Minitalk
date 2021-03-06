/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mboy <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/26 10:00:36 by mboy              #+#    #+#             */
/*   Updated: 2021/08/26 10:05:44 by mboy             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Include/minitalk.h"

t_mini	*client_initiate(void)
{
	t_mini	*talk;

	talk = malloc(sizeof(t_mini));
	if (!talk)
	{
		ft_putstr("[ERROR]: Out of memory! malloc() failed.\n");
		exit(EXIT_FAILURE);
	}
	talk->pid_server = 0;
	talk->pid_client = 0;
	return (talk);
}

void	client_send(t_mini *talk, char *mess)
{
	int		idx;
	int		bit;
	int		signal;

	idx = -1;
	while (++idx <= ft_strlen(mess))
	{
		bit = -1;
		signal = 0;
		while (++bit < 7)
		{
			if ((mess[idx] >> bit) & 1)
				signal = SIGUSR2;
			else
				signal = SIGUSR1;
			kill(talk->pid_server, signal);
			usleep(100);
		}
	}
	return ;
}

int	main(int ac, char *av[])
{
	t_mini	*talk;

	talk = NULL;
	if (ac != 3)
	{
		ft_putstr("[ERROR]: Use ./server with 3 arguments only.\n");
		exit(EXIT_FAILURE);
	}
	else
	{
		talk = client_initiate();
		talk->pid_server = ft_atoi(av[1]);
		if (talk->pid_server <= 0)
		{
			ft_putstr("[ERROR]: PID is egal or less than to zero.\n");
			free(talk);
			talk = NULL;
			exit(EXIT_FAILURE);
		}
		client_send(talk, av[2]);
	}
	free(talk);
	talk = NULL;
	return (0);
}
