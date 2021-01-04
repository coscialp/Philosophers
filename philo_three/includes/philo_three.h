/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_three.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: coscialp <coscialp@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/10 09:40:47 by coscialp          #+#    #+#             */
/*   Updated: 2021/01/04 10:59:23 by coscialp         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_THREE_H
# define PHILO_THREE_H

# include <stdlib.h>
# include <unistd.h>
# include <pthread.h>
# include <sys/time.h>
# include <string.h>
# include <stdio.h>
# include <stdbool.h>
# include <semaphore.h>
# include <sys/types.h>
# include <signal.h>

typedef struct s_philosoph	t_philosoph;
struct			s_philosoph
{
	bool			is_dead;
	short			id;
	short			eating;
	pthread_t		brain;
	pthread_t		eat;
	sem_t			*sem_eat;
	sem_t			*sem_check;
	struct timeval	last_meal;
	t_philosoph		*right;
	t_philosoph		*left;
	pid_t			pid;
};

typedef struct s_rules	t_rules;
struct			s_rules
{
	short	number_of_philo;
	short	time_to_die;
	short	time_to_eat;
	short	time_to_sleep;
	short	number_of_must_eat;
};

typedef struct	s_state
{
	sem_t				*forks;
	t_philosoph			*philosoph;
	sem_t				*sem_write;
	t_rules				rules;
	struct timeval		begin_time;
	time_t				time;
	bool				end;
}				t_state;

int				ft_write(int fd, char *buf, size_t size);
int				ft_atoi(const char *str);
size_t			ft_strlen(const char *s);
long int		get_time(void);
char			*ft_putnbr(int nb);
bool			ft_stris(char *str, bool (*f)(int));
bool			ft_isdigit(int c);
t_state			*state(void);
int				init_fork(int i);
int				init_philosoph(int i);
int				init_state(int ac, char **av);
int				ft_error(char *msg);
int				ft_standby(int time);
void			display(t_philosoph *philo, char *message);
int				get_timestamp(struct timeval s, struct timeval t);
void			*th_brain(void *philo_ptr);
void			th_routine(void *philo_ptr);
void			*th_eating(void *ptr);
void			ft_sleep(t_philosoph *philo);
int				ft_eat(t_philosoph *philo);
void			ft_think(t_philosoph *philo);
t_state			*state(void);
int				ft_is_dead(t_philosoph *philo);
void			destroy_sem(void);
void			*ft_calloc(size_t size, size_t count);
short			ft_strcat(char *dest, const char *src, short i);

#endif
