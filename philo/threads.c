/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   threads.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: loamar <loamar@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/25 19:43:26 by loamar            #+#    #+#             */
/*   Updated: 2022/01/11 21:42:32 by loamar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	check_death2(t_data *data)
{
	pthread_mutex_lock(&data->arg.mtx_dead);
	if (data->arg.stop_time)
	{
		pthread_mutex_unlock(&data->arg.mtx_dead);
		return (1);
	}
	pthread_mutex_unlock(&data->arg.mtx_dead);
	return (0);
}

void	finish_thread(t_data *data)
{
	int	count;

	count = -1;
	printf("finish 1\n");
	while (!check_death2(data))
		ft_sleep(1);
	printf("finish 2\n");
	while (++count < data->arg.nbr_philo)
		pthread_join(data->philo[count].thread_philo, NULL);
	printf("finish 3\n");
	pthread_mutex_destroy(&data->arg.mtx_write);
	printf("finish 4\n");
	count = -1;
	while (++count < data->arg.nbr_philo)
		pthread_mutex_destroy(&data->philo[count].left_hand);
	printf("finish 5\n");
	if (data->arg.stop_time == 2)
		printf("Each philosopher ate %d time(s)\n", data->arg.eat_max);
	printf("finish 6\n");
	free(data->philo);
	printf("finish 7\n");
}

void	*if_dead(void *lair_philo)
{
	t_philo		*philo;

	philo = (t_philo *)lair_philo;
	ft_sleep(philo->args->time_to_die + 1);
	pthread_mutex_lock(&philo->args->mtx_eat);
	pthread_mutex_lock(&philo->args->mtx_finish);
	if (!check_death(philo, 0) && !philo->finish \
	&& ((get_time() - philo->eat_in_ms) >= \
	(long)(philo->args->time_to_die)))
	{
		pthread_mutex_unlock(&philo->args->mtx_eat);
		pthread_mutex_unlock(&philo->args->mtx_finish);
		print_status(DEAD, philo->id, philo);
		check_death(philo, 1);
	}
	pthread_mutex_unlock(&philo->args->mtx_eat);
	pthread_mutex_unlock(&philo->args->mtx_finish);
	return (NULL);
}

int	check_death(t_philo *philo, int key)
{
	pthread_mutex_lock(&philo->args->mtx_dead);
	if (key)
		philo->args->stop_time = key;
	if (philo->args->stop_time)
	{
		pthread_mutex_unlock(&philo->args->mtx_dead);
		return (1);
	}
	pthread_mutex_unlock(&philo->args->mtx_dead);
	return (0);
}

void	*handler_threads(void *lair_philo)
{
	t_philo	*philo;

	philo = (t_philo *)lair_philo;
	if (philo->id % 2 == 0)
		ft_sleep(philo->args->time_to_eat / 10);
	while (check_death(philo, 0))
	{
		pthread_create(&philo->thread_death, NULL, if_dead, lair_philo);
		handler_action(philo);
		pthread_detach(philo->thread_death);
		if ((int)++philo->nbr_eat == philo->args->eat_max)
		{
			pthread_mutex_lock(&philo->args->mtx_finish);
			philo->finish = 1;
			philo->args->nb_p_finish++;
			if (philo->args->nb_p_finish == philo->args->nbr_philo)
			{
				pthread_mutex_unlock(&philo->args->mtx_finish);
				check_death(philo, 2);
			}
			pthread_mutex_unlock(&philo->args->mtx_finish);
			return (NULL);
		}
	}
	return (NULL);
}

int	create_thread(t_data *data)
{
	int	count;

	count = 0;
	while (count < data->arg.nbr_philo)
	{
		data->philo[count].args = &data->arg;
		if (pthread_create(&data->philo[count].thread_philo, NULL, handler_threads, &data->philo[count]) != 0)
			return (error_msg("Error : Pthread not return 0"));
		count++;
	}
	return (1);
}
