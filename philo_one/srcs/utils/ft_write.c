/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_write.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: coscialp <coscialp@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/14 10:21:58 by coscialp          #+#    #+#             */
/*   Updated: 2020/12/10 12:13:17 by coscialp         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "philo_one.h"

int		ft_write(int fd, char *buf, size_t size)
{
	int ret;

	ret = write(fd, buf, size);
	return (ret);
}
