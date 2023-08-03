/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgrootve <sgrootve@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/19 14:05:27 by sgrootve          #+#    #+#             */
/*   Updated: 2023/07/19 14:08:37 by sgrootve         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <unistd.h>

int	my_strlen(char *str)
{
	int	len;

	len = 0;
	while (str[len] != '\0')
		len++;
	return (len);
}

void	ft_putstr(char *str)
{
	int	len;
	int	index;

	len = my_strlen(str);
	index = 0;
	while (index < len)
	{
		write(1, &str[index], 1);
		index++;
	}
}

/*int	main(void)
{
	ft_putstr("Testing a string");
	return (0);
}*/
