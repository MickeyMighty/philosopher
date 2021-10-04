/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   action.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: loamar <loamar@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/31 01:49:44 by loamar            #+#    #+#             */
/*   Updated: 2021/10/04 15:29:36 by loamar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	ft_sleep(long int time)
{
	long int	start_time;

	start = 0;
	start = get_time();
	while ((get_time() - start_time) < time)
		usleep(time / 10);
}

void 		handler_action(t_philo *philo)
{
	;
}
