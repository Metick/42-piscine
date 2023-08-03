/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgrootve <sgrootve@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/29 16:34:47 by sgrootve          #+#    #+#             */
/*   Updated: 2023/07/30 22:30:07 by sgrootve         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

typedef struct s_parsed
{
	char	*value;
	char	*letters;
}	t_parsed;

typedef struct s_integers
{
	int	billions;
	int	hun_million;
	int	ten_millions;
	int	millions;
	int	hun_thousand;
	int	ten_thousand;
	int	thousand;
	int	hundred;
	int	ten;
	int	digit;
}	t_integers;

unsigned int	my_atoi(char *nb);
int				my_print_str(char *str);

void	my_memset(int *ptr, int value, int size)
{
	int	index;

	index = 0;
	while (index < size)
	{
		ptr[index] = (int)value;
		index++;
	}
}

int	ft_strcmp(char *s1, char *s2)
{
	int	len;

	len = 0;
	while (s1[len] != '\0' || s2[len] != '\0')
	{
		if (s1[len] != s2[len])
			return ((unsigned char)s1[len] - (unsigned char)s2[len]);
		len++;
	}
	return (0);
}

char	*get_word_from_dict(unsigned int value, t_parsed *data)
{
	int	index;

	index = 0;
	while (data[index].letters != 0)
	{
		if (my_atoi(data[index].value) == value)
		{
			return (data[index].letters);
		}
		index++;
	}
	return (0);
}

int	billion(t_integers *integers, t_parsed *data)
{
	if (!my_print_str(get_word_from_dict(integers->billions, data)))
		return (0);
	my_print_str(" ");
	if (!my_print_str(get_word_from_dict(1000000000, data)))
		return (0);
	my_print_str(" ");
	return (1);
}

int	hun_million(t_integers *integers, t_parsed *data)
{
	if (!my_print_str(get_word_from_dict(integers->hun_million, data)))
		return (0);
	my_print_str(" ");
	if (!my_print_str(get_word_from_dict(100, data)))
		return (0);
	my_print_str(" ");
	if ((integers->hun_million % 10 == 0 && integers->hun_million % 10 == 0)
		|| integers->ten_millions == 0)
	{
		if (!my_print_str(get_word_from_dict(1000000, data)))
			return (0);
		my_print_str(" ");
		integers->millions = 0;
	}
	return (1);
}
