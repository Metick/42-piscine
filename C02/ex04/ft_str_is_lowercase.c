/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_is_lowercase.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgrootve <sgrootve@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/16 12:01:35 by sgrootve          #+#    #+#             */
/*   Updated: 2023/07/19 12:09:22 by sgrootve         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

int	ft_str_is_lowercase(char *str)
{
	int	len;

	len = 0;
	while (str[len] != 0)
	{
		if (str[len] >= 'a' && str[len] <= 'z')
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
	int test = ft_str_is_lowercase("dhaudhwa");
	printf("%i\n", test);
	test = ft_str_is_lowercase("t1eSt");
	printf("%i\n", test);
	return (0);
}*/
