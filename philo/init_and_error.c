/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_and_error.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: loamar <loamar@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/19 12:53:21 by loamar            #+#    #+#             */
/*   Updated: 2021/10/04 14:14:04 by loamar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static int	 	get_time(void)
{
	long int	time_ms;
	struct	timeval	time_value;

	time_ms = 0;
	if (gettimeofday(&current_time, NULL) != 0)
		return (error_msg("Error : gettimeofday return -1"));
	time_ms = (time_value.tv_sec * 1000) + (time_value.tv_usec / 1000);
	return (time_ms);
}

static void 	synchronize_philo(t_data *data)
{
	int		count_id;

	count_id = 1;
	while (count_id <= data->arg.nbr_philo)
	{
		if (count_id < data->arg.nbr_philo)
			data->philo[count_id - 1].right_hand = data->philo[count_id].left_hand;
		if (count_id == data->arg.nbr_philo)
			data->philo[count_id - 1].right_hand = &data->philo[0].left_hand;
		if (data->arg.nbr_philo > 1)
			data->philo[count_id - 1].right_hand = &data->philo[count_id].left_hand;
		data->philo[count_id - 1].id = count_id;
		data->philo[count_id - 1].eat_time = data.arg.start_time;
		data->philo.start_time

		count_id++;
	}
}

int				init_philo(t_data *data)
{
	int     count;

	count = 0;
	data->arg.stop_time = 0;
	data->arg.start_time = get_time();
	if (data->arg.start_time == ERROR)
		return (ERROR);
	pthread_mutex_init(&data->arg.mtx_write, NULL);
	pthread_mutex_init(&data->arg.mtx_eat, NULL);
	pthread_mutex_init(&data->arg.mtx_dead, NULL);
	pthread_mutex_init(&data->arg.mtx_end, NULL);
	synchronize_philo(data);
	while (count < data->arg.nbr_philo)
	{
		if (pthread_create(&data->philo[count].thread_philo, NULL, handler_threads, &data->philo[count]) != 0)
			return (error_msg("Error : Pthread_create\n"));
		count++;
	}
	return (SUCCESS);
}

int 		error_msg(char *msg)
{
	ft_putstr_fd(msg, 2);
	ft_putchar_fd('\n', 2);
	return (ERROR);
}
