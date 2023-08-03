/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgrootve <sgrootve@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/26 15:34:01 by sgrootve          #+#    #+#             */
/*   Updated: 2023/08/02 17:24:20 by sgrootve         ###   ########.fr       */
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

int	get_total_size(char **strs, int size)
{
	int	index;
	int	total_len;
	int	len;

	index = 0;
	total_len = 0;
	while (index < size)
	{
		len = 0;
		while (strs[index][len] != '\0')
			len++;
		total_len += len;
		index++;
	}
	return (total_len);
}

int	add_str(char *str, char *final_str, int cur_len)
{
	int	index;

	index = 0;
	while (str[index] != '\0')
	{
		final_str[cur_len + index] = str[index];
		index++;
	}
	final_str[cur_len + index] = '\0';
	return (index);
}

char	*empty_str(void)
{
	char	*str;

	str = malloc(0);
	if (!str)
		return ("");
	str[0] = '\0';
	return (str);
}

char	*ft_strjoin(int size, char **strs, char *sep)
{
	char	*final_str;
	int		index;
	int		cur_len;

	final_str = (char *)malloc(sizeof(char) * (get_total_size(strs, size)
				+ (my_strlen(sep) * (size - 1))));
	if (!final_str)
		return (empty_str());
	index = 0;
	cur_len = 0;
	while (index < size)
	{
		cur_len += add_str(strs[index], final_str, cur_len);
		if (index != size - 1)
			cur_len += add_str(sep, final_str, cur_len);
		index++;
	}
	return (final_str);
}

/*int main(int argc, char *argv[])
{
	char* final_str = ft_strjoin(argc, argv, " and ");
	printf("%s\n", final_str);
	free(final_str);
}*/
