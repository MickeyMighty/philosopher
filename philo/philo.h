/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: loamar <loamar@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/21 12:42:24 by loamar            #+#    #+#             */
/*   Updated: 2021/10/04 15:28:22 by loamar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <sys/time.h>
#include <pthread.h>

# define SUCCESS 0
# define ERROR -1
# define EAT 2
# define TAKE_FORK 3
# define SLEEP 4
# define THINK 5
# define DEAD 6

typedef struct				s_argument
{
  int     				    nbr_philo;
  int      				    time_to_die;
  int      				    time_to_eat;
  int    	  			    time_to_sleep;
  int    		   		    eat_max;
	long int    		    start_time;
	long int    		    stop_time;
	int    		          end;
	pthread_mutex_t     mtx_write;
	pthread_mutex_t     mtx_eat;
	pthread_mutex_t     mtx_dead;
	pthread_mutex_t     mtx_end;
}							t_argument;


typedef struct				s_philo
{
    int                	id;
    long int            eat_time;
    unsigned int        nbr_eat;
    pthread_t           thread_philo;
    pthread_t           thread_death;
    pthread_mutex_t     *right_hand;
    pthread_mutex_t     left_hand;
    t_argument          *args;     
}							t_philo;

typedef struct              s_data
{
    t_argument      arg;
    t_philo         *philo;
}							t_data;

// MAIN

void		print_status(int status, int id);

// THREADS

int    create_threads(t_data *data);

// INIT

int				init_philo(t_data *data);
int 			error_msg(char *msg);

// TOOLS

void	ft_putchar_fd(char c, int fd);
int     ft_isdigit(int c);
int     ft_atoi(const char *str);
void	ft_putnbr(int n);
void	ft_putstr_fd(char *s, int fd);

#endif
