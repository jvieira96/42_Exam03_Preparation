/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpedro-f <jpedro-f@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/18 17:46:17 by jpedro-f          #+#    #+#             */
/*   Updated: 2025/04/07 13:04:23 by jpedro-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static char *join_char(char *line, char c, int len)
{
	char 	*new_str;
	int		i = 0;

	new_str = (char *)malloc(len + 2);
	if (!new_str)
		return (NULL);
	while (i < len)
	{
		new_str[i] = line[i];
		i++;
	}
	new_str[i] = c;
	i++;
	new_str[i] = '\0';
	free(line);
	return (new_str);
}

char *get_next_line(int fd)  
{
	static char buffer[BUFFER_SIZE];
	static int	bytes_read = 0;
	static int	buffer_index = 0;
	char		*line;
	int			i = 0;
	
	if (BUFFER_SIZE < 1 || fd < 0)
		return NULL;
	line = (char *)malloc(1);
	if (!line)
		return NULL;
	line[0] = '\0';
	while (1)
	{
		if (buffer_index >= bytes_read) 
		{
			bytes_read = read(fd, buffer, BUFFER_SIZE);
			buffer_index = 0;
			if (bytes_read <= 0)
			{
				if (i == 0)
				{
					free(line);
					return (NULL);
				}
				else
					break ;
			}		
		}
		line = join_char(line, buffer[buffer_index++], i);
		if (!line)
			return (NULL);
		if(line[i++] == '\n')
			break ;
	}
	return (line);
}

/* int main(void)
{
	int 	fd;
	char	*line;

	fd = open("test.txt", O_RDONLY);
	while ((line = get_next_line(fd)) != NULL)
	{
		printf("%s", line);
		free(line);
	}
	return (0);
} */