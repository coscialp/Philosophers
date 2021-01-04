/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   global.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: coscialp <coscialp@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/18 10:55:23 by coscialp          #+#    #+#             */
/*   Updated: 2020/12/18 11:04:59 by coscialp         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "philo_one.h"

void		destroy_mutex(void)
{
	int		i;

	i = -1;
	while (++i < state()->rules.number_of_philo)
	{
		pthread_mutex_destroy(&state()->philosoph->l_fork->mutex);
		pthread_mutex_destroy(&state()->philosoph->r_fork->mutex);
		pthread_mutex_destroy(&state()->philosoph->mutex_check);
		pthread_mutex_destroy(&state()->philosoph->mutex_eat);
		state()->philosoph = state()->philosoph->right;
	}
	pthread_mutex_destroy(&state()->mutex_write);
	pthread_mutex_destroy(&state()->mutex_state);
	pthread_mutex_destroy(&state()->mutex_fork);
}

int			ft_is_dead(t_philosoph *philo)
{
	static struct timeval now;

	gettimeofday(&now, NULL);
	if (get_timestamp(philo->last_meal, now) > state()->rules.time_to_die)
		return (1);
	return (0);
}
