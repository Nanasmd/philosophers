/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nasamadi <nasamadi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/12 11:52:51 by nasamadi          #+#    #+#             */
/*   Updated: 2023/05/04 18:00:13 by nasamadi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

/*int	check_dead(t_philo *philo)
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
}*/

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
	else if (philo->info->num_must_eat > 0 && philo->eat_cnt >= philo->info->num_must_eat)
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


/*static void	eat(t_philo *philo)
{
	pthread_mutex_lock(&philo->info->forks[philo->left_fork]);
	print_status(philo, "has taken a fork");
	pthread_mutex_lock(&philo->info->forks[philo->right_fork]);
	print_status(philo, "has taken a fork");
	print_status(philo, "is eating");
	ft_sleep(philo, philo->info->time_to_eat);
	pthread_mutex_lock(&philo->info->eat_mutex);
	philo->eat_cnt += 1;
	philo->last_eat_time = get_time();
	pthread_mutex_unlock(&philo->info->eat_mutex);
	pthread_mutex_unlock(&philo->info->forks[philo->right_fork]);
	pthread_mutex_unlock(&philo->info->forks[philo->left_fork]);
}*/

/*static void	right_fork(t_philo *philo)
{
	pthread_mutex_lock(&philo->info->forks[philo->right_fork]);
	print_status(philo, "has taken a fork");
	pthread_mutex_lock(&philo->info->forks[philo->left_fork]);
	print_status(philo, "has taken a fork");
	print_status(philo, "is eating");
}

static void	left_fork(t_philo *philo)
{
	pthread_mutex_lock(&philo->info->forks[philo->left_fork]);
	print_status(philo, "has taken a fork");
	pthread_mutex_lock(&philo->info->forks[philo->right_fork]);
	print_status(philo, "has taken a fork");
	print_status(philo, "is eating");
}*/

/*int	check_finish(t_philo *philo, int yes)
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
}*/

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

/*void	*philo_start(void *arg)
{
	t_philo	*philo;
	t_info	*info;

	philo = (t_philo *)arg;
	info = philo->info;
	if (philo->id % 2 == 0)
		usleep(philo->info->time_to_eat * 2000);
	if (info->num_philo == 1)
	{
		print_status(&info->philos[0], "has taken a fork");
		ft_sleep(&info->philos[0], info->time_to_die);
		print_status(&info->philos[0], "died");
		check_finish(&info->philos[0], 1);
		return (0);
	}
	while (42)
	{
		if (check_finish(philo, 0))
			return (0);
		//eat_left(philo);
		//eat_right(philo);
		if (philo->id % 2 == 0)
		{
			eat_left(philo);
			eat_right(philo);
		}
		else
		{
			eat_right(philo);
			eat_left(philo);
		}
		print_status(philo, "is sleeping");
		ft_sleep(philo, philo->info->time_to_sleep);
		print_status(philo, "is thinking");
	}
	return (0);
}*/

int random_sleep(int max)
{
    return (rand() % max);
}

/*void	*philo_start(void *arg)
{
	t_philo	*philo;
	t_info	*info;

	philo = (t_philo *)arg;
	info = philo->info;
	if (philo->id % 2 == 0 && info->num_args == 5)
		//usleep((philo->info->time_to_eat / 2) * 1000);
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
		usleep((rand() % 10 + 1) * 100);
		pthread_mutex_lock(&philo->info->forks[philo->left_fork]);
		print_status(philo, "has taken a fork");
		usleep((rand() % 10 + 1) * 100);
		pthread_mutex_lock(&philo->info->forks[philo->right_fork]);
		print_status(philo, "has taken a fork");
		pthread_mutex_lock(&philo->info->eat_mutex);
		philo->last_eat_time = get_time();
		philo->eat_cnt++;
		print_status(philo, "is eating");
		pthread_mutex_unlock(&philo->info->eat_mutex);
		if (info->num_args == 5)
			ft_sleep(philo, philo->info->time_to_eat);
		pthread_mutex_unlock(&philo->info->forks[philo->left_fork]);
		pthread_mutex_unlock(&philo->info->forks[philo->right_fork]);
		if (philo->info->num_must_eat != -1 && philo->eat_cnt >= philo->info->num_must_eat)
			break ;
		print_status(philo, "is sleeping");
		ft_sleep(philo, philo->info->time_to_sleep);
		print_status(philo, "is thinking");
	}
    return (NULL);
}*/






void	*philo_start(void *arg)
{
	t_philo	*philo;
	t_info	*info;

	philo = (t_philo *)arg;
	info = philo->info;

	if (info->num_philo == 1)
	{
		print_status(&info->philos[0], "has taken a fork");
		ft_sleep(&info->philos[0], info->time_to_die);
		print_status(&info->philos[0], "died");
		check_finish(&info->philos[0], 1);
		return (0);
	}

	if (philo->id % 2 == 0)
		usleep(philo->info->time_to_eat * 1000);
	else
		usleep(philo->info->time_to_eat * 500);

	if (info->time_to_die < (info->time_to_eat + info->time_to_sleep))
	{
		info->time_to_eat = info->time_to_die / 2;
		info->time_to_sleep = info->time_to_die / 2;
	}
	
	while (!check_finish(philo, 0))
	{
		
		//usleep((rand() % 10 + 1) * 100);
		pthread_mutex_lock(&philo->info->forks[philo->left_fork]);
		print_status(philo, "has taken a fork");

		//usleep((rand() % 10 + 1) * 100);
		pthread_mutex_lock(&philo->info->forks[philo->right_fork]);
		print_status(philo, "has taken a fork");

		pthread_mutex_lock(&philo->info->eat_mutex);
		philo->last_eat_time = get_time();
		philo->eat_cnt++;
		print_status(philo, "is eating");
		pthread_mutex_unlock(&philo->info->eat_mutex);

		if (info->num_args == 5)
			ft_sleep(philo, philo->info->time_to_eat);

		pthread_mutex_unlock(&philo->info->forks[philo->left_fork]);
		pthread_mutex_unlock(&philo->info->forks[philo->right_fork]);

		if (philo->info->num_must_eat != -1 && philo->eat_cnt >= philo->info->num_must_eat)
			break ;

		print_status(philo, "is sleeping");
		ft_sleep(philo, philo->info->time_to_sleep);

		print_status(philo, "is thinking");
		//usleep((rand() % 10 + 1) * 1000);
	}

	return (NULL);
}


