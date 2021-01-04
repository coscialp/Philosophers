/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stris.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: coscialp <coscialp@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/10 12:27:54 by coscialp          #+#    #+#             */
/*   Updated: 2020/12/18 13:48:52 by coscialp         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "philo_three.h"

bool	ft_stris(char *str, bool (*f)(int))
{
	size_t	i;

	i = 0;
	while (str[i])
	{
		if (!(*f)(str[i]))
			return (1);
		i++;
	}
	return (0);
}
