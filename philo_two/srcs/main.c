/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: coscialp <coscialp@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/10 12:08:50 by coscialp          #+#    #+#             */
/*   Updated: 2021/01/21 09:08:03 by coscialp         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "philo_two.h"

t_state		*state(void)
{
	static t_state s = {0};

	return (&s);
}

void		*th_brain(void *philo_ptr)
{
	t_philosoph	*philo;

	philo = (t_philosoph *)philo_ptr;
	while (philo->is_dead)
	{
		if (state()->end)
			break ;
		sem_wait(philo->sem_check);
		if (ft_is_dead(philo))
		{
			philo->is_dead = 0;
			display(philo, "died");
			sem_post(philo->sem_check);
			return (NULL);
		}
		sem_post(philo->sem_check);
		usleep(3000);
	}
	return (NULL);
}

void		*th_routine(void *philo_ptr)
{
	t_philosoph	*philo;

	philo = (t_philosoph *)philo_ptr;
	philo->last_meal = state()->begin_time;
	pthread_create(&philo->brain, NULL, th_brain, philo);
	while (philo->is_dead && !state()->end)
	{
		if (ft_eat(philo))
			break ;
		ft_sleep(philo);
		ft_think(philo);
	}
	pthread_join(philo->brain, NULL);
	return (NULL);
}

int			main(int ac, char **av)
{
	static int	i = -1;
	pthread_t	pid;

	if (init_state(ac, av))
		return (1);
	gettimeofday(&state()->begin_time, NULL);
	state()->time = get_time();
	if (state()->rules.number_of_must_eat == 0)
		return (0);
	while (++i < state()->rules.number_of_philo)
	{
		pthread_create(&pid, NULL, th_routine, state()->philosoph);
		usleep(1000);
		state()->philosoph = state()->philosoph->right;
	}
	pthread_join(pid, NULL);
	destroy_sem();
	return (0);
}