/*void	*philo_start(void *arg)
{
	t_philo	*philo;
	t_info	*info;

	philo = (t_philo *)arg;
	info = philo->info;
	if (philo->id % 2 == 0  && info->num_args == 5)
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
		if (info->num_args == 5)
		{
			ft_sleep(philo, philo->info->time_to_eat);
			pthread_mutex_unlock(&philo->info->forks[philo->left_fork]);
			pthread_mutex_unlock(&philo->info->forks[philo->right_fork]);
		}
		else if (info->num_args == 6)
		{
			pthread_mutex_unlock(&philo->info->forks[philo->left_fork]);
			pthread_mutex_unlock(&philo->info->forks[philo->right_fork]);
		}
		if (philo->info->num_must_eat != -1 && philo->eat_cnt >= philo->info->num_must_eat)
			break ;
		print_status(philo, "is sleeping");
		ft_sleep(philo, philo->info->time_to_sleep);
		print_status(philo, "is thinking");
	}
    return (0);
}*/

/*void	*philo_start(void *arg)
{
	t_philo	*philo;
	t_info	*info;
	time_t	max_time;

	philo = (t_philo *)arg;
	info = philo->info;
	max_time = info->time_to_die + 2 * info->time_to_eat + info->time_to_sleep + 1000; // 10 is a safety margin
	if (philo->id % 2 == 0  && info->num_args == 5)
		usleep(philo->info->time_to_eat * 1000);
	if (info->num_philo == 2 && info->num_args == 5)
		usleep(1000);
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
		if ((get_time() - philo->last_eat_time) >= max_time)
		{
			print_status(philo, "died");
			check_finish(philo, 1);
			return (NULL);
		}
		pthread_mutex_lock(&philo->info->forks[philo->left_fork]);
		print_status(philo, "has taken a fork");
		pthread_mutex_lock(&philo->info->forks[philo->right_fork]);
		print_status(philo, "has taken a fork");
		pthread_mutex_lock(&philo->info->eat_mutex);
		philo->last_eat_time = get_time();
		philo->eat_cnt++;
		print_status(philo, "is eating");
		pthread_mutex_unlock(&philo->info->eat_mutex);
		if (info->num_args == 5)
			ft_sleep(philo, philo->info->time_to_eat);
		pthread_mutex_unlock(&philo->info->forks[philo->left_fork]);
		pthread_mutex_unlock(&philo->info->forks[philo->right_fork]);
		if (philo->info->num_must_eat != -1 && philo->eat_cnt >= philo->info->num_must_eat)
			break ;
		print_status(philo, "is sleeping");
		ft_sleep(philo, philo->info->time_to_sleep);
		print_status(philo, "is thinking");
	}
    return (NULL);
}*/

/*void	*philo_start(void *arg)
{
	t_philo	*philo;
	t_info	*info;
	time_t	max_time;

	philo = (t_philo *)arg;
	info = philo->info;
	max_time = info->time_to_die + 2 * info->time_to_eat + info->time_to_sleep + 1000; // 10 is a safety margin
	if (philo->id % 2 == 0  && info->num_args == 5)
		usleep(philo->info->time_to_eat * 1000);
	if (info->num_philo == 2 && info->num_args == 5)
		usleep(1000);
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
		if (get_time() - philo->last_eat_time >= max_time)
		{
			print_status(philo, "died");
			check_finish(philo, 1);
			return (NULL);
		}
		pthread_mutex_lock(&philo->info->forks[philo->left_fork]);
		print_status(philo, "has taken a fork");
		pthread_mutex_lock(&philo->info->forks[philo->right_fork]);
		print_status(philo, "has taken a fork");
		pthread_mutex_lock(&philo->info->eat_mutex);
		philo->last_eat_time = get_time();
		philo->eat_cnt++;
		print_status(philo, "is eating");
		pthread_mutex_unlock(&philo->info->eat_mutex);
		if (info->num_args == 5)
			ft_sleep(philo, philo->info->time_to_eat);
		pthread_mutex_unlock(&philo->info->forks[philo->left_fork]);
		pthread_mutex_unlock(&philo->info->forks[philo->right_fork]);
		if (philo->info->num_must_eat != -1 && philo->eat_cnt >= philo->info->num_must_eat)
			break ;
		print_status(philo, "is sleeping");
		ft_sleep(philo, philo->info->time_to_sleep);
		print_status(philo, "is thinking");
		if (info->num_args == 6 && info->finish)
			return (NULL);
	}
	return (NULL);
}*/
