/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: loamar <loamar@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/21 12:26:26 by loamar            #+#    #+#             */
/*   Updated: 2021/08/23 14:37:33 by loamar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

pthread_mutex_t mutex = PTHREAD_MUTEX_INITIALIZER;

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

// static int  **malloc_each_philo(t_data data)
// {
//     int     philo[data.nbr_philo][3];
//     // int     pos;
//     // pos = 0;
//     // if (!(philo = (int**)malloc(sizeof(int*) * data.nbr_philo)))
//     //     return (0);
//     // while (pos < 3)
//     // {
//     //     if (!(philo[pos] = (int*)malloc(sizeof(int) * 3)))
//     //         return (0);
//     //     // memset(philo[pos], '0', 4*sizeof(int));
//     //     pos++;
//     // }
//     return (philo);
// }
// static int  **init_philo(t_data data)
// {
//     int     philo[data.nbr_philo][3];
//     int     pos;
//
//     pos = 0;
//     while (pos < data.nbr_philo)
//     {
//         philo[pos][0] = 0;
//         philo[pos][1] = 0;
//         philo[pos][2] = 0;
//         pos++;
//     }
//     return (philo);
// }

static void  start_philo(t_data data)
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

int         main(int argc, char **argv)
{
    t_data  data;

    if (argc != 5 || argc != 6)
        return (0);
    if (check_arg(argc, argv) == 1)
        return (0);
    data.nbr_philo = ft_atoi(argv[1]);
    data.time_to_die = ft_atoi(argv[2]);
    data.time_to_eat = ft_atoi(argv[3]);
    data.time_to_sleep = ft_atoi(argv[4]);
    if (argc == 6)
        data.eat_max = ft_atoi(argv[5il]);
    // philo = malloc_each_philo(philo);
    start_philo(data);
    return (0);
}
