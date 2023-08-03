/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_is_numeric.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgrootve <sgrootve@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/16 11:55:38 by sgrootve          #+#    #+#             */
/*   Updated: 2023/07/19 12:45:45 by sgrootve         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

int	ft_str_is_numeric(char *str)
{
	int	len;

	len = 0;
	while (str[len] != 0)
	{
		if (str[len] >= '0' && str[len] <= '9')
		{
		}
		else
		{
			return (0);
		}
		len++;
	}
	return (1);
}

/*int main(void)
{
	int test = ft_str_is_numeric("927248");
	printf("%i\n", test);
	test = ft_str_is_numeric("te31231St");
	printf("%i\n", test);
	return (0);
}*/
