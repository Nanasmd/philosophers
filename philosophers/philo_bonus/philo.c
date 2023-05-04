/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nasamadi <nasamadi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/12 11:54:02 by nasamadi          #+#    #+#             */
/*   Updated: 2023/05/04 19:10:29 by nasamadi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

/*static void	eat(t_philo *philo)
{
	sem_wait(philo->info->forks);
	print_status(philo, "has taken a fork");
	sem_wait(philo->info->forks);
	print_status(philo, "has taken a fork");
	print_status(philo, "is eating");
	ft_sleep(philo->info->time_to_eat);
	sem_wait(philo->info->eat_sem);
	philo->eat_cnt += 1;
	philo->last_eat_time = get_time();
	sem_post(philo->info->eat_sem);
	sem_post(philo->info->forks);
	sem_post(philo->info->forks);
}

void	*check_dead(void *arg)
{
	t_philo	*philo;

	philo = arg;
	while (42)
	{
		sem_wait(philo->info->eat_sem);
		if ((get_time() - philo->last_eat_time) >= philo->info->time_to_die)
		{
			sem_post(philo->info->eat_sem);
			print_status(philo, "died");
			sem_wait(philo->info->print_sem);
			philo->info->finish = 1;
			exit(1);
		}
		if (philo->info->num_must_eat > 0 && philo->eat_cnt >= \
				philo->info->num_must_eat)
		{
			sem_post(philo->info->eat_sem);
			exit(1);
			break ;
		}
		sem_post(philo->info->eat_sem);
		usleep(5000);
	}
	return (NULL);
}

void	philo_start(t_philo *philo)
{
	pthread_t	thread;

	pthread_create(&thread, NULL, check_dead, philo);
	if (philo->id % 2 == 0)
		usleep(philo->info->time_to_eat * 1000);
	while (!philo->info->finish)
	{
		eat(philo);
		print_status(philo, "is sleeping");
		ft_sleep(philo->info->time_to_sleep);
		print_status(philo, "is thinking");
	}
	pthread_join(thread, NULL);
	exit(0);
}*/

/*static void eat(t_philo *philo)
{
    int left_fork = philo->id;
    int right_fork = (philo->id + 1) % philo->info->num_philo;

    sem_wait(&philo->info->forks[left_fork]);
    print_status(philo, "has taken a fork");
    sem_wait(&philo->info->forks[right_fork]);
    print_status(philo, "has taken a fork");
    print_status(philo, "is eating");
    ft_sleep(philo->info->time_to_eat);
    sem_wait(philo->info->eat_sem);
    philo->eat_cnt += 1;
    philo->last_eat_time = get_time();
    sem_post(philo->info->eat_sem);
    sem_post(&philo->info->forks[left_fork]);
    sem_post(&philo->info->forks[right_fork]);
}

void	*check_dead(void *arg)
{
	t_philo	*philo;

	philo = arg;
	while (42)
	{
		sem_wait(philo->info->eat_sem);
		if ((get_time() - philo->last_eat_time) >= philo->info->time_to_die)
		{
			//sem_post(philo->info->eat_sem);
			print_status(philo, "died");
			sem_wait(philo->info->print_sem);
			philo->info->finish = 1;
			exit(1);
		}
		if (philo->info->num_must_eat > 0 && philo->eat_cnt >= \
				philo->info->num_must_eat)
		{
			sem_post(philo->info->eat_sem);
			exit(1);
			break ;
		}
		sem_post(philo->info->eat_sem);
		usleep(5000);
	}
	return (NULL);
}


void philo_start(t_philo *philo)
{
    pthread_t thread;

    pthread_create(&thread, NULL, check_dead, philo);
    if (philo->id % 2 == 0)
        usleep(philo->info->time_to_eat * 1000);
    while (!philo->info->finish)
    {
        eat(philo);
        print_status(philo, "is sleeping");
        ft_sleep(philo->info->time_to_sleep);
        print_status(philo, "is thinking");
    }
    pthread_join(thread, NULL);
    exit(0);
}*/

/*static void eat(t_philo *philo)
{
    sem_wait(philo->info->forks);
    print_status(philo, "has taken a fork");
    sem_wait(philo->info->forks);
    print_status(philo, "has taken a fork");
    print_status(philo, "is eating");
    ft_sleep(philo->info->time_to_eat);
    sem_wait(philo->info->eat_sem);
    philo->eat_cnt += 1;
    philo->last_eat_time = get_time();
    sem_post(philo->info->eat_sem);
    sem_post(philo->info->forks);
    sem_post(philo->info->forks);
}

void *check_dead(void *arg)
{
    t_philo *philo;

    philo = arg;
    while (1)
    {
        sem_wait(philo->info->eat_sem);
        if ((get_time() - philo->last_eat_time) >= philo->info->time_to_die)
        {
            sem_post(philo->info->eat_sem);
            print_status(philo, "died");
            sem_wait(philo->info->print_sem);
            philo->info->finish = 1;
            exit(1);
        }
        if (philo->info->num_must_eat > 0 && philo->eat_cnt >= philo->info->num_must_eat)
        {
            sem_post(philo->info->eat_sem);
            exit(0);
            break;
        }
        sem_post(philo->info->eat_sem);
        usleep(5000);
    }
    return (NULL);
}

void philo_start(t_philo *philo)
{
    pthread_t thread;

    pthread_create(&thread, NULL, check_dead, philo);
    pthread_detach(thread); // Detach the thread
    if (philo->id % 2 == 0)
        ft_sleep(philo->info->time_to_eat * 1000);
	else
		ft_sleep(philo->info->time_to_eat * 500);
    while (!philo->info->finish)
    {
        eat(philo);
        print_status(philo, "is sleeping");
        ft_sleep(philo->info->time_to_sleep);
        print_status(philo, "is thinking");
    }
    exit(0);
}*/

