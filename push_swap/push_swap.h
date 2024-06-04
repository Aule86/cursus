/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aszamora <aszamora@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/09 12:07:13 by aszamora          #+#    #+#             */
/*   Updated: 2024/06/04 12:14:27 by aszamora         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
# include <stddef.h>
# include <stdlib.h>
# include "libft/libft.h"
# include <stdio.h>

typedef struct s_stack
{
	int				nbr;
	long			index;
	struct s_stack	*next;
	struct s_stack	*prev;
}	t_stack;

t_stack	*ft_process(int argc, char **argv);
t_stack	*ft_sub_process(char **argv);
int		ft_atol(const char *str, t_stack *stack);
void	ft_add_back(t_stack **stack, t_stack *new_stack);
t_stack	*ft_new_stack(int content);
void	ft_freestr(char **lst);
void	ft_error(t_stack *stack);
void	ft_free(t_stack **lst);
int		ft_case_rarb(t_stack *a, t_stack *b, int c);
int		ft_case_rrarrb(t_stack *a, t_stack *b, int c);
int		ft_case_rrarb(t_stack *a, t_stack *b, int c);
int		ft_case_rarrb(t_stack *a, t_stack *b, int c);
int		ft_case_rarb_a(t_stack *a, t_stack *b, int c);
int		ft_case_rrarrb_a(t_stack *a, t_stack *b, int c);
int		ft_case_rarrb_a(t_stack *a, t_stack *b, int c);
int		ft_case_rrarb_a(t_stack *a, t_stack *b, int c);
int		ft_checksorted(t_stack *stack_a);
int		ft_checkdup(t_stack *a);
int		ft_find_index(t_stack *a, int nbr);
int		ft_find_place_b(t_stack *stack_b, int nbr_push);
int		ft_find_place_a(t_stack *stack_a, int nbr_push);
int		ft_rotate_type_ba(t_stack *a, t_stack *b);
int		ft_rotate_type_ab(t_stack *a, t_stack *b);
int		ft_apply_rarb(t_stack **a, t_stack **b, int c, char s);
int		ft_apply_rrarrb(t_stack **a, t_stack **b, int c, char s);
int		ft_apply_rrarb(t_stack **a, t_stack **b, int c, char s);
int		ft_apply_rarrb(t_stack **a, t_stack **b, int c, char s);
void	ft_sort_b_till_3(t_stack **stack_a, t_stack **stack_b);
t_stack	*ft_sort_b(t_stack **stack_a);
t_stack	**ft_sort_a(t_stack **stack_a, t_stack **stack_b);
void	ft_sort_three(t_stack **stack_a);
void	ft_sort(t_stack **stack_a);
void	ft_ra(t_stack **a, int j);
void	ft_sa(t_stack **a, int j);
void	ft_pa(t_stack **a, t_stack **b, int j);
void	ft_rra(t_stack **a, int j);
void	ft_ss(t_stack **a, t_stack **b, int j);
void	ft_rr(t_stack **a, t_stack **b, int j);
void	ft_pb(t_stack **stack_a, t_stack **stack_b, int j);
void	ft_rrb(t_stack **b, int j);
void	ft_rrr_sub(t_stack **b, int j);
void	ft_rrr(t_stack **a, t_stack **b, int j);
void	ft_rb(t_stack **b, int j);
void	ft_sb(t_stack **b, int j);
t_stack	*ft_lstlast(t_stack *lst);
int		ft_lstsize(t_stack *lst);
int		ft_min(t_stack *a);
int		ft_max(t_stack *a);

#endif
