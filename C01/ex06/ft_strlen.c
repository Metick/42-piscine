/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgrootve <sgrootve@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/13 11:40:48 by sgrootve          #+#    #+#             */
/*   Updated: 2023/07/17 14:43:30 by sgrootve         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

int	my_strlen(char *str)
{
	int	len;

	len = 0;
	while (str[len] != 0)
	{
		len++;
	}
	return (len);
}

int	ft_strlen(char *str)
{
	return (my_strlen(str));
}

/*int main(void)
{
	int len = ft_strlen("testing a string length");
	printf("Lenght: %i\n", len);
	return (0);
}*/
