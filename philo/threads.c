/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   threads.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: loamar <loamar@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/25 19:43:26 by loamar            #+#    #+#             */
/*   Updated: 2021/09/15 02:28:47 by loamar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void    create_threads(t_data data)
{
    int     count;

    count = 0;
    while (count < data.nbr_philo)
    {
        data.philo[count].nbr = count + 1;
        if (pthread_create(&data.philo[count].thread_id, NULL, handler_action,) != 0)
            return (error_msg("Error : Pthread_create\n"));
        count++;
    }
}
