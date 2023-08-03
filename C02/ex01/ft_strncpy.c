/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgrootve <sgrootve@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/15 14:14:13 by sgrootve          #+#    #+#             */
/*   Updated: 2023/07/19 12:19:25 by sgrootve         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

char	*ft_strncpy(char *dest, char *src, unsigned int n)
{
	unsigned int	len;

	len = 0;
	while (src[len] != '\0' && len < n)
	{
		dest[len] = src[len];
		len++;
	}
	while (len < n)
	{
		dest[len] = '\0';
		len++;
	}
	return (dest);
}

/*int main(void)
{
	char str1[9] = "testtest";
	char str2[256];
	ft_strncpy(str2, str1, 5);

	printf("Old: %s new: %s", str1, str2);

	return (0);
}*/
