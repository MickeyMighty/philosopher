/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: loamar <loamar@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/21 12:42:24 by loamar            #+#    #+#             */
/*   Updated: 2021/08/21 13:26:52 by loamar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <pthread.h>

typedef struct				s_data
{
    int     nbr_philo;
    int     time_to_die;
    int     time_to_eat;
    int     time_to_sleep;
}							t_data;

int     ft_isdigit(int c);
int     ft_atoi(const char *str);

#endif
