/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   action.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: loamar <loamar@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/31 01:49:44 by loamar            #+#    #+#             */
/*   Updated: 2021/10/01 14:35:38 by loamar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

long int	ft_sleep(long int time)
{
	long int	start_time;

	start = 0;
	start = get_time();
	while ((get_time() - start_time) < time)
		usleep(time / 10);
}
