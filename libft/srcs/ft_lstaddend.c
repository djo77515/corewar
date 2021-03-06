/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstaddend.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eparisot <eparisot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/29 14:57:22 by eparisot          #+#    #+#             */
/*   Updated: 2018/05/17 15:05:18 by pmilan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

void	ft_lstaddend(t_list **alst, t_list *new)
{
	t_list	*tmp;

	tmp = *alst;
	if (alst && new)
	{
		while (tmp->next)
			tmp = tmp->next;
		tmp->next = new;
	}
}
