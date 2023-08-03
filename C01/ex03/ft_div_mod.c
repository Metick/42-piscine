/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_div_mod.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgrootve <sgrootve@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/13 11:29:58 by sgrootve          #+#    #+#             */
/*   Updated: 2023/07/17 12:38:20 by sgrootve         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

void	ft_div_mod(int a, int b, int *div, int *mod)
{
	*div = a / b;
	*mod = a % b;
}

/*int main(void)
{
	int a = 88;
	int b = 10;
	int div;
	int mod;

	ft_div_mod(a, b, &div, &mod);
	printf("div: %i mod %i\n", div, mod);
	return (0);
}*/
