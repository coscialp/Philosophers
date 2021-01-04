/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: coscialp <coscialp@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/14 10:17:05 by coscialp          #+#    #+#             */
/*   Updated: 2021/01/04 10:59:04 by coscialp         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "philo_three.h"

short	ft_strcat(char *dest, const char *src, short i)
{
	int j;

	j = 0;
	while (src[j])
		dest[i++] = src[j++];
	dest[i] = '\0';
	return (i);
}

void			display(t_philosoph *philo, char *message)
{
	char	str[100];
	short	i;

	memset(str, 0, 100);
	sem_wait(state()->sem_write);
	i = ft_strcat(str, ft_putnbr(get_time() - state()->time), 0);
	i = ft_strcat(str, " ", i);
	i = ft_strcat(str, ft_putnbr(philo->id), i);
	i = ft_strcat(str, " ", i);
	i = ft_strcat(str, message, i);
	i = ft_strcat(str, "\n", i);
	if (state()->end == 1)
	{
		sem_post(state()->sem_write);
		return ;
	}
	ft_write(1, str, i);
	if (!strcmp(message, "died"))
		state()->end = 1;
	else
		sem_post(state()->sem_write);
}
