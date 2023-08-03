/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgrootve <sgrootve@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/16 13:37:55 by sgrootve          #+#    #+#             */
/*   Updated: 2023/07/19 16:26:13 by sgrootve         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

unsigned int	my_strlen(char	*str)
{
	unsigned int	len;

	len = 0;
	while (str[len] != '\0')
	{
		len++;
	}
	return (len);
}

unsigned int	ft_strlcpy(char *dest, char *src, unsigned int size)
{
	unsigned int	len;
	unsigned int	string_size;

	string_size = my_strlen(src);
	len = 0;
	while (len < string_size && len < size - 1)
	{
		dest[len] = src[len];
		len++;
	}
	if (size != 0)
		dest[len] = '\0';
	return (string_size);
}

/*int main(void)
{
	char str1[9] = "testtest";
	char str2[256];
	ft_strlcpy(str2, str1, 10);

	printf("Old: %s new: %s", str1, str2);

	return (0);
}*/
