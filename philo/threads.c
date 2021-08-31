/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   threads.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: loamar <loamar@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/25 19:43:26 by loamar            #+#    #+#             */
/*   Updated: 2021/08/31 04:39:03 by loamar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void    create_threads(t_data data)
{
    pthread_t   t_eat;
    pthread_t   t_sleep;
    pthread_t   t_think;
    pthread_t   t_die;

    pthread_create(&t_eat, NULL, action_eat, data);
    pthread_create(&t_sleep, NULL, action_sleep, data);
    pthread_create(&t_think, NULL, action_think, data);
    pthread_create(&t_die, NULL, action_die, data);
    // int     count;
    //
    // count = 1;
    // while (count <= data.nbr_philo)
    // {
    //     pthread_create(&)
    // }
}
