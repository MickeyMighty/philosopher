/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_and_error.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: loamar <loamar@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/19 12:53:21 by loamar            #+#    #+#             */
/*   Updated: 2021/09/29 16:10:33 by loamar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static int	 	get_time(void)
{
	struct	timeval	current_time;
	if (gettimeofday(&current_time, NULL) != 0)
		return (error_msg("Error : gettimeofday return -1"));
	printf("seconds : %ld\nmicro seconds : %d", current_time.tv_sec, current_time.tv_usec);
	printf("\nend\n");
	exit (0);
}

static void 	give_id_each_philo(t_data *data)
{
	int		count_id;

	count_id = 1;
	while (count_id <= data->arg.nbr_philo)
	{
		if (count_id < data->arg.nbr_philo)
			data->philo[count_id - 1].right_hand = data->philo[count_id].left_hand;
		if (count_id == data->arg.nbr_philo)
			data->philo[count_id - 1].right_hand = data->philo[0].left_hand;
		data->philo[count_id - 1].id = count_id;
		if (data->arg.nbr_philo > 1)
			data->philo[count_id - 1].right_hand = data->philo[count_id].left_hand;
		count_id++;
	}
}

int				init_philo(t_data *data)
{
	data->arg.stop_time = 0;
	data->arg.start_time = get_time();
	if (data->arg.start_time == ERROR)
		return (ERROR);
	printf("actual_time = [%d]\n", data->arg.start_time);
	pthread_mutex_init(&data->arg.mtx_write, NULL);
	pthread_mutex_init(&data->arg.mtx_eat, NULL);
	pthread_mutex_init(&data->arg.mtx_dead, NULL);
	pthread_mutex_init(&data->arg.mtx_end, NULL);
	give_id_each_philo(data);
	return (0);
}

int 		error_msg(char *msg)
{
	ft_putstr_fd(msg, 2);
	ft_putchar_fd('\n', 2);
	return (ERROR);
}
