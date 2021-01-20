/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   global.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: coscialp <coscialp@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/18 10:55:23 by coscialp          #+#    #+#             */
/*   Updated: 2021/01/20 09:23:54 by coscialp         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "philo_two.h"

void		destroy_sem(void)
{
	int			i;
	t_philosoph	*tmp;

	i = -1;
	while (++i < state()->rules.number_of_philo)
	{
		sem_close(state()->philosoph->sem_check);
		tmp = state()->philosoph->right;
		free(state()->philosoph);
		state()->philosoph = tmp;
	}
	sem_close(state()->sem_write);
	sem_close(state()->forks);
}

int			ft_is_dead(t_philosoph *philo)
{
	static struct timeval now;

	gettimeofday(&now, NULL);
	if (get_timestamp(philo->last_meal, now) > state()->rules.time_to_die)
		return (1);
	return (0);
}
