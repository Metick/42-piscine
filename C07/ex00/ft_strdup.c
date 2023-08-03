/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgrootve <sgrootve@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/26 12:41:58 by sgrootve          #+#    #+#             */
/*   Updated: 2023/08/02 17:24:33 by sgrootve         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>

int	my_strlen(char *str)
{
	int	len;

	len = 0;
	while (str[len] != '\0')
		len++;
	return (len);
}

char	*ft_strdup(char *src)
{
	int		index;
	int		src_len;
	char	*tmp_src;

	src_len = my_strlen(src);
	tmp_src = malloc(sizeof(char) * src_len);
	if (!tmp_src)
		return (0);
	index = 0;
	while (src[index] != '\0')
	{
		tmp_src[index] = src[index];
		index++;
	}
	return (tmp_src);
}

/*int main(void)
{
	char *str = ft_strdup("testing this");
	printf("str: %s\n", str);
	free(str);
}*/