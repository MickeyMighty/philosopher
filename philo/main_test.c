/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_test.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: loamar <loamar@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/18 16:27:46 by loamar            #+#    #+#             */
/*   Updated: 2021/09/15 02:18:01 by loamar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void    *func1(void *arg)
{
    int     i;

    i = 0;
    while (i++ < 10)
    {
        // usleep(10000);
        printf("\033[91mthread 1: %s\033[0m\n", (char*)arg);
    }
    pthread_exit(arg);
}

void    *func2(void *arg)
{
    int     i;

    i = 0;
    while (i++ < 10)
    {
        // usleep(10000);
        printf("\033[95mthread 2: %s\033[0m\n", (char*)arg);
    }
    pthread_exit(arg);
}

int     main(int argc, char **argv)
{
    int     i;

    if (argc != 5)
        return (0);
    if (check_arg(argv))
    i = 0;
    pthread_t t1;
    pthread_t t2;

    pthread_create(&t1, NULL, func1, "hello 1");
    pthread_create(&t1, NULL, func2, "hello 2");

    char s1;
    char s2;
    pthread_join(t1, (void**)&s1);
    pthread_join(t2, (void**)&s2);
    return (0);
}
