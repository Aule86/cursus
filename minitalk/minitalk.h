/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aszamora <aszamora@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/20 12:57:38 by aszamora          #+#    #+#             */
/*   Updated: 2024/03/04 11:50:51 by aszamora         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINITALK_H
# define MINITALK_H
# include <unistd.h>
# include <signal.h>
# include <stdarg.h>
# include "printf/ft_printf.h"

int		ft_client(int ac, char **av);
void	text_binary(int pid, char c);
int		ft_atoi(const char *str);
int		ft_server(void);
void	get_pid(void);
void	binary_text(int signum);

#endif