/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgrootve <sgrootve@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/21 11:39:14 by sgrootve          #+#    #+#             */
/*   Updated: 2023/07/24 12:16:50 by sgrootve         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

int	my_strlen(char *str)
{
	int	len;

	len = 0;
	while (str[len] != '\0')
		len++;
	return (len);
}

char	*ft_strstr(char *str, char *to_find)
{
	int	index;
	int	len;
	int	substr_len;

	if (to_find[0] == '\0')
		return (str);
	substr_len = my_strlen(to_find);
	len = 0;
	index = 0;
	while (str[index] != '\0')
	{
		if (str[index] == to_find[len])
			len++;
		else
			len = 0;
		if (substr_len == len)
			return (&str[(index - len) + 1]);
		index++;
	}
	return (0);
}

/*int main(void)
{
	printf("%s\n", ft_strstr("", "st"));
	return (0);
}*/
