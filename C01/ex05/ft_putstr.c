/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgrootve <sgrootve@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/13 11:38:06 by sgrootve          #+#    #+#             */
/*   Updated: 2023/07/17 12:39:00 by sgrootve         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
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

void	ft_putstr(char *str)
{
	write(1, str, my_strlen(str));
}

/*int main(void)
{
	ft_putstr("testing a string\n");
	return (0);
}*/
