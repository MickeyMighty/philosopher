/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: loamar <loamar@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/21 12:42:24 by loamar            #+#    #+#             */
/*   Updated: 2021/09/15 02:21:51 by loamar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <pthread.h>

# define EAT 1
# define TAKE_FORK 2
# define SLEEP 3
# define THINK 4
# define DEAD 5

typedef struct				s_argument
{
    int     nbr_philo;
    int     time_to_die;
    int     time_to_eat;
    int     time_to_sleep;
    int     eat_max;
}							t_argument;


typedef struct				s_philo
{
    int                 nbr;
    pthread_t           thread_id;
    pthread_mutex_t     right_hand;
    pthread_mutex_t     left_hand;
}							t_philo;

typedef struct              s_data
{
    t_argument      arg;
    t_philo         *philo;
}

// MAIN
void print_status(int status, int id);

// TOOLS
void	ft_putchar(char c);
int     ft_isdigit(int c);
int     ft_atoi(const char *str);
void	ft_putnbr(int n);
void	ft_putstr_fd(char *s, int fd);

#endif
