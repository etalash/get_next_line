/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stalash <stalash@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/02 12:29:29 by stalash           #+#    #+#             */
/*   Updated: 2024/04/11 13:54:05 by stalash          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

void	clean_up(t_list **list)
{
	t_list	*last_node;
	t_list	*clean_node;
	int		i;
	int		k;
	char	*buf;

	buf = malloc(BUFFER_SIZE + 1);
	clean_node = malloc(sizeof(t_list));
	if (NULL == buf || NULL == clean_node)
		return ;
	last_node = ft_lstlast(*list);
	i = 0;
	k = 0;
	while (last_node->content[i] != '\n' && last_node->content[i] != '\0')
		++i;
	while (last_node->content[i] != '\0' && last_node->content[++i] != '\0')
		buf[k++] = last_node->content[i];
	buf[k] = '\0';
	clean_node->content = buf;
	clean_node->next = NULL;
	dealloc(list, clean_node, buf);
}

void	ft_copy_str(t_list *list, char *new_str)
{
	int	i;
	int	k;

	if (NULL == list)
		return ;
	k = 0;
	while (list)
	{
		i = 0;
		while (list->content[i])
		{
			if (list->content[i] == '\n')
			{
				new_str[k++] = '\n';
				new_str[k] = '\0';
				return ;
			}
			new_str[k++] = list->content[i++];
		}
		list = list->next;
	}
	new_str[k] = '\0';
}

char	*make_line(t_list *list)
{
	char	*new_list;
	int		len;

	if (list == NULL)
		return (NULL);
	len = ft_strlen(list);
	new_list = malloc(len + 1);
	if (NULL == new_list)
		return (NULL);
	ft_copy_str(list, new_list);
	return (new_list);
}

void	ft_create(t_list **list, int fd)
{
	char	*str;
	int		char_read;

	while (!new_line(*list))
	{
		str = malloc(BUFFER_SIZE + 1);
		if (str == NULL)
			return ;
		char_read = read(fd, str, BUFFER_SIZE);
		if (!char_read)
		{
			free(str);
			return ;
		}
		str[char_read] = '\0';
		ft_join_str(list, str);
	}
}

char	*get_next_line(int fd)
{
	static t_list	*list = NULL;
	char			*str;

	if (fd < 0 || BUFFER_SIZE <= 0 || read(fd, &str, 0) < 0)
		return (NULL);
	ft_create(&list, fd);
	if (list == NULL)
		return (NULL);
	str = make_line(list);
	clean_up(&list);
	return (str);
}
// #include <stdio.h>

// int main (void)
// {
// 	printf("%s", get_next_line);

// 	return (0);
// }
