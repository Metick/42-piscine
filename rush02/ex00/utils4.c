/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils4.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgrootve <sgrootve@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/30 19:16:57 by sgrootve          #+#    #+#             */
/*   Updated: 2023/07/31 16:08:38 by sgrootve         ###   ########.fr       */
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
int				ten_thousand_2(t_integers *integers, t_parsed *data);

int	hun_thousand(t_integers *integers, t_parsed *data)
{
	if (!my_print_str(get_word_from_dict(integers->hun_thousand, data)))
		return (0);
	my_print_str(" ");
	if (!my_print_str(get_word_from_dict(100, data)))
		return (0);
	my_print_str(" ");
	if (integers->thousand % 10 == 0 && integers->ten_thousand % 10 == 0)
	{
		if (!my_print_str(get_word_from_dict(1000, data)))
			return (0);
		my_print_str(" ");
		integers->thousand = 0;
	}
	return (1);
}

int	ten_thousand_1(t_integers *integers, t_parsed *data)
{
	if (integers->ten_thousand > 10 && integers->ten_thousand < 19)
	{
		if (!my_print_str(get_word_from_dict(integers->ten_thousand, data)))
			return (0);
	}
	else if (integers->ten_thousand - (integers->ten_thousand % 10))
	{
		if (!my_print_str(get_word_from_dict(integers->ten_thousand
					- (integers->ten_thousand % 10), data)))
			return (0);
		if (integers->ten_thousand % 10)
		{
			my_print_str(" ");
			if (!my_print_str(get_word_from_dict(integers->ten_thousand % 10,
						data)))
				return (0);
		}
	}
	else
		if (!my_print_str(get_word_from_dict(integers->ten_thousand % 10,
					data)))
			return (0);
	my_print_str(" ");
	return (1);
}

int	ten_thousand(t_integers *integers, t_parsed *data)
{
	integers->ten_thousand *= 10;
	if (integers->ten_thousand % 10 == 0)
	{
		ten_thousand_2(integers, data);
	}
	else
		if (!ten_thousand_1(integers, data))
			return (0);
	if (integers->thousand == 0)
	{
		if (!my_print_str(get_word_from_dict(1000, data)))
			return (0);
		my_print_str(" ");
	}
	return (1);
}

54;
50 4 

int	thousand_1(t_integers *integers, t_parsed *data)
{
	if (integers->thousand > 10 && integers->thousand < 19)
	{
		if (!my_print_str(get_word_from_dict(integers->thousand, data)))
			return (0);
	}
	else if (integers->thousand - (integers->thousand % 10))
	{
		if (!my_print_str(get_word_from_dict(integers->thousand
					- (integers->thousand % 10), data)))
			return (0);
		if (integers->thousand % 10)
		{
			my_print_str(" ");
			if (!my_print_str(get_word_from_dict(integers->thousand % 10,
						data)))
				return (0);
		}
	}
	else
		if (!my_print_str(get_word_from_dict(integers->thousand % 10, data))) // 1 - 9
			return (0);
	my_print_str(" ");
	return (1);
}

int	thousand(t_integers *integers, t_parsed *data)
{
	if (integers->thousand % 10 == 0)
	{
		if (!my_print_str(get_word_from_dict(integers->thousand, data)))
			return (0);
		my_print_str(" ");
	}
	else
	{
		if (!thousand_1(integers, data))
			return (0);
	}
	if (!my_print_str(get_word_from_dict(1000, data)))
		return (0);
	my_print_str(" ");
	return (1);
}
