/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcapitalize.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgrootve <sgrootve@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/16 12:36:30 by sgrootve          #+#    #+#             */
/*   Updated: 2023/07/20 13:43:22 by sgrootve         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

int	is_lower_case_alphabet(char c)
{
	if (c >= 'a' && c <= 'z')
		return (1);
	return (0);
}

int	is_upper_case_alphabet(char c)
{
	if (c >= 'A' && c <= 'Z')
		return (1);
	return (0);
}

int	is_numeric_number(char c)
{
	if (c >= '0' && c <= '9')
		return (1);
	return (0);
}

int	is_special_character(char c)
{
	if (!is_numeric_number(c) 
		&& !is_upper_case_alphabet(c) 
		&& !is_lower_case_alphabet(c))
		return (1);
	return (0);
}

char	*ft_strcapitalize(char *str)
{
	int	len;
	int	capital;

	capital = 1;
	len = 0;
	while (str[len] != 0)
	{
		if (is_upper_case_alphabet(str[len]))
			str[len] = (str[len] + ('a' - 'A'));
		while (is_special_character(str[len]))
		{
			len++;
			capital = 1;
		}
		if (capital == 1)
		{
			if (is_lower_case_alphabet(str[len]))
				str[len] = (str[len] - ('a' - 'A'));
			capital = 0;
		}
		len++;
	}
	return (str);
}


int main(void)
{
	char test[] = "          salut,-comment tu vas ? 42mots quaRAnte-deux; cinquante+et+un";
	ft_strcapitalize(test);
	printf("str: %s\n", test);
	return (0);
}
