/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nasamadi <nasamadi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/12 11:52:51 by nasamadi          #+#    #+#             */
/*   Updated: 2023/05/05 11:02:24 by nasamadi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	acquire_forks(t_philo *philo)
{
	pthread_mutex_lock(&philo->info->forks[philo->left_fork]);
	print_status(philo, "has taken a fork");
	pthread_mutex_lock(&philo->info->forks[philo->right_fork]);
	print_status(philo, "has taken a fork");
}

void	release_forks(t_philo *philo)
{
	pthread_mutex_unlock(&philo->info->forks[philo->left_fork]);
	pthread_mutex_unlock(&philo->info->forks[philo->right_fork]);
}

void	eating(t_philo *philo)
{
	pthread_mutex_lock(&philo->info->eat_mutex);
	philo->last_eat_time = get_time();
	philo->eat_cnt++;
	print_status(philo, "is eating");
	pthread_mutex_unlock(&philo->info->eat_mutex);
}

void	main_loop(t_philo *philo)
{
	int	t;

	while (!check_finish(philo, 0))
	{
		acquire_forks(philo);
		eating(philo);
		ft_sleep(philo, philo->info->time_to_eat);
		release_forks(philo);
		if (philo->info->num_must_eat != -1 && philo->eat_cnt >= \
			philo->info->num_must_eat)
			break ;
		print_status(philo, "is sleeping");
		ft_sleep(philo, philo->info->time_to_sleep);
		print_status(philo, "is thinking");
		if (philo->info->num_philo % 2 == 1)
		{
			t = philo->info->time_to_eat;
			usleep(t * 1000 * 0.7);
		}
	}
}

void	*philo_start(void *arg)
{
	t_philo	*philo;
	t_info	*info;

	philo = (t_philo *)arg;
	info = philo->info;
	if (philo->id % 2 == 0)
		usleep(philo->info->time_to_eat * 1000);
	if (info->num_philo == 1)
	{
		one_philosopher_case(philo);
		return (0);
	}
	main_loop(philo);
	return (0);
}

/*void	*philo_start(void *arg)
{
	t_philo	*philo;
	t_info	*info;
	int		t;

	philo = (t_philo *)arg;
	info = philo->info;
	if (philo->id % 2 == 0)
		usleep(philo->info->time_to_eat * 1000);
	if (info->num_philo == 1)
	{
		print_status(&info->philos[0], "has taken a fork");
		ft_sleep(&info->philos[0], info->time_to_die);
		print_status(&info->philos[0], "died");
		check_finish(&info->philos[0], 1);
		return (0);
	}
	while (!check_finish(philo, 0))
	{
		pthread_mutex_lock(&philo->info->forks[philo->left_fork]);
		print_status(philo, "has taken a fork");
		pthread_mutex_lock(&philo->info->forks[philo->right_fork]);
		print_status(philo, "has taken a fork");
		pthread_mutex_lock(&philo->info->eat_mutex);
		philo->last_eat_time = get_time();
		philo->eat_cnt++;
		print_status(philo, "is eating");
		pthread_mutex_unlock(&philo->info->eat_mutex);
		ft_sleep(philo, philo->info->time_to_eat);
		pthread_mutex_unlock(&philo->info->forks[philo->left_fork]);
		pthread_mutex_unlock(&philo->info->forks[philo->right_fork]);
		if (philo->info->num_must_eat != -1 && philo->eat_cnt >= \
			philo->info->num_must_eat)
			break ;
		print_status(philo, "is sleeping");
		ft_sleep(philo, philo->info->time_to_sleep);
		print_status(philo, "is thinking");
		if (philo->info->num_philo % 2 == 1)
		{
			t = philo->info->time_to_eat;
			usleep(t * 1000 * 0.7);
		}
	}
	return (0);
}*/