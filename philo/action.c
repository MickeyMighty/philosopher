/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   action.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: loamar <loamar@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/31 01:49:44 by loamar            #+#    #+#             */
/*   Updated: 2022/01/11 11:03:50 by loamar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	ft_sleep(long int time)
{
	long int	start_time;

	start_time = 0;
	start_time = get_time();
	while ((get_time() - start_time) < time)
		usleep(time / 10);
}

static void	eat_action(t_philo *philo)
{
	pthread_mutex_lock(&philo->left_hand);
	print_status(TAKE_FORK, philo->id, philo);
	if (!philo->right_hand)
	{
		ft_sleep(philo->args->time_to_die * 2);
		return ;
	}
	pthread_mutex_lock(philo->right_hand);
	print_status(TAKE_FORK, philo->id, philo);
	print_status(EAT, philo->id, philo);
	ft_sleep(philo->args->time_to_eat);
	pthread_mutex_unlock(philo->right_hand);
	pthread_mutex_unlock(&philo->left_hand);
}

void	handler_action(t_philo *philo)
{
	eat_action(philo);
	print_status(SLEEP, philo->id, philo);
	ft_sleep(philo->args->time_to_sleep);
	print_status(THINK, philo->id, philo);
}
