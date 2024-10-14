/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stage.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sde-carv <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/18 16:23:37 by sde-carv          #+#    #+#             */
/*   Updated: 2024/09/18 16:23:40 by sde-carv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

void	stage_thinking(t_philo *ph)
{
	if (ph->stop == 0)
		print_msg(ph, "is thinking", BLUE);
}

void	pick_up_fork(t_philo *ph)
{
	if (ph->stop == 0)
		print_msg(ph, "has taken a fork", YELLOW);
}

void	stage_eating(t_philo *ph)
{
	if (ph->stop == 1)
		return ;
	sem_wait(ph->forks);
	pick_up_fork(ph);
	sem_wait(ph->forks);
	pick_up_fork(ph);
	if (ph->stop == 0)
	{
		print_msg(ph, "is eating", LIME);
		usleep(ph->conter->time_eat * 1000);
		ph->time = current_time();
		++ph->eat;	
	}
	sem_post(ph->forks);
	sem_post(ph->forks);
}

void	stage_sleeping(t_philo *ph)
{
	if (ph->stop == 0)
	{
		print_msg(ph, "is sleeping", D_BLUE);
		usleep(ph->conter->time_sleep * 1000);		
	}
}

int	stage_deading(t_philo *ph)
{
	long long	time_elapsed;

	time_elapsed = current_time() - ph->time;
	if (time_elapsed >= ph->conter->time_die && ph->stop == 0)
	{
		print_msg(ph, "died", RED);
		return (0);
	}
	return (1);
}
