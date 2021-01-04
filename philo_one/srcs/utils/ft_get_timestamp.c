/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_timestamp.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: coscialp <coscialp@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/18 11:55:58 by coscialp          #+#    #+#             */
/*   Updated: 2020/12/18 11:56:12 by coscialp         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "philo_one.h"

int		get_timestamp(struct timeval s, struct timeval t)
{
	return (1000 * (t.tv_sec - s.tv_sec) + (t.tv_usec - s.tv_usec) * 0.001);
}
