/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbouquet <rbouquet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/09 09:37:57 by rbouquet          #+#    #+#             */
/*   Updated: 2024/09/11 10:00:55 by rbouquet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

static int	convert_signal(int sig, int bits)
{
	if (sig == SIGUSR1)
		bits = (bits << 1) | 0;
	else if (sig == SIGUSR2)
		bits = (bits << 1) | 1;
	return (bits);
}

static char	*ft_malloc_len(int bits)
{
	char	*message;

	message = malloc((bits + 1) * sizeof(char));
	if (!message)
		return (NULL);
	return (message);
}

static void	handle_signal(int sig)
{
	static int	bits = 0;
	static int	bit_count = 0;
	static char	*msg = NULL;
	static int	i = 0;

	bits = convert_signal(sig, bits);
	bit_count++;
	if (!msg && bit_count == 32)
	{
		msg = ft_malloc_len(bits);
		bits = 0;
	}
	if (msg && (bit_count == 40 || bit_count == 8))
	{
		msg[i++] = bits;
		if (bits == 0)
		{
			ft_printf("%s\n", msg);
			free(msg);
			msg = NULL;
			i = 0;
		}
		bits = 0;
		bit_count = 0;
	}
}

int	main(int argc, char **argv)
{
	int	pid;

	(void)**argv;
	if (argc != 1)
		ft_printf("Error, try ./server");
	else if (argv[2] == NULL)
	{
		ft_printf("Error, nothing to send");
		return (-1);
	}
	else
	{
		pid = getpid();
		ft_printf("PID SERVER : %d\n", pid);
		ft_printf("Waiting...\n");
		signal(SIGUSR1, handle_signal);
		signal(SIGUSR2, handle_signal);
		while (1)
			usleep(200);
	}
}
