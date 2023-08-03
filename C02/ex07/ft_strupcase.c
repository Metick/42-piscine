/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strupcase.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgrootve <sgrootve@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/16 12:19:26 by sgrootve          #+#    #+#             */
/*   Updated: 2023/07/19 12:04:55 by sgrootve         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

char	*ft_strupcase(char *str)
{
	int	len;

	len = 0;
	while (str[len] != 0)
	{
		if (str[len] >= 'a' && str[len] <= 'z')
			str[len] = (str[len] - ('a' - 'A'));
		len++;
	}
	return (str);
}

/*int	main(void)
{
	char test[] = "test";
	ft_strupcase(test);
	printf("str: %s\n", test);
	return (0);
}*/
