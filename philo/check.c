/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nasamadi <nasamadi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/05 10:03:22 by nasamadi          #+#    #+#             */
/*   Updated: 2023/05/05 10:09:03 by nasamadi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	check_dead(t_philo *philo)
{
	pthread_mutex_lock(&philo->info->eat_mutex);
	if ((get_time() - philo->last_eat_time) >= philo->info->time_to_die)
	{
		print_status(philo, "died");
		check_finish(philo, 1);
		pthread_mutex_unlock(&philo->info->eat_mutex);
		return (1);
	}
	else if (philo->info->num_must_eat > 0 && philo->eat_cnt >= \
		philo->info->num_must_eat)
	{
		philo->info->num_full_philo++;
		if (philo->info->num_full_philo >= philo->info->num_philo)
		{
			check_finish(philo, 1);
			print_status(philo, "f");
			pthread_mutex_unlock(&philo->info->eat_mutex);
			return (1);
		}
	}
	pthread_mutex_unlock(&philo->info->eat_mutex);
	return (0);
}

int	check_finish(t_philo *philo, int yes)
{
	pthread_mutex_lock(&philo->info->finish_mutex);
	if (yes)
	{
		philo->info->finish = 1;
		pthread_mutex_unlock(&philo->info->finish_mutex);
		return (1);
	}
	if (philo->info->finish)
	{
		pthread_mutex_unlock(&philo->info->finish_mutex);
		return (1);
	}
	pthread_mutex_unlock(&philo->info->finish_mutex);
	return (0);
}

void	one_philosopher_case(t_philo *philo)
{
	print_status(&philo->info->philos[0], "has taken a fork");
	ft_sleep(&philo->info->philos[0], philo->info->time_to_die);
	print_status(&philo->info->philos[0], "died");
	check_finish(&philo->info->philos[0], 1);
}
