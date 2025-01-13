/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: toto <toto@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/06 19:02:59 by tmillot           #+#    #+#             */
/*   Updated: 2024/11/15 12:02:40 by toto             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd)
{
	static char	buffer[BUFFER_SIZE + 1];
	char		*str;
	int			read_byte;

	str = NULL;
	read_byte = 1;
	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	str = process_buffer(buffer, str);
	while (read_byte > 0 && is_new_line(buffer) == 0)
	{
		read_byte = read(fd, buffer, BUFFER_SIZE);
		if (read_byte < 0)
			return (free(str), NULL);
		if (read_byte == 0)
		{
			if (str != NULL && str[0] != '\0')
				return (str);
			return (free(str), NULL);
		}
		buffer[read_byte] = '\0';
		str = ft_strjoin_gnl(str, buffer);
	}
	return (str);
}

// int main()
// {
// 	int fd;
// 	char *str;
// 	fd = open("test.txt", O_RDONLY);
// 	str = get_next_line(fd);
// 	printf("lecture du fichier test : \n");
// 	while (str != NULL)
// 	{
// 		printf("%s", str);
// 		str = get_next_line(fd);
// 	}
// 	free(str);
// 	close(fd);
// 	fd = open("test2.txt", O_RDONLY);
// 	str = get_next_line(fd);
// 	printf("lecture du fichier test2 : \n");
// 	while (str != NULL)
// 	{
// 		printf("%s", str);
// 		str = get_next_line(fd);
// 	}
// 	free(str);
// 	close(fd);
// 	fd = open("test3.txt", O_RDONLY);
// 	str = get_next_line(fd);
// 	printf("lecture du fichier test3 : \n");
// 	while (str != NULL)
// 	{
// 		printf("%s", str);
// 		str = get_next_line(fd);
// 	}
// 	free(str);
// 	close(fd);
// 	fd = open("test4.txt", O_RDONLY);
// 	str = get_next_line(fd);
// 	printf("lecture du fichier test4 : \n");
// 	while (str != NULL)
// 	{
// 		printf("%s", str);
// 		str = get_next_line(fd);
// 	}
// 	free(str);
// 	close(fd);
// 	fd = open("test5.txt", O_RDONLY);
// 	str = get_next_line(fd);
// 	printf("lecture du fichier test5 : \n");
// 	while (str != NULL)
// 	{
// 		printf("%s", str);
// 		str = get_next_line(fd);
// 	}
// 	free(str);
// 	close(fd);
// 	fd = open("test6.txt", O_RDONLY);
// 	str = get_next_line(fd);
// 	printf("lecture du fichier test6 qui n'existe pas : \n");
// 	printf("%s", str);
// 	free(str);
// 	close(fd);
// }