/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: loamar <loamar@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/21 12:26:26 by loamar            #+#    #+#             */
/*   Updated: 2021/08/31 01:22:53 by loamar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

pthread_mutex_t mutex = PTHREAD_MUTEX_INITIALIZER;

void print_status(int status, int id)
{
    //print timestamp_in_ms
    ft_putnbr(id);
    if (status == TAKE_FORK)
        ft_putstr(" has taken a fork");
    if (status == EAT)
        ft_putstr("  is eating");
    if (status == SLEEP)
        ft_putstr(" is sleeping");
    if (status == THINK)
        ft_putstr("  is thinking");
    if (status == DEAD)
        ft_putstr(" died");
}

static int  check_arg(int argc, char **argv)
{
    int     letter;
    int     word;
    int     limit;

    limit = argc;
    letter = 0;
    word = 1;
    while (word < limit)
    {
        while (argv[word][letter] != 0)
        {
            if (ft_isdigit(argv[word][letter]) == 0)
                return (1);
            letter++;
        }
        word++;
    }
    return (0);
}

static void  start_philo(t_argument arg)
{
    int     philo[data.nbr_philo][3];
    int     pos;

    pos = 0;
    while (pos < data.nbr_philo)
    {
        philo[pos][0] = 0;
        philo[pos][1] = 0;
        philo[pos][2] = 0;
        pos++;
    }

    // philo = init_philo(data, philo);
}

int            main(int argc, char **argv)
{
    t_argument  arg;

    arg.eat_max = 0;
    if (argc != 5 || argc != 6)
        return (0);
    if (check_arg(argc, argv) == 1)
        return (0);
    arg.nbr_philo = ft_atoi(argv[1]);
    arg.time_to_die = ft_atoi(argv[2]);
    arg.time_to_eat = ft_atoi(argv[3]);
    arg.time_to_sleep = ft_atoi(argv[4]);
    if (argc == 6)
        arg.eat_max = ft_atoi(argv[5]);
    if (arg.nbr_philo < 0 || arg.time_to_die < 0 || arg.time_to_eat < 0
    || arg.time_to_sleep < 0 || arg.eat_max < 0)
        return (0);
    // philo = malloc_each_philo(philo);
    start_philo(arg);
    return (0);
}
