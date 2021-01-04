/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: coscialp <coscialp@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/14 10:19:08 by coscialp          #+#    #+#             */
/*   Updated: 2020/12/18 13:48:49 by coscialp         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "philo_three.h"

char	*ft_putnbr(int nb)
{
	static char	buf[12] = {0};
	short		i;

	i = 10;
	if (nb == 0)
		return ("0");
	while (nb != 0)
	{
		i--;
		buf[i] = nb % 10 + '0';
		nb /= 10;
	}
	return (buf + i);
}
