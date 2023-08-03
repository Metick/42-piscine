/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgrootve <sgrootve@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/14 14:42:05 by sgrootve          #+#    #+#             */
/*   Updated: 2023/07/19 16:25:44 by sgrootve         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

char	*ft_strcpy(char *dest, char *src)
{
	int	len;

	len = 0;
	while (src[len] != '\0')
	{
		dest[len] = src[len];
		len++;
	}
	dest[len] = '\0';
	return (dest);
}

/*int main(void)
{
	char str1[] = "testtest";
	char str2[256];
	ft_strcpy(str2, NULL);

	printf("Old: %s new: %s", str1, str2);

	return (0);
}*/
