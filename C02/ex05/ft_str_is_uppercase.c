/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_is_uppercase.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgrootve <sgrootve@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/16 12:03:53 by sgrootve          #+#    #+#             */
/*   Updated: 2023/07/19 12:08:29 by sgrootve         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

int	ft_str_is_uppercase(char *str)
{
	int	len;

	len = 0;
	while (str[len] != 0)
	{
		if (str[len] >= 'A' && str[len] <= 'Z')
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
	int test = ft_str_is_uppercase("dhaudhwa");
	printf("%i\n", test);
	test = ft_str_is_uppercase("TEST");
	printf("%i\n", test);
	return (0);
}*/
