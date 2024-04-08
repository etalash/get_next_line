/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stalash <stalash@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/02 14:37:48 by stalash           #+#    #+#             */
/*   Updated: 2024/04/08 16:26:58 by stalash          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

// int	new_line(t_list *list)
// {
// 	if (list == NULL)
// 		return (0);
// 	while (list)
// 	{
// 		if (*(list->content) != '\0' && BUFFER_SIZE > 0)
// 		{
// 			if (*(list->content) == '\n')
// 				return (1);
// 		}
// 		list = list->next;
// 	}
// 	return (0);
// }

int	new_line(t_list *list)
{
	int	i;

	if (list == NULL)
		return (0);
	while (list != NULL)
	{
		i = 0;
		if (list->content[i] != '\0' && BUFFER_SIZE > i)
		{
			if (list->content[i] == '\n')
				return (1);
			i++;
		}
		list = list->next;
	}
	return (0);
}

t_list	*ft_lstlast(t_list *lst)
{
	if (lst == NULL)
		return (NULL);
	while (lst->next != NULL)
		lst = lst->next;
	return (lst);
}

// t_list	*ft_lstlast(t_list *lst)
// {
// 	if (lst == NULL)
// 		return (NULL);
// 	while (lst->next != NULL)
// 		lst = lst->next;
// 	return (lst);
// }

// int	ft_strlen(t_list *list)
// {
// 	int i = 0;

// 	if (list == NULL)
// 		return (0);
// 	while (list)
// 	{
// 		int j = 0;
// 		while (list->content[j])
// 		{
// 			if (list->content[j] == '\n')
// 				return (i + 1);
// 			i++;
// 			j++;
// 		}
// 		list = list->next;
// 	}
// 	return (i);
// }

// in if condition if break doesent work use return (i);
int	ft_strlen(t_list *list)
{
	int	i;
	int	len;

	if (NULL == list)
		return (0);
	len = 0;
	while (list)
	{
		i = 0;
		while (list->content[i])
		{
			if (list->content[i] == '\n')
			{
				++len;
				return (len);
			}
			++i;
			++len;
		}
		list = list->next;
	}
	return (len);
}

// void ft_join_str(t_list **list, char *ptr)
// {
// 	t_list *new_node;
// 	t_list *last_node = ft_lstlast(*list);

// 	new_node = malloc(sizeof(t_list));
// 	if (new_node == NULL)
// 		return ;
// 	new_node->content = ptr;
// 	new_node->next = NULL;
// 	if (*list == NULL)
// 		*list = new_node;
// 	else
// 		last_node->next = new_node;
// }

void	ft_join_str(t_list **list, char *ptr)
{
	t_list	*new_node;
	t_list	*last_node;

	last_node = ft_lstlast(*list);
	new_node = malloc(sizeof(t_list));
	if (NULL == new_node)
		return ;
	if (NULL == last_node)
		*list = new_node;
	else
		last_node->next = new_node;
	new_node->content = ptr;
	new_node->next = NULL;
}

// void clear_line(t_list **list)
// {
// 	t_list *temp;

// 	if (*list == NULL)
// 		return ;
// 	while (*list != NULL)
// 	{
// 		temp = (*list)->next;
// 		free((*list)->content);
// 		free(*list);
// 		*list = temp;
// 	}
// }

void	dealloc(t_list **list, t_list *clean_node, char *buf)
{
	t_list	*tmp;

	if (NULL == *list)
		return ;
	while (*list)
	{
		tmp = (*list)->next;
		free((*list)->content);
		free(*list);
		*list = tmp;
	}
	*list = NULL;
	if (clean_node->content[0])
		*list = clean_node;
	else
	{
		free(buf);
		free(clean_node);
	}
}
