/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_non_printable.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgrootve <sgrootve@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/19 12:22:06 by sgrootve          #+#    #+#             */
/*   Updated: 2023/07/19 16:26:19 by sgrootve         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>

int	is_case_alphabet(char c)
{
	if (c >= ' ' && c <= 0x7F)
		return (1);
	return (0);
}

char	dec_to_hex(char c)
{
	if (c >= 10)
		return ((c - 10) + 'a');
	else if (c > 0 && c < 10) 
		return ('0' + c);
	else
		return ('0');
}

void	ft_putstr_non_printable(char *str)
{
	char	hex[3];
	int		len;

	len = 0;
	while (str[len] != '\0')
	{
		if (is_case_alphabet(str[len]))
		{
			write(1, &str[len], 1);
		}
		else
		{
			hex[0] = dec_to_hex((unsigned char)str[len] / 16);
			hex[1] = dec_to_hex((unsigned char)str[len] % 16);
			hex[2] = '\\';
			write(1, &hex[2], 1);
			write(1, &hex[0], 1);
			write(1, &hex[1], 1);
		}
		len++;
	}
}

/*int	main(void)
{
	ft_putstr_non_printable("Coucou\ntu vas bien ?\x99");
	printf("\n");
	return (0);
}*/
