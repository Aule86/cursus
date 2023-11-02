/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aszamora <aszamora@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/09 15:35:02 by aszamora          #+#    #+#             */
/*   Updated: 2023/10/18 11:32:23 by aszamora         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <stddef.h>
# include <stdlib.h>
# include <stdio.h>
# include <stdarg.h>

int		ft_printf(const char *str, ...);
void	ft_onlychar(int c, int *r);
void	ft_putstr(char *s, int *r);
void	ft_putunbr(unsigned int n, int *r);
void	ft_puthexa(unsigned int n, const char str, int *r);
void	ft_adress(unsigned long int p, int *r);
void	ft_putnbr(int n, int *r);

#endif