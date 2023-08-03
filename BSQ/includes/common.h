/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   common.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgrootve <sgrootve@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/31 12:31:33 by sgrootve          #+#    #+#             */
/*   Updated: 2023/08/02 15:55:02 by sgrootve         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef COMMON_H
# define COMMON_H
# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>
# include <stdio.h>

/*Data types*/
typedef enum BOOL
{
	FALSE,
	TRUE 
}	t_bool;

/*Structs*/
typedef struct s_map_info
{
	char	empty;
	char	obstacle;
	char	filled_in;
	int		column_size;
	int		row_size;
}	t_map_info;

typedef struct s_map_file
{
	t_map_info	info;
	char		**grid;
}	t_map_file;

typedef struct s_bsq_info
{
	int	row;
	int	column;
	int	size;
}	t_bsq_info;

/* File.c */
t_bool			close_file(int file);
t_bool			read_file(int file, char *buf, int size);
int				open_file(char *given_file);

/* Map.c */
t_bool			create_map(t_map_file **map, int column_size, int row_size);
void			free_map(t_map_file *map);

/* Parser.c */
t_bool			parse_file(t_map_file **file_strct, char *buffer);
int				count_chars(char *buffer);

/* Utils.c */
char			*my_strncpy(char **dest, char *src, int size);
int				my_print_str(char *str);
void			exit_program(void);
int				my_atoi(char *nb);
void			my_put_char(char c);

/* Logic.c*/
t_bool			permutations(t_map_file *map);

/* Buffer.c */
unsigned long	calc_total_buffer(char *map_buffr);

/* Print.c */
t_bool			print(t_map_file *map, t_bsq_info *bsq);

#endif