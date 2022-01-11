/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: loamar <loamar@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/21 12:42:24 by loamar            #+#    #+#             */
/*   Updated: 2022/01/11 11:03:47 by loamar           ###   ########.fr       */
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
	int    		    		stop_time;
	int						nb_p_finish;
	int    		        	end;
	pthread_mutex_t     	mtx_write;
	pthread_mutex_t     	mtx_eat;
	pthread_mutex_t     	mtx_dead;
	pthread_mutex_t     	mtx_end;
	pthread_mutex_t     	mtx_finish;
}							t_argument;

typedef struct				s_philo
{
    int                	id;
    long int            eat_time;
    unsigned int        nbr_eat;
	long int			eat_in_ms;
    pthread_t           thread_philo;
    pthread_t           thread_death;;
    pthread_mutex_t     *right_hand;
    pthread_mutex_t     left_hand;
    t_argument          *args;
	int					finish;
}							t_philo;

typedef struct              s_data
{
    t_argument      arg;
    t_philo         *philo;
}							t_data;

// MAIN

void		print_status(int status, int id, t_philo *philo);

// THREADS

void 	*if_dead(void 	*lair_philo);
int     check_death(t_philo *philo, int key);
void 	*handler_threads(void *lair_philo);

// INIT

int	 			get_time(void);
int				init_philo(t_data *data);
int 			error_msg(char *msg);

// TOOLS

void	ft_putchar_fd(char c, int fd);
int     ft_isdigit(int c);
int     ft_atoi(const char *str);
void	ft_putnbr(int n);
void	ft_putstr_fd(char *s, int fd);

#endif