/*static void eat(t_philo *philo)
{
    sem_wait(philo->info->forks);
    print_status(philo, "has taken a fork");
    sem_wait(philo->info->forks);
    print_status(philo, "has taken a fork");
    sem_wait(philo->info->eat_sem);
    philo->eat_cnt += 1;
    philo->last_eat_time = get_time();
    print_status(philo, "is eating");
    ft_sleep(philo->info->time_to_eat);
    sem_post(philo->info->eat_sem);
    sem_post(philo->info->forks);
    sem_post(philo->info->forks);
}



void *check_dead(void *arg)
{
    t_philo *philo;

    philo = arg;
    while (1)
    {
        sem_wait(philo->info->eat_sem);
        if ((get_time() - philo->last_eat_time) >= philo->info->time_to_die)
        {
            sem_post(philo->info->eat_sem);
            print_status(philo, "died");
            sem_wait(philo->info->print_sem);
            philo->info->finish = 1;
            exit(1);
        }
        if (philo->info->num_must_eat > 0 && philo->eat_cnt >= philo->info->num_must_eat)
        {
            sem_post(philo->info->eat_sem);
            exit(0);
            break;
        }
        sem_post(philo->info->eat_sem);
        usleep(5000);
    }
    return (NULL);
}

void philo_start(t_philo *philo)
{
    pthread_t thread;

    pthread_create(&thread, NULL, check_dead, philo);
    pthread_detach(thread); // Detach the thread
    if (philo->id % 2 == 0)
        ft_sleep(philo->info->time_to_eat / 2);
	else
		ft_sleep(philo->info->time_to_eat / 4);

    if (philo->info->time_to_die < (philo->info->time_to_eat + philo->info->time_to_sleep))
    {
        philo->info->time_to_eat = philo->info->time_to_die / 2;
        philo->info->time_to_sleep = philo->info->time_to_die / 2;
    }

    while (!philo->info->finish)
    {
        eat(philo);
        print_status(philo, "is sleeping");
        ft_sleep(philo->info->time_to_sleep);
        print_status(philo, "is thinking");
		usleep((rand() % 10 + 1) * 1000);
    }
    exit(0);
}*/






/*static void eat(t_philo *philo)
{
    sem_wait(philo->info->forks);
    print_status(philo, "has taken a fork");
    sem_wait(philo->info->forks);
    print_status(philo, "has taken a fork");
    print_status(philo, "is eating");
    ft_sleep(philo->info->time_to_eat);
    sem_wait(philo->info->eat_sem);
    philo->eat_cnt += 1;
    philo->last_eat_time = get_time();
    sem_post(philo->info->eat_sem);
    sem_post(philo->info->forks);
    sem_post(philo->info->forks);
}


void *check_dead(void *arg)
{
    t_philo *philo;

    philo = arg;
    while (42)
    {
        sem_wait(philo->info->eat_sem);
        if ((get_time() - philo->last_eat_time) >= philo->info->time_to_die)
        {
            sem_post(philo->info->eat_sem);
            print_status(philo, "died");
            sem_wait(philo->info->print_sem);
            philo->info->finish = 1;
            exit(1);
        }
        if (philo->info->num_must_eat > 0 && philo->eat_cnt >= philo->info->num_must_eat)
        {
            sem_post(philo->info->eat_sem);
            break;
        }
        sem_post(philo->info->eat_sem);
        usleep(5000);
    }
    return (NULL);
}

void philo_start(t_philo *philo)
{
    pthread_t thread;

    pthread_create(&thread, NULL, check_dead, philo);
    pthread_detach(thread);

    if (philo->info->time_to_die < (philo->info->time_to_eat + philo->info->time_to_sleep))
    {
        philo->info->time_to_eat = philo->info->time_to_die / 2;
        philo->info->time_to_sleep = philo->info->time_to_die / 2;
    }

    if (philo->id % 2 == 0)
        usleep(philo->info->time_to_eat * 1000);
	else
		usleep(philo->info->time_to_eat * 500);

    while (!philo->info->finish)
    {
        eat(philo);
        print_status(philo, "is sleeping");
        ft_sleep(philo->info->time_to_sleep);
        print_status(philo, "is thinking");
    }
}*/

int random_sleep(int max)
{
    return (rand() % max);
}

