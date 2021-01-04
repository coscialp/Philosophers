/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: coscialp <coscialp@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/11 14:31:42 by coscialp          #+#    #+#             */
/*   Updated: 2020/12/18 12:22:58 by coscialp         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "philo_two.h"

int		init_philosoph(int i)
{
	static t_philosoph	*left = NULL;
	static t_philosoph	*top = NULL;

	if (!(state()->philosoph = malloc(sizeof(t_philosoph))))
		return (1);
	state()->philosoph->left = left;
	if (left)
		state()->philosoph->left->right = state()->philosoph;
	state()->philosoph->id = i + 1;
	state()->philosoph->is_dead = 1;
	state()->philosoph->eating = 0;
	sem_unlink("sem_check");
	state()->philosoph->sem_check = sem_open("sem_check", O_CREAT, S_IRWXU, 1);
	left = state()->philosoph;
	if (i == 0)
		top = state()->philosoph;
	if (i == state()->rules.number_of_philo - 1)
		state()->philosoph->right = top;
	return (0);
}

int		init_rules(int ac, char **av)
{
	int i;

	if (ac <= 4 || ac >= 7)
		return (ft_error("Invalid number of arguments\n"));
	i = 0;
	while (++i < (ac == 6 ? 6 : 5))
		if (ft_stris(av[i], ft_isdigit))
			return (ft_error("Arguments must be composed by digit\n"));
	if ((state()->rules.number_of_philo = ft_atoi(av[1])) <= 0)
		return (ft_error("Number of philosoph must be positive\n"));
	if ((state()->rules.time_to_die = ft_atoi(av[2])) <= 0)
		return (ft_error("Rule must be positive\n"));
	if ((state()->rules.time_to_eat = ft_atoi(av[3])) <= 0)
		return (ft_error("Rule must be positive\n"));
	if ((state()->rules.time_to_sleep = ft_atoi(av[4])) <= 0)
		return (ft_error("Rule must be positive\n"));
	state()->rules.number_of_must_eat = (ac == 6) ? ft_atoi(av[5]) : -1;
	sem_unlink("sem_write");
	state()->sem_write = sem_open("sem_write", O_CREAT, S_IRWXU, 1);
	sem_unlink("sem_forks");
	state()->forks = sem_open("sem_forks", O_CREAT, S_IRWXU, state()->rules.number_of_philo);
	return (0);
}

int		init_state(int ac, char **av)
{
	int			i;

	if (init_rules(ac, av))
		return (1);
	i = -1;
	while (++i < state()->rules.number_of_philo)
	{
		if (init_philosoph(i))
			return (ft_error("Allocation failed\n"));
	}
	state()->philosoph = state()->philosoph->right;
	return (0);
}
