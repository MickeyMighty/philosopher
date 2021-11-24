/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: loamar <loamar@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/21 12:26:26 by loamar            #+#    #+#             */
/*   Updated: 2021/10/04 14:15:10 by loamar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

pthread_mutex_t mutex = PTHREAD_MUTEX_INITIALIZER;

void 		print_status(int status, int id, int time_ms)
{
    ft_putnbr(time_ms);
    ft_putchar_fd(' ', 1);
    ft_putnbr(id);
    if (status == TAKE_FORK)
        ft_putstr_fd(" has taken a fork", 1);
    if (status == EAT)
        ft_putstr_fd(" is eating", 1);
    if (status == SLEEP)
        ft_putstr_fd(" is sleeping", 1);
    if (status == THINK)
        ft_putstr_fd(" is thinking", 1);
    if (status == DEAD)
        ft_putstr_fd(" died", 1);
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
                return (ERROR);
            letter++;
        }
        word++;
    }
    return (SUCCESS);
}

static int  start(t_data data)
{
	if (init_philo(&data) == ERROR);
        return (ERROR);
    // create_threads(&data);
	return (0);
	// handler_threads();
}

int            main(int argc, char **argv)
{
    t_data  data;

    data.arg.eat_max = 0;
    if (argc != 5 || argc != 6)
        return (error_msg("Error : Invalid Arguments"));
    if (check_arg(argc, argv) == ERROR)
        return (error_msg("Error : Invalid Arguments"));
    data.arg.nbr_philo = ft_atoi(argv[1]);
    data.arg.time_to_die = ft_atoi(argv[2]);
    data.arg.time_to_eat = ft_atoi(argv[3]);
    data.arg.time_to_sleep = ft_atoi(argv[4]);
    if (argc == 6)
        data.arg.eat_max = ft_atoi(argv[5]);
    if (data.arg.nbr_philo < 0 || data.arg.time_to_die < 0 || data.arg.time_to_eat < 0
    || data.arg.time_to_sleep < 0 || data.arg.eat_max < 0)
        return (error_msg("Error : Invalid Arguments"));
    data.philo = malloc(sizeof(t_philo) * data.arg.nbr_philo);
    if (!data.philo)
        return (error_msg("Error : Malloc (main.c - l.96)"));
    start(data);
    return (0);
}
