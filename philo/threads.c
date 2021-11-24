/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   threads.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: loamar <loamar@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/25 19:43:26 by loamar            #+#    #+#             */
/*   Updated: 2021/10/04 15:46:39 by loamar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int     check_death(t_philo *philo)
{
  int   check;

  check = 0;
  pthread_mutex_lock(&philo->arg->mtx_dead);
  if (philo->arg->stop == 1)
    check = 1;
  pthread_mutex_unlock(&philo->arg->mtx_dead);
  return (check);
}

void 	handler_threads(void *lair_philo)
{
    t_philo     *philo;

    philo = (t_philo *)lair_philo;
	while (check_death(philo))
    {
        handler_action(philo);

        // pthread_create(&philo->thread_death, NULL, death, lair_philo);
        // pthread_detach(&philo->thread_death)

    }
}

// int    create_threads(t_data *data)
// {
//     int     count;
//
//     count = 0;
//     while (count < data->arg.nbr_philo)
//     {
//         if (pthread_create(&data->philo[count].thread_philo, NULL, handler_threads, &data->philo[count]) != 0)
//             return (error_msg("Error : Pthread_create\n"));
//         count++;
//     }
// 	return (SUCCESS);
// }
