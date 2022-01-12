/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_and_error.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: loamar <loamar@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/19 12:53:21 by loamar            #+#    #+#             */
/*   Updated: 2022/01/11 00:11:44 by loamar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	get_time(void)
{
	long int			time_ms;
	struct timeval		time_value;

	time_ms = 0;
	if (gettimeofday(&time_value, NULL) != 0)
		return (error_msg("Error : gettimeofday return -1"));
	time_ms = (time_value.tv_sec * 1000) + (time_value.tv_usec / 1000);
	return (time_ms);
}

static void	synchronize_philo(t_data *data)
{
	int	count_id;

	count_id = 0;
	while (count_id <= data->arg.nbr_philo)
	{
		data->philo[count_id].id = count_id + 1;
		data->philo[count_id].eat_in_ms = data->arg.start_time;
		data->philo[count_id].nbr_eat = 0;
		data->philo[count_id].finish = 0;
		data->philo[count_id].right_hand = NULL;
		pthread_mutex_init(&data->philo[count_id].left_hand, NULL);
		if (data->arg.nbr_philo == 1)
			return;
		if (count_id == data->arg.nbr_philo - 1)
			data->philo[count_id].right_hand = &data->philo[0].left_hand;
		else
			data->philo[count_id].right_hand = \
			&data->philo[count_id + 1].left_hand;
		count_id++;
	}
}

int	init_philo(t_data *data)
{
	data->arg.stop_time = 0;
	data->arg.start_time = get_time();
	data->arg.nb_p_finish = 0;
	if (data->arg.start_time == ERROR)
		return (ERROR);
	pthread_mutex_init(&data->arg.mtx_write, NULL);
	pthread_mutex_init(&data->arg.mtx_eat, NULL);
	pthread_mutex_init(&data->arg.mtx_dead, NULL);
	pthread_mutex_init(&data->arg.mtx_end, NULL);
	pthread_mutex_init(&data->arg.mtx_finish, NULL);
	synchronize_philo(data);
	return (SUCCESS);
}

int	error_msg(char *msg)
{
	ft_putstr_fd(msg, 2);
	ft_putchar_fd('\n', 2);
	return (ERROR);
}
