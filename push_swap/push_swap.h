/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aule86 <aule86@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/25 13:06:48 by aszamora          #+#    #+#             */
/*   Updated: 2024/05/07 12:18:14 by aule86           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
# include <stddef.h>
# include <stdlib.h>
# include "../libft/libft.h"

typedef struct s_stack
{
	long			nbr;
	long			index;
	struct s_stack	*next;
	struct s_stack	*prev;
}	t_stack;

t_stack	*ft_process(int argc, char **argv);
t_stack	*ft_sub_process(char **argv);
int		ft_atol(const char *str);
void	ft_add_back(t_stack **stack, t_stack *new_stack);
t_stack	*ft_new_stack(int content);
void	ft_freestr(char **lst);
void	ft_error(void);
void	ft_free(t_stack **lst);


#endif
