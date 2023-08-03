/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlowcase.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgrootve <sgrootve@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/16 12:34:58 by sgrootve          #+#    #+#             */
/*   Updated: 2023/07/19 12:04:22 by sgrootve         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

char	*ft_strlowcase(char *str)
{
	int	len;

	len = 0;
	while (str[len] != 0)
	{
		if (str[len] >= 'A' && str[len] <= 'Z')
			str[len] = (str[len] + ('a' - 'A'));
		len++;
	}
	return (str);
}

/*int	main(void)
{
	char test[] = "TeST";
	ft_strlowcase(test);
	printf("str: %s\n", test);
	return (0);
}*/
