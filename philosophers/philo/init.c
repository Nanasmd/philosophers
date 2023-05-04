/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nasamadi <nasamadi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/12 11:52:38 by nasamadi          #+#    #+#             */
/*   Updated: 2023/05/04 13:09:05 by nasamadi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	init_info(t_info *info, int ac, char **av)
{
	int		i;

	i = 0;
	if (ac < 5 || ac > 6)
		return (print_error("Error: incorrect number of arguments. Usage: ./philo num_philo time_to_die time_to_eat time_to_sleep [num_must_eat]\n"));
	info->num_philo = ft_atoi(av[1]);
	info->time_to_die = ft_atoi(av[2]);
	info->time_to_eat = ft_atoi(av[3]);
	info->time_to_sleep = ft_atoi(av[4]);
	info->num_args = ac;
	info->start_time = get_time();
	if (info->num_philo < 1 || info->time_to_die < 1 || \
			info->time_to_eat < 1 || info->time_to_sleep < 1)
		return (print_error("Error: invalid argument values. All argument values must be positive integers.\n"));
	if (ac == 6)
	{
		info->num_must_eat = ft_atoi(av[5]);
		if (info->num_must_eat < 1)
			return (print_error("Error: invalid argument values. All argument values must be positive integers.\n"));
	}
	else
		info->num_must_eat = -1;
	info->finish = 0;
	return (0);
}

/*int	init_philos(t_info *info)
{
	int	i;

	i = -1;
	info->philos = malloc(sizeof(t_philo) * info->num_philo);
	if (!info->philos)
		return (print_error("Error: init_philos memory allocation failure.\n"));
	info->forks = malloc(sizeof(pthread_mutex_t) * info->num_philo);
	if (!info->forks)
	{
		free(info->philos);
		return (print_error("Error: init_philos memory allocation failure.\n"));
	}
	info->start_time = get_time();
	while (++i < info->num_philo)
	{
		info->philos[i].id = i + 1;
		info->philos[i].left_fork = i;
		info->philos[i].right_fork = (i + 1) % info->num_philo;
		info->philos[i].eat_cnt = 0;
		info->philos[i].last_eat_time = info->start_time;
		info->philos[i].info = info;
	}
	return (0);
}*/

void swap(int *a, int *b)
{
    int tmp = *a;
    *a = *b;
    *b = tmp;
}

int init_philos(t_info *info)
{
    int i = -1;
    info->philos = malloc(sizeof(t_philo) * info->num_philo);
    if (!info->philos)
        return (print_error("Error: init_philos memory allocation failure.\n"));
    info->forks = malloc(sizeof(pthread_mutex_t) * info->num_philo);
    if (!info->forks)
    {
        free(info->philos);
        return (print_error("Error: init_philos memory allocation failure.\n"));
    }
    info->start_time = get_time();
    while (++i < info->num_philo)
    {
        info->philos[i].id = i + 1;
        info->philos[i].left_fork = i;
        info->philos[i].right_fork = (i + 1) % info->num_philo;
        if (i == info->num_philo - 1)
            swap(&info->philos[i].left_fork, &info->philos[i].right_fork);
        info->philos[i].eat_cnt = 0;
        info->philos[i].last_eat_time = info->start_time;
        info->philos[i].info = info;
    }
    return (0);
}


int	init_mutex(t_info *info)
{
	int	i;

	i = -1;
	while (++i < info->num_philo)
	{
		if (pthread_mutex_init(&info->forks[i], NULL))
			return (print_error("Error: mutex initialization failure.\n"));
	}
	if (pthread_mutex_init(&info->print_mutex, NULL))
		return (print_error("Error: print mutex initialization failure.\n"));
	if (pthread_mutex_init(&info->eat_mutex, NULL))
		return (print_error("Error: eat mutex initialization failure.\n"));
	if (pthread_mutex_init(&info->finish_mutex, NULL))
		return (print_error("Error: finish mutex initialization failure.\n"));
	return (0);
}

int	create_philos(t_info *info)
{
	int	i;

	i = -1;
	while (++i < info->num_philo)
	{
		if (pthread_create(&info->philos[i].thread, NULL, philo_start, \
			&(info->philos[i])))
			return (print_error("Error: thread creation failure.\n"));
	}
	return (0);
}
