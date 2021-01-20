/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   action.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: coscialp <coscialp@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/18 10:58:35 by coscialp          #+#    #+#             */
/*   Updated: 2021/01/20 11:03:46 by coscialp         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "philo_one.h"

void	ft_sleep(t_philosoph *philo)
{
	display(philo, "is sleeping");
	usleep(state()->rules.time_to_sleep * 1000);
}

int		ft_eat(t_philosoph *philo)
{
	if (state()->rules.number_of_philo == 1)
	{
		pthread_mutex_lock(&philo->r_fork->mutex);
		display(philo, "has taken a fork");
		usleep(state()->rules.time_to_die * 1000);
		return (1);
	}
	pthread_mutex_lock(&philo->r_fork->mutex);
	pthread_mutex_lock(&philo->l_fork->mutex);
	display(philo, "has taken a fork");
	display(philo, "has taken a fork");
	pthread_mutex_lock(&philo->mutex_check);
	display(philo, "is eating");
	gettimeofday(&philo->last_meal, NULL);
	philo->eating++;
	pthread_mutex_unlock(&philo->mutex_check);
	usleep(state()->rules.time_to_eat * 1000);
	pthread_mutex_unlock(&philo->r_fork->mutex);
	pthread_mutex_unlock(&philo->l_fork->mutex);
	return (0);
}

void	ft_think(t_philosoph *philo)
{
	display(philo, "is thinking");
}
