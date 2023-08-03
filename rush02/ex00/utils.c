/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgrootve <sgrootve@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/29 11:28:32 by sgrootve          #+#    #+#             */
/*   Updated: 2023/07/30 21:52:38 by sgrootve         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	my_put_char(char c)
{
	write(1, &c, 1);
}

int	my_print_str(char *str)
{
	int	index;

	if (str == 0)
		return (0);
	index = 0;
	while (str[index] != '\0')
	{
		my_put_char(str[index]);
		index++;
	}
	return (1);
}

int	is_integer(char c)
{
	return ((c >= '0' && c <= '9'));
}

int	is_alpha(char c)
{
	return ((c >= 'A' && c <= 'Z') || (c >= 'a' && c <= 'z'));
}

int	my_strlen(char *str)
{
	int	len;

	len = 0;
	while (str[len] != '\0')
		len++;
	return (len);
}
