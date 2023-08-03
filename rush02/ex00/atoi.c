/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   atoi.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgrootve <sgrootve@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/29 11:35:54 by sgrootve          #+#    #+#             */
/*   Updated: 2023/07/31 16:15:26 by sgrootve         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

unsigned int	is_integer(char c);

unsigned int	my_atoi(char *nb)
{
	unsigned int	sum;
	int				found[2];

	sum = 0;
	found[0] = 1;
	found[1] = 0;
	while (*nb == ' ' || *nb == '\t' || \
		*nb == '\n' || *nb == '\f' || *nb == '\r' || *nb == '\v' )
	{
		nb++;
		found[0] = 0;
		found[1] = 1;
	}
	while (*nb)
	{
		found[0] = 0;
		if (*nb >= '0' && *nb <= '9')
			sum = sum * 10 + *nb - '0';
		else
			return (-1);
		nb++;
	}
	if (found[0] == 1 || found[1] == 1)
		return (-1);
	return (sum);
}
