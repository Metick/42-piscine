/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ultimate_div_mod.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgrootve <sgrootve@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/13 11:35:05 by sgrootve          #+#    #+#             */
/*   Updated: 2023/07/17 12:38:38 by sgrootve         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

void	ft_ultimate_div_mod(int *a, int *b)
{
	int	tmp;

	tmp = *a;
	*a = *a / *b;
	*b = tmp % *b;
}

/*int main(void)
{
	int a;
	int b;

	a = 88;
	b = 10;
	ft_ultimate_div_mod(&a, &b);
	printf("a: %i b: %i\n", a, b);
	return (0);
}*/
