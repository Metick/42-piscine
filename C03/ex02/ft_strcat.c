/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcat.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgrootve <sgrootve@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/21 11:22:59 by sgrootve          #+#    #+#             */
/*   Updated: 2023/07/21 11:28:37 by sgrootve         ###   ########.fr       */
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

char	*ft_strcat(char *dest, char *src)
{
	int	index;
	int	dest_len;

	dest_len = my_strlen(dest);
	index = 0;
	while (src[index] != '\0')
	{
		dest[dest_len + index] = src[index];
		index++;
	}
	dest[dest_len + index] = '\0';
	return (dest);
}

/*int	main(void)
{
	char dest[256];
	printf("%s\n", ft_strcat(dest, "test"));
	printf("%s\n", ft_strcat(dest, "test"));
	printf("%s\n", ft_strcat(dest, "test"));
	printf("%s\n", dest);
	return (0);
}*/
