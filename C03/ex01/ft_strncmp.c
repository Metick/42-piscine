/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgrootve <sgrootve@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/21 11:19:13 by sgrootve          #+#    #+#             */
/*   Updated: 2023/07/24 12:05:41 by sgrootve         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

int	ft_strncmp(char *s1, char *s2, unsigned int n)
{
	unsigned int	len;

	len = 0;
	while (len < n && (s1[len] != '\0' || s2[len] != '\0'))
	{
		if (s1[len] != s2[len])
			return ((unsigned char)s1[len] - (unsigned char)s2[len]);
		len++;
	}
	return (0);
}

/*int main(void)
{
	printf("%i\n", ft_strncmp("\20", "\0", 1));
	return (0);
}*/
