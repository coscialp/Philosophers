/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: coscialp <coscialp@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/10 12:08:50 by coscialp          #+#    #+#             */
/*   Updated: 2021/01/19 15:06:17 by coscialp         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "philo_three.h"

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
		if (philo->eating == state()->rules.number_of_must_eat)
			sem_post(philo->sem_eat);
		if (state()->end)
			break ;
		sem_wait(philo->sem_check);
		if (ft_is_dead(philo))
		{
			philo->is_dead = 0;
			display(philo, "died");
			sem_post(philo->sem_check);
			kill(philo->pid, SIGINT);
			return (NULL);
		}
		sem_post(philo->sem_check);
		usleep(3000);
	}
	kill(philo->pid, SIGINT);
	return (NULL);
}

void		th_routine(void *philo_ptr)
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
	exit(0);
}

void		*th_eating(void *philo_ptr)
{
	int	i;

	(void)philo_ptr;
	i = -1;
	sem_wait(state()->philosoph->sem_eat);
	while (++i < state()->rules.number_of_philo)
	{
		sem_wait(state()->philosoph->sem_eat);
		state()->philosoph = state()->philosoph->right;
	}
	i = -1;
	while (++i < state()->rules.number_of_philo)
	{
		kill(state()->philosoph->pid, SIGINT);
		state()->philosoph = state()->philosoph->right;
	}
	return (NULL);
}

int			main(int ac, char **av)
{
	static int		i = -1;
	static int		status = 0;
	pthread_t		end_game;

	if (init_state(ac, av))
		return (1);
	if (state()->rules.number_of_must_eat == 0)
		return (0);
	pthread_create(&end_game, NULL, th_eating, NULL);
	while (++i < state()->rules.number_of_philo)
	{
		state()->philosoph->pid = fork();
		if (!state()->philosoph->pid)
		{
			th_routine(state()->philosoph);
			exit(0);
		}
		usleep(1000);
		state()->philosoph = state()->philosoph->right;
	}
	if (waitpid(-1, &status, 0) < 0)
		exit(0);
	pthread_join(end_game, NULL);
	destroy_sem();
	return (0);
}
