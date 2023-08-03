/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgrootve <sgrootve@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/19 18:05:38 by sgrootve          #+#    #+#             */
/*   Updated: 2023/07/27 12:16:43 by sgrootve         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

int	f_num(char str, char *base, int why)
{
	int	len;

	len = 0;
	if (why == 1)
	{
		while (base[len] != '\0')
		{
			if (base[len] == str)
				return (len);
			len++;
		}
	}
	else
	{
		while (base[len] != '\0')
		{
			if (base[len] == str)
				return (1);
			len++;
		}
	}
	return (0);
}

int	get_negative(char *str, char *base)
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
		else if (f_num(str[len], base, 0))
			break ;
		len++;
	}
	return (negative);
}

int	check_str(char *str, char *base)
{
	int	len;
	int	found_whitespace;

	len = 0;
	found_whitespace = 0;
	while (str[len] != '\0')
	{
		if (str[len] == ' ' || str[len] == '\t' || str[len] == '\n' 
			|| str[len] == '\v' || str[len] == '\f' || str[len] == '\r')
		{
			if (found_whitespace)
				return (-1);
		}
		else if (str[len] == '-' || str[len] == '+')
			found_whitespace = 1;
		else if (f_num(str[len], base, 0))
			return (len);
		else
			return (-1);
		len++;
	}
	return (len);
}

int	atoi_base(char *str, char *base, int base_len)
{
	int	begin;
	int	total_number;
	int	negative;

	begin = check_str(str, base);
	if (begin == -1)
		return (0);
	total_number = 0;
	while (str[begin] != '\0')
	{
		if (f_num(str[begin], base, 0))
			total_number = (total_number * base_len) + 
				f_num(str[begin], base, 1);
		else
			break ;
		begin++;
	}
	negative = get_negative(str, base);
	if (negative % 2 == 1 && negative != 0)
		total_number = -total_number;
	return (total_number);
}

int	ft_atoi_base(char *str, char *base)
{
	int	len;
	int	index;

	if (base == 0)
		return (0);
	len = 0;
	while (base[len] != '\0')
	{
		index = len + 1;
		while (base[index] != '\0')
		{
			if (base[len] == base[index])
				return (0);
			index++;
		}
		if (base[len] == '+' || base[len] == '-')
			return (0);
		len++;
	}
	if (len <= 1)
		return (0);
	return (atoi_base(str, base, len));
}

int main(void)
{
	printf("%i\n", ft_atoi_base("     --- FF", "0123456789ABCDEF"));
	printf("%i\n", ft_atoi_base(" ++++--- FF", "0123456789ABCDEF"));
	printf("%i\n", ft_atoi_base(" ++++---aFF", "0123456789ABCDEF"));
	printf("%i\n", ft_atoi_base("  - ---FF", "0123456789ABCDEF"));
	printf("%i\n", ft_atoi_base("     ++---FF", "0123456789ABCDEF"));
	printf("%i\n", ft_atoi_base("-1101", "01"));
	printf("%i\n", ft_atoi_base("5000", "0123456789"));
	printf("%i\n", ft_atoi_base("50a00", "0123456789"));
	printf("%i\n", ft_atoi_base("---++++++500 0", "0123456789"));
	return (0);
}
