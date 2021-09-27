/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   threads.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: loamar <loamar@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/25 19:43:26 by loamar            #+#    #+#             */
/*   Updated: 2021/09/22 19:00:17 by loamar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

// void 	handler_threads(t_data data)
// {
// 	;
// }

int    create_threads(t_data *data)
{
    int     count;

    count = 0;
    while (count < data->arg.nbr_philo)
    {
        // data->philo[count].id = count + 1;
        // if (pthread_create(&data->philo[count].thread_id, NULL, handler_action,) != 0)
        //     return (error_msg("Error : Pthread_create\n"));
        count++;
    }
	return (SUCCESS);
}
