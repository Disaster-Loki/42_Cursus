/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sde-carv <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/15 10:34:18 by sde-carv          #+#    #+#             */
/*   Updated: 2024/09/15 10:34:47 by sde-carv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	ft_atoi(char *str)
{
	int	res;

	res = 0;
	while (*str >= 9 && *str <= 13)
		str++;
	if (*str == '+' || *str == '-')
	{
		if (*str == '-')
			return (-1);
	}
	while (*str >= '0' && *str <= '9')
		res = (res * 10) + (*str++ - '0');
	return (res);
}

long long	current_time(void)
{
	struct timeval	time;

	gettimeofday(&time, NULL);
	return ((time.tv_sec * 1000) + (time.tv_usec / 1000));
}

void	strac_usleep(t_philo *ph, int lim)
{
	int	i;

	i = -1;
	while (++i < (lim / 10))
	{
		if (!stage_deading(ph))
			break ;
		usleep(10000);
	}
}

int	check_args(int av, char **args)
{
	int	i;
	int	j;

	i = 0;
	while (++i < av)
	{
		j = 0;
		if (args[i][j] == '+' || args[i][j] == '-')
			j++;
		while (args[i][j])
		{
			if (args[i][j] < '0' || args[i][j] > '9')
				return (0);
			j++;
		}
	}
	return (1);
}

void	print_msg(t_philo *ph, char *str, char *color)
{
	pthread_mutex_lock(&ph->conter->msg);
	if (ph->conter->dead == 0)
	{
		printf("[%lli] ", (current_time() - ph->start));
		printf("%d %s%s%s", ph->id, color, str, RESET);
	}
	pthread_mutex_unlock(&ph->conter->msg);
}
