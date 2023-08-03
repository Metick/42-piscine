/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_is_alpha.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgrootve <sgrootve@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/15 17:55:19 by sgrootve          #+#    #+#             */
/*   Updated: 2023/07/20 13:41:25 by sgrootve         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

int	ft_str_is_alpha(char *str)
{
	int	len;
	int	is_alpha;

	is_alpha = 0;
	len = 0;
	while (str[len] != 0)
	{
		if ((str[len] >= 'A' && str[len] <= 'Z')
			|| (str[len] >= 'a' && str[len] <= 'z'))
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
	int test = ft_str_is_alpha("teSt[");
	printf("%i\n", test);
	test = ft_str_is_alpha("teSt");
	printf("%i\n", test);
	return (0);
}*/
