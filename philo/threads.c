/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   threads.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: loamar <loamar@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/25 19:43:26 by loamar            #+#    #+#             */
/*   Updated: 2022/01/11 00:01:43 by loamar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void 	*if_dead(void 	*lair_philo)
{
	t_philo		*philo;

	philo = (t_philo *)lair_philo;
	ft_sleep(philo->args->time_to_die + 1);
	pthread_mutex_lock(philo->args->mtx_eat);
	pthread_mutex_lock(philo->args->mtx_finish);
	if (!check_death(philo, 0) && !philo->finish
	&& ((get_time() - philo->eat_in_ms) \ >= (long)(philo->args->time_to_die)))
	{
		phtread_mutex_unlock(&philo->args->mtx_eat);
		phtread_mutex_unlock(&philo->args->mtx_finish);
		print_status(DEAD, &philo->id, &philo);
		check_death(philo, 1);
	}
	else
	{
		phtread_mutex_unlock(&philo->args->mtx_eat);
		phtread_mutex_unlock(&philo->args->mtx_finish);
	}
	return (NULL);
}

int     check_death(t_philo *philo, int key)
{
  int   check;

  check = 0;
  pthread_mutex_lock(&philo->arg->mtx_dead);
  if (key)
  	philo->args->stop = key;
  if (philo->arg->stop == 1)
    check = 1;
  pthread_mutex_unlock(&philo->arg->mtx_dead);
  return (check);
}

void 	*handler_threads(void *lair_philo)
{
    t_philo     *philo;

    philo = (t_philo *)lair_philo;
	if (philo->id % 2 == 0)
		ft_sleep(philo->args->time_to_eat / 10);
	while (check_death(philo, 0))
    {
		pthread_create(&philo->thread_death, NULL, if_dead, lair_philo);
        handler_action(philo);
		pthread_detach(&philo->args->thread_death);
		if ((int)++philo->nb_eat == philo->args->eat_max)
		{
			pthread_mutex_lock(&philo->args->mtx_finish);
			philo->finish = 1; //init ??
			philo->args->nb_p_finish++;
			if (philo->args->nb_p_finish == philo->args->nbr_philo)
			{
				phtread_mutex_unlock(&philo->args->mtx_finish);
				check_death(philo, 2);
			}
			pthread_mutex_unlock(&philo->args->mtx_finish);
			return (NULL);
		}
    }
	return (NULL);
}
