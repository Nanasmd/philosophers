/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nasamadi <nasamadi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/12 11:52:32 by nasamadi          #+#    #+#             */
/*   Updated: 2023/04/21 17:20:29 by nasamadi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	free_info(t_info *info)
{
	free(info->philos);
	free(info->forks);
	return (0);
}

int	free_destroy(t_info *info)
{
	int	i;

	i = -1;
	while (++i < info->num_philo)
		pthread_mutex_destroy(&info->forks[i]);
	pthread_mutex_destroy(&info->print_mutex);
	pthread_mutex_destroy(&info->eat_mutex);
	pthread_mutex_destroy(&info->finish_mutex);
	free_info(info);
	return (0);
}

void	join_free_destroy(t_info *info)
{
	int	i;

	i = -1;
	while (++i < info->num_philo)
		pthread_join(info->philos[i].thread, NULL);
	free_destroy(info);
}

void	destroy(t_info *info)
{
	int	i;
	int	yes;

	yes = 1;
	while (yes)
	{
		i = -1;
		info->num_full_philo = 0;
		while (++i < info->num_philo)
		{
			if (yes && check_dead(&info->philos[i]))
				yes = 0;
		}
		usleep(10);
	}
	join_free_destroy(info);
}

/*void	destroy(t_info *info)
{
	int	i;

	i = -1;
	while (++i < info->num_philo)
		pthread_join(info->philos[i].thread, NULL);
	i = -1;
	while (++i < info->num_philo)
		pthread_mutex_destroy(&info->forks[i]);
	pthread_mutex_destroy(&info->print_mutex);
	pthread_mutex_destroy(&info->eat_mutex);
	pthread_mutex_destroy(&info->finish_mutex);
	free(info->philos);
	free(info->forks);
}*/
