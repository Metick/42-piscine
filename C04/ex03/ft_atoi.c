/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgrootve <sgrootve@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/19 14:18:16 by sgrootve          #+#    #+#             */
/*   Updated: 2023/07/27 13:55:31 by sgrootve         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int	is_integer(char c)
{
	if (c >= '0' && c <= '9')
		return (1);
	return (0);
}

int	my_isspace(char c)
{
	if (c == ' ' || c == '\t' || c == '\n' 
		|| c == '\v' || c == '\f' || c == '\r')
		return (1);
	return (0);
}

int	get_negative(char *str)
{
	int	len;
	int	negative;

	negative = 0;
	len = 0;
	while (str[len] != '\0')
	{
		if (str[len] == '-' || str[len] == '+')
		{
			if (str[len] == '-')
				negative++;
		}
		else if (is_integer(str[len]))
			break ;
		len++;
	}
	return (negative);
}

int	check_str(char *str)
{
	int	len;
	int	found_whitespace;

	len = 0;
	found_whitespace = 0;
	while (str[len] != '\0')
	{
		if (my_isspace(str[len]))
		{
			if (found_whitespace)
				return (-1);
		}
		else if (str[len] == '-' || str[len] == '+')
			found_whitespace = 1;
		else if (is_integer(str[len]))
			return (len);
		else
			return (-1);
		len++;
	}
	return (len);
}

int	ft_atoi(char *str)
{
	int	begin;
	int	total_number;
	int	negative;

	begin = check_str(str);
	if (begin == -1)
		return (0);
	total_number = 0;
	while (str[begin] != '\0')
	{
		if (is_integer(str[begin]))
			total_number = (total_number * 10) + (str[begin] - '0');
		else
			break ;
		begin++;
	}
	negative = get_negative(str);
	if (negative % 2 == 1 && negative != 0)
		total_number = -total_number;
	return (total_number);
}

int	main(void)
{
	printf("%i\n", ft_atoi("2147483647"));
	printf("%i\n", ft_atoi("-2147483647"));
	printf("%i\n", ft_atoi("214 7483647"));
	printf("%i\n", ft_atoi("   2147c483647"));
	printf("%i\n", ft_atoi("    ---+++- 2147483647"));
	printf("%i\n", ft_atoi("    ---++ a2147483647"));
	printf("%i\n", ft_atoi("    ---++++++++2147483647"));
	printf("%i\n", ft_atoi("    ---++a2147483647"));
	printf("%i\n", ft_atoi("    2147483647"));
	return (0);
}
