/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_base.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgrootve <sgrootve@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/28 10:21:19 by sgrootve          #+#    #+#             */
/*   Updated: 2023/08/02 17:42:52 by sgrootve         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>

int	is_base(char c, char *base)
{
	int	index;

	index = 0;
	while (base[index] != '\0')
	{
		if (base[index] == c)
			return (index);
		index++;
	}
	return (-1);
}

int	my_strlen(char *str)
{
	int	len;

	len = 0;
	while (str[len] != '\0')
		len++;
	return (len);
}

void	int_to_char(char *ptr, int total_number, char *base_to, int info[3])
{
	int	info2[3];

	info2[0] = info[0] - 1;
	info2[1] = info[1];
	info2[2] = info[2];
	if (total_number / info[1])
	{
		int_to_char(ptr, total_number / info[1], base_to, info2);
		ptr[info[0]] = base_to[total_number % info[1]];
	}
	else
	{
		if (info[2] == -1)
			ptr[info[0] - 1] = '-';
		ptr[info[0]] = base_to[total_number];
	}
}

char	*idk_name_yet(int total_number, char *base_to, int neg)
{
	char	*new_number;
	int		temp_number;
	int		info[3];

	if (neg == -1)
		info[0] = 1;
	else
		info[0] = 0;
	info[2] = neg;
	temp_number = total_number;
	info[1] = my_strlen(base_to);
	while (temp_number / info[1])
	{
		temp_number /= info[1];
		info[0]++;
	}
	new_number = (char *)malloc(sizeof(char) * (info[0] ));
	if (!new_number)
		return (0);
	int_to_char(new_number, total_number, base_to, info);
	return (new_number);
}

char	*ft_convert_base(char *nbr, char *base_from, char *base_to)
{
	int		total_number;
	int		base_len;
	int		neg;

	while ((*nbr == '\t' || *nbr == '\n' || *nbr == '\v'
			|| *nbr == '\f' || *nbr == '\r' || *nbr == ' '))
		nbr++;
	neg = 1;
	while (*nbr == '-' || *nbr == '+')
	{
		if (*nbr == '-')
			neg *= -1;
		nbr++;
	}
	total_number = 0;
	base_len = my_strlen(base_from);
	while (is_base(*nbr, base_from) != -1)
	{
		total_number = (total_number * base_len) + is_base(*nbr, base_from);
		nbr++;
	}
	return (idk_name_yet(total_number, base_to, neg));
}

/*int main(void)
{
	printf("Final converted: %s\n", ft_convert_base("  
	 ---+++--101010", "01", "0123456789ABCDEF"));
	return (0);
}*/
