/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgrootve <sgrootve@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/21 11:29:33 by sgrootve          #+#    #+#             */
/*   Updated: 2023/07/21 12:40:22 by sgrootve         ###   ########.fr       */
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

char	*ft_strncat(char *dest, char *src, unsigned int nb)
{
	unsigned int	index;
	int				dest_len;

	dest_len = my_strlen(dest);
	index = 0;
	while (index < nb && (src[index] != '\0' || dest[index] != '\0'))
	{
		dest[dest_len + index] = src[index];
		index++;
	}
	dest[dest_len + index] = '\0';
	return (dest);
}

/*int	main(void)
{
	char	dest[256];
	printf("%s\n", ft_strncat(dest, "test", 0));
	printf("%s\n", ft_strncat(dest, "test", 1));
	printf("%s\n", ft_strncat(dest, "test", 3));
	return (0);
}*/