static void eat(t_philo *philo)
{
    if (philo->info->time_to_die < (philo->info->time_to_eat + philo->info->time_to_sleep))
    {
        philo->info->time_to_eat = philo->info->time_to_die / 2;
        philo->info->time_to_sleep = philo->info->time_to_die / 2;
    }

    sem_wait(philo->info->forks);
    print_status(philo, "has taken a fork");
    sem_wait(philo->info->forks);
    print_status(philo, "has taken a fork");
    print_status(philo, "is eating");
    ft_sleep(philo->info->time_to_eat);
    sem_wait(philo->info->eat_sem);
    philo->eat_cnt += 1;
    philo->last_eat_time = get_time();

    if (philo->info->num_must_eat > 0 && philo->eat_cnt >= philo->info->num_must_eat)
    {
        sem_wait(philo->info->meals_count_sem);
        philo->info->finished_meals++;
        sem_post(philo->info->meals_count_sem);
    }

    sem_post(philo->info->eat_sem);
    sem_post(philo->info->forks);
    sem_post(philo->info->forks);
}

/*int check_all_meals_finished(t_info *info)
{
    int i;

    i = 0;
    while (i < info->num_philo)
    {
        if (info->philos[i].eat_cnt < info->num_must_eat)
            return (0);
        i++;
    }
    return (1);
}

void	*check_dead(void *arg)
{
    t_philo	*philo;

    philo = arg;
    while (1)
    {
        sem_wait(philo->info->eat_sem);
        if ((get_time() - philo->last_eat_time) >= philo->info->time_to_die)
        {
            sem_post(philo->info->eat_sem);
            print_status(philo, "died");
            sem_wait(philo->info->print_sem);
            exit(1);
        }
        sem_post(philo->info->eat_sem);

        if (philo->info->num_must_eat > 0 && check_all_meals_finished(philo->info))
        {
            exit(0);
        }
        usleep(5000);
    }
    return (NULL);
}

void philo_start(t_philo *philo)
{
    pthread_t thread;

    pthread_create(&thread, NULL, check_dead, philo);
    pthread_detach(thread);

    if (philo->id % 2 == 0)
        usleep(philo->info->time_to_eat * 1000);
	else
		usleep(philo->info->time_to_eat * 500);

    while (1)
    {
        eat(philo);
        if (philo->info->num_must_eat > 0 && check_all_meals_finished(philo->info))
        {
            break;
        }
        print_status(philo, "is sleeping");
        ft_sleep(philo->info->time_to_sleep);
        print_status(philo, "is thinking");
		usleep((rand() % 10 + 1) * 1000);
    }
}*/

/*void *check_dead(void *arg)
{
    t_philo *philo;

    philo = arg;
    while (42)
    {
        sem_wait(philo->info->eat_sem);
        if ((get_time() - philo->last_eat_time) >= philo->info->time_to_die)
        {
            sem_post(philo->info->eat_sem);
            print_status(philo, "died");
            sem_wait(philo->info->print_sem);
            philo->info->finish = 1;
            exit(1);
        }
        sem_post(philo->info->eat_sem);

        sem_wait(philo->info->meals_count_sem);
        if (philo->info->num_must_eat > 0 && philo->info->meals_finished >= philo->info->num_philo)
        {
            sem_post(philo->info->meals_count_sem);
            break;
        }
        sem_post(philo->info->meals_count_sem);

        usleep(5000);
    }
    return (NULL);
}*/

void	*check_dead(void *arg)
{
	t_philo	*philo;
	int		meals_finished;
	int		i;

	philo = arg;
	while (42)
	{
		sem_wait(philo->info->eat_sem);
		if ((get_time() - philo->last_eat_time) >= philo->info->time_to_die)
		{
			sem_post(philo->info->eat_sem);
			print_status(philo, "died");
			sem_wait(philo->info->print_sem);
			philo->info->finished_meals = philo->info->num_philo;
			exit(1);
		}
		sem_post(philo->info->eat_sem);
		if (philo->info->num_must_eat > 0)
		{
			sem_wait(philo->info->meals_count_sem);
			meals_finished = 0;
			i = 0;
			while (i < philo->info->num_philo)
			{
				if (philo->info->philos[i].eat_cnt >= philo->info->num_must_eat)
				{
					meals_finished++;
				}
				i++;
			}
			if (meals_finished == philo->info->num_philo)
			{
				philo->info->finished_meals = 1;
				exit(0);
			}
			sem_post(philo->info->meals_count_sem);
		}
		usleep(5000);
	}
	return (NULL);
}


void philo_start(t_philo *philo)
{
    pthread_t thread;

    pthread_create(&thread, NULL, check_dead, philo);
    pthread_detach(thread);

    if (philo->id % 2 == 0)
        usleep(philo->info->time_to_eat * 1000);
	else
		usleep(philo->info->time_to_eat * 500);
	while (philo->info->finished_meals < philo->info->num_philo) //while (!philo->info->finish)
    {
        eat(philo);
        print_status(philo, "is sleeping");
        ft_sleep(philo->info->time_to_sleep);
        print_status(philo, "is thinking");
    }
}





