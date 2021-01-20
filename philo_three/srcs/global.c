/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   global.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: coscialp <coscialp@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/18 10:55:23 by coscialp          #+#    #+#             */
/*   Updated: 2021/01/20 11:06:47 by coscialp         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "philo_three.h"

char		*ft_strdup(const char *str)
{
	size_t		size;
	size_t		i;
	char		*dest;

	i = 0;
	size = ft_strlen(str);
	if (!(dest = (char*)ft_calloc(sizeof(char), size + 1)))
		return (NULL);
	ft_memcpy(dest, str, size);
	return (dest);
}

char		*ft_itoa(int n)
{
	static char	buf[12] = {0};
	int			i;
	int			neg;

	i = 10;
	if (n == -2147483648)
		return (ft_strdup("-2147483648"));
	neg = n < 0 ? -1 : 1;
	n = n < 0 ? -n : n;
	while (1)
	{
		buf[i--] = n % 10 + '0';
		n /= 10;
		if (n == 0)
			break ;
	}
	if (neg == -1)
		buf[i] = '-';
	return (neg == -1 ? ft_strdup(buf + i) : ft_strdup(buf + 1 + i));
}

void		destroy_sem(void)
{
	int			i;
	t_philosoph	*tmp;

	i = -1;
	while (++i < state()->rules.number_of_philo)
	{
		sem_close(state()->philosoph->sem_check);
		sem_close(state()->philosoph->sem_eat);
		tmp = state()->philosoph->right;
		free(state()->philosoph);
		state()->philosoph = tmp;
	}
	sem_close(state()->sem_write);
	sem_close(state()->forks);
}

sem_t		*create_sem(char *name, int id, int value)
{
	char				*number;
	static char			name_sem[16] = {0};

	number = ft_itoa(id + 1);
	ft_strcat(name_sem, name, 0);
	ft_strcat(name_sem, number, 9);
	sem_unlink(name_sem);
	free(number);
	return (sem_open(name_sem, O_CREAT, S_IRWXU, value));
}

int			ft_is_dead(t_philosoph *philo)
{
	static struct timeval now;

	gettimeofday(&now, NULL);
	if (get_timestamp(philo->last_meal, now) > state()->rules.time_to_die)
		return (1);
	return (0);
}
