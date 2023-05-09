/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nasamadi <nasamadi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/12 11:53:11 by nasamadi          #+#    #+#             */
/*   Updated: 2023/05/05 11:16:16 by nasamadi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <stdlib.h>
# include <stdio.h>
# include <pthread.h>
# include <unistd.h>
# include <sys/time.h>
# include <time.h>
# include "philo.h"

/******************************************************************************\
 * ERROR MSG
\******************************************************************************/

# define ERROR_ARG "ERROR: incorrect number of arguments.\n \
Usage: ./philo num_philo time_to_die time_to_eat time_to_sleep [num_must_eat]\n"

# define INVALID_ARG "ERROR: invalid argument values. \
All argument values must be positive integers.\n"

# define PHILO_MALLOC_FAIL "ERROR: init_philos memory allocation failure.\n"

# define MUTEX_INIT_FAIL "ERROR: mutex initialization failure.\n"

# define PRINT_MUTEX_INIT_FAIL "ERROR: print mutex initialization failure.\n"

# define EAT_MUTEX_INIT_FAIL "ERROR: eat mutex initialization failure.\n"

# define FINISH_MUTEX_INIT_FAIL "ERROR: finish mutex initialization failure.\n"

# define THREAD_CREAT_FAIL "ERROR: thread creation failure.\n"

/******************************************************************************\
 * STRUCTURES
\******************************************************************************/

typedef struct s_philo
{
	int				id;
	int				eat_cnt;
	int				left_fork;
	int				right_fork;
	long long		last_eat_time;
	struct s_info	*info;
	pthread_t		thread;
	pthread_t		monitor_thread;
}				t_philo;

typedef struct s_info
{
	int				num_philo;
	int				time_to_die;
	int				time_to_eat;
	int				time_to_sleep;
	int				num_must_eat;
	int				num_full_philo;
	int				finish;
	int				num_args;
	long long		start_time;
	t_philo			*philos;
	pthread_mutex_t	*forks;
	pthread_mutex_t	print_mutex;
	pthread_mutex_t	eat_mutex;
	pthread_mutex_t	finish_mutex;
}				t_info;

/******************************************************************************\
 * CHECK
\******************************************************************************/
int			check_dead(t_philo *philo);
int			check_finish(t_philo *philo, int yes);
void		one_philosopher_case(t_philo *philo);

/******************************************************************************\
 * FREE
\******************************************************************************/
int			free_info(t_info *info);
int			free_destroy(t_info *info);
void		join_free_destroy(t_info *info);
void		destroy(t_info *info);

/******************************************************************************\
 * INIT & PHILO
\******************************************************************************/
int			init_info(t_info *info, int ac, char **av);
int			init_philos(t_info *info);
int			init_mutex(t_info *info);
int			create_philos(t_info *info);
void		acquire_forks(t_philo *philo);
void		release_forks(t_philo *philo);
void		eating(t_philo *philo);
void		main_loop(t_philo *philo);
void		*philo_start(void *arg);

/******************************************************************************\
 * UTILS
\******************************************************************************/
int			print_error(char *message);
int			ft_atoi(const char *nptr);
long long	get_time(void);
int			print_status(t_philo *philo, const char *message);
void		ft_sleep(t_philo *philo, long long ms);

#endif
