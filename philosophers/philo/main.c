/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nasamadi <nasamadi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/12 11:52:42 by nasamadi          #+#    #+#             */
/*   Updated: 2023/05/04 12:57:10 by nasamadi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	main(int ac, char **av)
{
	t_info	info;

	if (init_info(&info, ac, av))
		return (0);
	if (init_philos(&info))
		return (free_info(&info));
	if (init_mutex(&info))
		return (free_destroy(&info));
	if (create_philos(&info))
		return (0);
	destroy(&info);
	return (0);
}

/*int main(int ac, char **av)
{
    t_info info;

    if (init_info(&info, ac, av) || init_philos(&info) || init_mutex(&info) || create_philos(&info))
        return (1);
    destroy(&info);
    return (0);
}*/
