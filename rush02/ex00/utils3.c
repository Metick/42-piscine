/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils3.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgrootve <sgrootve@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/30 19:10:06 by sgrootve          #+#    #+#             */
/*   Updated: 2023/07/30 22:40:51 by sgrootve         ###   ########.fr       */
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

int				my_print_str(char *str);
char			*get_word_from_dict(unsigned int value, t_parsed *data);
unsigned int	my_atoi(char *nb);

int	ten_million_1(t_integers *integers, t_parsed *data)
{
	if (integers->millions > 0 && integers->millions < 10
		&& integers->ten_millions == 10)
	{
		if (!my_print_str(get_word_from_dict(integers->ten_millions
					+ integers->millions, data)))
			return (0);
		integers->millions = 0;
	}
	else
		if (!my_print_str(get_word_from_dict(integers->ten_millions, data)))
			return (0);
	my_print_str(" ");
	return (1);
}

int	ten_million_2(t_integers *integers, t_parsed *data)
{
	if (integers->ten_millions > 10 && integers->ten_millions < 19)
	{
		if (!my_print_str(get_word_from_dict(integers->ten_millions, data)))
			return (0);
	}
	else if (integers->ten_millions - (integers->ten_millions % 10))
	{
		if (!my_print_str(get_word_from_dict(integers->ten_millions
					- (integers->ten_millions % 10), data)))
			return (0);
		if (integers->ten_millions % 10)
		{
			my_print_str(" ");
			if (!my_print_str(get_word_from_dict(integers->ten_millions % 10,
						data)))
				return (0);
		}
	}
	else
		if (!my_print_str(get_word_from_dict(integers->ten_millions % 10,
					data)))
			return (0);
	my_print_str(" ");
	return (1);
}

int	ten_million(t_integers *integers, t_parsed *data)
{
	integers->ten_millions *= 10;
	if (integers->ten_millions % 10 == 0)
	{
		if (!ten_million_1(integers, data))
			return (0);
	}
	else
	{
		if (!ten_million_2(integers, data))
			return (0);
	}
	if (integers->millions == 0)
	{
		if (!my_print_str(get_word_from_dict(1000000, data)))
			return (0);
		my_print_str(" ");
	}
	return (1);
}

int	million_1(t_integers *integers, t_parsed *data)
{
	if (integers->millions > 10 && integers->millions < 19)
	{
		if (!my_print_str(get_word_from_dict(integers->millions, data)))
			return (0);
	}
	else if (integers->millions - (integers->millions % 10))
	{
		if (!my_print_str(get_word_from_dict(integers->millions
					- (integers->millions % 10), data)))
			return (0);
		if (integers->millions % 10)
		{
			my_print_str(" ");
			if (!my_print_str(get_word_from_dict(integers->millions % 10,
						data)))
				return (0);
		}
	}
	else
		if (!my_print_str(get_word_from_dict(integers->millions % 10, data)))
			return (0);
	my_print_str(" ");
	return (1);
}

int	million(t_integers *integers, t_parsed *data)
{
	if (integers->millions % 10 == 0)
	{
		if (!my_print_str(get_word_from_dict(integers->millions, data)))
			return (0);
		my_print_str(" ");
	}
	else
	{
		if (!million_1(integers, data))
			return (0);
	}
	if (!my_print_str(get_word_from_dict(1000000, data)))
		return (0);
	my_print_str(" ");
	return (1);
}
