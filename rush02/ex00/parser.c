/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgrootve <sgrootve@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/29 11:48:47 by sgrootve          #+#    #+#             */
/*   Updated: 2023/07/30 22:46:32 by sgrootve         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

typedef struct s_parsed
{
	char	*value;
	char	*letters;
}	t_parsed;

int			my_strlen(char *str);
int			is_integer(char c);
int			is_alpha(char c);
int			find_amount_lines(char *buf);
int			mem_s(char **ptr, int size, char *buf, int index);
t_parsed	*file_to_arr(char *buf);
void		my_memset(void *ptr, int value, int size);

t_parsed	*read_file(char *dictionary)
{
	int			file;
	int			bytes_read;
	char		buf[65535];
	t_parsed	*parsed;

	file = open(dictionary, O_RDONLY);
	if (file == -1)
		return (0);
	bytes_read = read(file, buf, sizeof(buf));
	parsed = file_to_arr(buf);
	if (close(file) < 0)
		return (0);
	return (parsed);
}

int	alloc_2(t_parsed *parsed, char *buf, int i[3])
{
	while (buf[i[1]] != '\0')
	{
		if (is_integer(buf[i[1]]) || is_alpha(buf[i[1]]))
			i[0]++;
		else if (buf[i[1]] == ':')
		{
			if (!mem_s(&parsed[i[2]].value, i[0], buf, i[1]))
				return (0);
			i[0] = 0;
		}
		else if (buf[i[1]] == '\n')
		{
			if (!mem_s(&parsed[i[2]].letters, i[0], buf, i[1]))
				return (0);
			if (i[0] != 0)
				i[2]++;
			i[0] = 0;
		}
		i[1]++;
	}
	return (1);
}

int	allocate_memory(t_parsed *parsed, char *buf)
{
	int	i[3];

	i[2] = 0;
	i[1] = 0;
	i[0] = 0;
	if (!alloc_2(parsed, buf, i))
		return (0);
	return (1);
}

t_parsed	*file_to_arr(char *buf)
{
	t_parsed	*parsed;

	parsed = (t_parsed *)malloc(sizeof(t_parsed)
			* (find_amount_lines(buf) + 1));
	if (!parsed)
		return (0);
	my_memset(&parsed[find_amount_lines(buf)], 0, sizeof(t_parsed *));
	if (!allocate_memory(parsed, buf))
		return (0);
	return (parsed);
}

void	free_parsed(t_parsed *parsed)
{
	int	index;

	index = 0;
	while (parsed[index].value != NULL)
	{
		free(parsed[index].value);
		free(parsed[index].letters);
		index++;
	}
	free(parsed);
}
