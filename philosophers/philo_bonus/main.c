/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nasamadi <nasamadi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/12 11:53:54 by nasamadi          #+#    #+#             */
/*   Updated: 2023/05/04 18:37:25 by nasamadi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

/*static void	close_info(t_info *info)
{
	int		i;
	int		stat;

	i = -1;
	while (++i < info->num_philo)
	{
		waitpid(-1, &stat, 0);
		if (stat != 0)
		{
			i = -1;
			while (++i < info->num_philo)
				kill(info->philos[i].pid, SIGTERM);
			break ;
		}
	}
	free(info->philos);
	sem_close(info->forks);
	sem_close(info->eat_sem);
	sem_close(info->print_sem);
}

int	main(int ac, char **av)
{
	t_info		info;


	if (init_info(&info, ac, av))
		return (0);
	if (init_philos(&info))
	{
		free(info.philos);
		return (0);
	}
	fork_philos(&info);
	close_info(&info);
}*/

static void close_info(t_info *info)
{
    int i;
    int stat;

    i = -1;
    while (++i < info->num_philo)
    {
        waitpid(-1, &stat, 0);
        if (stat != 0)
        {
            i = -1;
            while (++i < info->num_philo)
                kill(info->philos[i].pid, SIGTERM);
            break;
        }
    }
    free(info->philos);
	sem_destroy(info->meals_count_sem);
	free(info->meals_count_sem);
    sem_close(info->forks);
    sem_close(info->eat_sem);
    sem_close(info->print_sem);
    sem_unlink("forks");
    sem_unlink("eat");
    sem_unlink("print");
}

int main(int ac, char **av)
{
    t_info info;

    if (init_info(&info, ac, av))
        return (0);
    if (init_philos(&info))
    {
        free(info.philos);
        return (0);
    }
    fork_philos(&info);
    close_info(&info);
    return (0);
}