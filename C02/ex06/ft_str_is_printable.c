/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_is_printable.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgrootve <sgrootve@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/16 12:06:55 by sgrootve          #+#    #+#             */
/*   Updated: 2023/07/19 15:29:31 by sgrootve         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

int	ft_str_is_printable(char *str)
{
	int	len;
	int	is_printable;

	is_printable = 1;
	len = 0;
	while (str[len] != 0)
	{
		if (str[len] >= ' ' && str[len] <= 0x7F)
		{
		}
		else
		{
			is_printable = 0;
		}
		len++;
	}
	return (is_printable);
}

/*int	main(void)
{
	int test = ft_str_is_printable("~!dhaudhwa");
	printf("%i\n", test);
	test = ft_str_is_printable("\n");
	printf("%i\n", test);
	return (0);
}*/
