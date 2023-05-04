/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nasamadi <nasamadi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/12 11:53:50 by nasamadi          #+#    #+#             */
/*   Updated: 2023/05/04 18:51:10 by nasamadi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	init_info(t_info *info, int ac, char **av)
{
	int	i;

	i = 0;
	if (ac < 5 || ac > 6)
		return (print_error("Error: incorrect number of arguments.\n"));
	info->num_philo = ft_atoi(av[1]);
	info->time_to_die = ft_atoi(av[2]);
	info->time_to_eat = ft_atoi(av[3]);
	info->time_to_sleep = ft_atoi(av[4]);
	if (info->num_philo < 1 || info->time_to_die < 1 || \
			info->time_to_eat < 1 || info->time_to_sleep < 1)
		return (print_error("Error: invalid argument values.\n"));
	if (ac == 6)
	{
		info->num_must_eat = ft_atoi(av[5]);
		if (info->num_must_eat < 1)
			return (print_error("Error: invalid argument values.\n"));
	}
	else
		info->num_must_eat = -1;
	info->finished_meals = 0;
	return (0);
}

static sem_t	*init_sem(const char *name, unsigned int n)
{
	sem_t	*sem;

	sem = sem_open(name, O_CREAT, 0644, n);
	sem_unlink(name);
	return (sem);
}


int	init_philos(t_info *info)
{
	int	i;

	i = -1;
	info->finished_meals = 0;
	info->philos = malloc(sizeof(t_philo) * info->num_philo);
	info->meals_count_sem = malloc(sizeof(sem_t));
	if (sem_init(info->meals_count_sem, 0, 1) != 0)
	{
		perror("Semaphore initialization failed");
		return (0);
	}
	if (!info->philos)
		return (print_error("Error: init_philos memory allocation failure.\n"));
	info->forks = init_sem("forks", info->num_philo);
	info->eat_sem = init_sem("eat", 1);
	info->print_sem = init_sem("print", 1);
	if (info->forks == SEM_FAILED || info->eat_sem == SEM_FAILED || \
			info->print_sem == SEM_FAILED)
		return (print_error("Error: sem_open\n"));
	while (++i < info->num_philo)
	{
		info->philos[i].id = i + 1;
		info->philos[i].eat_cnt = 0;
		info->philos[i].info = info;
	}
	return (0);
}

void	fork_philos(t_info *info)
{
	int	i;

	i = -1;
	info->start_time = get_time();
	while (++i < info->num_philo)
	{
		info->philos[i].last_eat_time = info->start_time;
		info->philos[i].pid = fork();
		if (info->philos[i].pid == 0)
		{
			philo_start(&info->philos[i]);
			break ;
		}
		else if (info->philos[i].pid < 0)
			exit(print_error("Error: fork fail\n"));
	}
}

