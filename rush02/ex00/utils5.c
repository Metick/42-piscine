/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils5.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgrootve <sgrootve@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/30 19:28:30 by sgrootve          #+#    #+#             */
/*   Updated: 2023/07/30 22:49:15 by sgrootve         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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

typedef struct s_parsed
{
	char	*value;
	char	*letters;
}	t_parsed;

int				my_print_str(char *str);
char			*get_word_from_dict(unsigned int value, t_parsed *data);
unsigned int	my_atoi(char *nb);
int				billion(t_integers *integers, t_parsed *data);
int				hun_million(t_integers *integers, t_parsed *data);
int				ten_million(t_integers *integers, t_parsed *data);
int				million(t_integers *integers, t_parsed *data);
int				hun_thousand(t_integers *integers, t_parsed *data);
int				ten_thousand(t_integers *integers, t_parsed *data);
int				thousand(t_integers *integers, t_parsed *data);

int	ten_thousand_2(t_integers *integers, t_parsed *data)
{
	if (integers->thousand > 0 && integers->thousand < 10
		&& integers->ten_thousand == 10)
	{
		if (!my_print_str(get_word_from_dict(integers->ten_thousand
					+ integers->thousand, data)))
			return (0);
		integers->thousand = 0;
	}
	else
		if (!my_print_str(get_word_from_dict(integers->ten_thousand, data)))
			return (0);
	my_print_str(" ");
	return (1);
}

t_integers	init_integers(unsigned int value)
{
	t_integers	integers;

	integers.billions = value / 1000000000;
	integers.hun_million = ((value / 100000000) % 10);
	integers.ten_millions = ((value / 10000000) % 10);
	integers.millions = ((value / 1000000) % 10);
	integers.hun_thousand = ((value / 100000) % 10);
	integers.ten_thousand = ((value / 10000) % 10);
	integers.thousand = ((value / 1000) % 10);
	integers.hundred = ((value / 100) % 10);
	integers.ten = (((value / 10) % 10) * 10);
	integers.digit = value % 10;
	return (integers);
}

int	digits(t_integers *integers, t_parsed *data)
{
	if (integers->ten > 0)
	{
		if (!my_print_str(get_word_from_dict(integers->ten, data)))
			return (0);
		my_print_str(" ");
	}
	if (integers->digit > 0)
		if (!my_print_str(get_word_from_dict(integers->digit, data)))
			return (0);
	if (!integers->ten && !integers->hundred && !integers->thousand
		&& !integers->ten_thousand && !integers->hun_thousand 
		&& !integers->millions && !integers->ten_millions 
		&& !integers->hun_million && !integers->billions)
	{
		if (integers->digit == 0)
			if (!my_print_str(get_word_from_dict(integers->digit, data)))
				return (0);
	}
	return (1);
}

int	hundred(t_integers *integers, t_parsed *data)
{
	if (integers->hundred > 0)
	{
		if (!my_print_str(get_word_from_dict(integers->hundred, data)))
			return (0);
		my_print_str(" ");
		if (!my_print_str(get_word_from_dict(100, data)))
			return (0);
		my_print_str(" ");
	}
	if (integers->ten == 10 && integers->digit > 0)
	{
		integers->ten += integers->digit;
		if (!my_print_str(get_word_from_dict(integers->ten, data)))
			return (0);
		my_print_str(" ");
	}
	else 
	{
		if (!digits(integers, data))
			return (0);
	}
	return (1);
}

int	calc_num_to_word(t_integers integers, t_parsed *data)
{
	if (integers.billions > 0)
		if (!billion(&integers, data))
			return (0);
	if (integers.hun_million > 0)
		if (!hun_million(&integers, data))
			return (0);
	if (integers.ten_millions > 0)
		if (!ten_million(&integers, data))
			return (0);
	if (integers.millions > 0)
		if (!million(&integers, data))
			return (0);
	if (integers.hun_thousand > 0)
		if (!hun_thousand(&integers, data))
			return (0);
	if (integers.ten_thousand > 0)
		if (!ten_thousand(&integers, data))
			return (0);
	if (integers.thousand > 0)
		if (!thousand(&integers, data))
			return (0);
	if (!hundred(&integers, data))
		return (0);
	return (1);
}
