/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: coscialp <coscialp@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/07 13:39:22 by coscialp          #+#    #+#             */
/*   Updated: 2020/12/10 12:24:38 by coscialp         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

static int	ft_isspace(int c)
{
	return ((9 <= c && c <= 13) || c == 32);
}

static int	ft_isdigit(int c)
{
	return (48 <= c && 57 >= c);
}

int			ft_atoi(const char *str)
{
	int i;
	int nb;
	int neg;

	i = 0;
	nb = 0;
	neg = 1;
	while (ft_isspace(str[i]))
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			neg = -1;
		i++;
	}
	while (ft_isdigit(str[i]))
	{
		nb *= 10;
		nb += str[i] - '0';
		i++;
	}
	return (nb * neg);
}
