/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stalash <stalash@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/02 12:22:43 by stalash           #+#    #+#             */
/*   Updated: 2024/04/02 18:05:06 by stalash          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <unistd.h>
# include <stdlib.h>

typedef struct s_list
{
	char			*content;
	struct s_list	*next;
}					t_list;

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 10
# endif

char	*get_next_line(int fd);
void	ft_create(t_list **list, int fd);
char	*make_line(t_list *list);
void	ft_copy_str(t_list *list, char *new_str);
void	clean_up(t_list **list);
int		new_line(t_list *list);
t_list	*find_last_node(t_list *list);
// t_list	*ft_lstlast(t_list *lst);
int		ft_strlen(t_list *list);
void	ft_join_str(t_list **list, char *ptr);
void	clear_line(t_list **list);
void	dealloc(t_list **list, t_list *clean_node, char *buf);
// void	clear_line(t_list **list, t_list *for_clean, char *str);

#endif
