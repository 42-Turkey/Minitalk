/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mboy <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/26 09:59:02 by mboy              #+#    #+#             */
/*   Updated: 2021/08/26 10:00:23 by mboy             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINITALK_H
# define MINITALK_H
# include <unistd.h>
# include <stdlib.h>
# include <sys/types.h>
# include <signal.h>
# include <stdio.h>

typedef struct s_mini
{
	int		pid_server;
	int		pid_client;
}				t_mini;

t_mini	*client_initiate(void);
void	client_send(t_mini *talk, char *mess);
t_mini	*server_initiate(void);
void	server_receive(int binary);
int		ft_strlen(char *str);
void	ft_putstr(char *str);
void	ft_putnbr(int n);
int		ft_atoi(const char *str);

#endif
