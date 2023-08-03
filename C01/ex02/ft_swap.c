/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_swap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgrootve <sgrootve@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/13 11:24:34 by sgrootve          #+#    #+#             */
/*   Updated: 2023/07/17 12:37:58 by sgrootve         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

void	ft_swap(int *a, int *b)
{
	int	tmp;

	tmp = *b;
	*b = *a;
	*a = tmp;
}

/*int	main(void)
{
	int a;
	int b;

	a = 5;
	b = 10;
	ft_swap(&a, &b);
	printf("a: %i b: %i\n", a, b);
	return (0);
}*/
