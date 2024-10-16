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

#include "philo_bonus.h"

int	ft_atoi(char *str)
{
	int	sig;
	int	res;

	sig = 1;
	res = 0;
	while (*str >= 9 && *str <= 13)
		str++;
	if (*str == '+' || *str == '-')
	{
		if (*str == '-')
			sig = -1;
		str++;
	}
	while (*str >= '0' && *str <= '9')
		res = (res * 10) + (*str++ - '0');
	return (res * sig);
}

long	current_time(void)
{
	struct timeval	time;

	gettimeofday(&time, NULL);
	return ((time.tv_sec * 1000) + (time.tv_usec / 1000));
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

int	ft_strcmp(const char *s1, const char *s2)
{
	while (*s1 && *s1 == *s2)
	{
		s1++;
		s2++;
	}
	return (*s1 - *s2);
}

void	print_msg(t_philo *ph, char *str, char *color)
{
	if (ph->stop == 1)
		return ;
	sem_wait(ph->conter->msg);
	printf("[%ld] ", (current_time() - ph->start));
	printf("%d %s%s%s\n", ph->id, color, str, RESET);
	if (ft_strcmp(str, "died") != 0)
		sem_post(ph->conter->msg);
}
