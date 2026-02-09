/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbouquet <rbouquet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/01 12:09:11 by rbouquet          #+#    #+#             */
/*   Updated: 2024/09/05 10:18:23 by rbouquet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

static void	send_bits(int pid, int num, int bits_count)
{
	int	i;

	i = bits_count;
	while (i--)
	{
		if ((num >> i) & 1)
			kill(pid, SIGUSR2);
		else
			kill(pid, SIGUSR1);
		usleep(200);
	}
}

void	send_message(int pid, char *message)
{
	int	len;
	int	i;

	len = ft_strlen(message);
	send_bits(pid, len, 32);
	i = 0;
	while (message[i])
	{
		send_bits(pid, message[i], 8);
		i++;
	}
	send_bits(pid, 0, 8);
}

int	main(int argc, char **argv)
{
	int	pid;

	if (argc != 3)
	{
		ft_printf("ERROR, try ./client PID MESSAGE");
		return (-1);
	}
	pid = ft_atoi(argv[1]);
	if (!pid)
	{
		ft_printf("ERROR");
		return (-1);
	}
	send_message(pid, argv[2]);
	return (0);
}
