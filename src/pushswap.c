/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pushswap.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rvaz-da- <rvaz-da-@student.42belgium.be>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/18 19:58:05 by rvaz-da-          #+#    #+#             */
/*   Updated: 2026/01/17 16:49:15 by rvaz-da-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../pushswap.h"

void	print_stack(t_stack *stack)
{
	t_node	*current;

	current = stack->head;
	while (current)
	{
		ft_printf("%d\n", current->value);
		current = current->next;
	}
	ft_printf("length: %d\n", stack->length);
}

int	main(int ac, char *av[])
{
	t_stack	stack_a;
	t_stack	stack_b;

	if (ac == 1)
		return (1);
	stack_b = (t_stack){NULL, NULL, 0};
	stack_a = make_stack(av, ac);
	if (!stack_a.head)
		return (1);
	ft_printf("stack a before: \n");
	print_stack(&stack_a);
	ft_printf("stack b before: \n");
	print_stack(&stack_b);
	ft_printf("\n\n");
	if (strictly_ascending(&stack_a))
		return (write(1, "Stack sorted\n", 12), 0);//free_stack(&stack_a, &stack_b);
	else
		sort_stack(&stack_a, &stack_b);
	ft_printf("\n\n");
	printf("stack a after: \n");
	print_stack(&stack_a);
	ft_printf("stack b after:\n");
	print_stack(&stack_b);
	free_stack(&stack_a);
	free_stack(&stack_b);
	return (0);
}
