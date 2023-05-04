/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nasamadi <nasamadi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/12 11:54:09 by nasamadi          #+#    #+#             */
/*   Updated: 2023/05/04 18:57:20 by nasamadi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <stdlib.h>
# include <stdio.h>
# include <pthread.h>
# include <semaphore.h>
# include <signal.h>
# include <unistd.h>
# include <sys/time.h>
# include <sys/wait.h>
# include <fcntl.h>

typedef struct s_philo
{
	int				id;
	int				eat_cnt;
	long long		last_eat_time;
	pid_t			pid;
	struct s_info	*info;
}					t_philo;

typedef struct s_info
{
	int				num_philo;
	int				time_to_die;
	int				time_to_eat;
	int				time_to_sleep;
	int				num_must_eat;
	int				finished_meals;
	long long		start_time;
	t_philo			*philos;
	sem_t			*forks;
	sem_t			*print_sem;
	sem_t			*eat_sem;
	sem_t			*die_sem;
	sem_t			*meals_count_sem;
}					t_info;

int			print_error(char *message);
int			ft_atoi(const char *nptr);
long long	get_time(void);
void		print_status(t_philo *philo, const char *message);
void		ft_sleep(long long ms);

int			init_info(t_info *info, int ac, char **av);
int			init_philos(t_info *info);
void		fork_philos(t_info *info);

void		*check_dead(void *arg);
//int 		random_sleep(int max);
int 		check_all_meals_finished(t_info *info);
void		philo_start(t_philo *philo);

#endif
