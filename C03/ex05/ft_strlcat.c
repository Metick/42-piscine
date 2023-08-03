/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgrootve <sgrootve@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/21 11:48:55 by sgrootve          #+#    #+#             */
/*   Updated: 2023/07/24 16:15:25 by sgrootve         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <string.h>

unsigned int	my_strlen(char *str)
{
	unsigned int	len;

	len = 0;
	while (str[len] != '\0')
		len++;
	return (len);
}

unsigned int	ft_strlcat(char *dest, char *src, unsigned int size)
{
	unsigned int	index;
	unsigned int	dest_len;
	unsigned int	src_len;

	dest_len = my_strlen(dest);
	src_len = my_strlen(src);
	if (size <= dest_len && dest_len != 0)
		return (dest_len + src_len);
	index = 0;
	while (index < (size - dest_len) - 1)
	{
		dest[dest_len + index] = src[index];
		index++;
	}
	return (dest_len + src_len);
}

/*int	main(void)
{
	char dest[256];
	unsigned int size = ft_strlcat(dest, "test", 5);
	printf("[%i] %s\n", size, dest);
	size = ft_strlcat(dest, "saddd", 7);
	printf("[%i] %s\n", size, dest);
	return (0);
}*/
