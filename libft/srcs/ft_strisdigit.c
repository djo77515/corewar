/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strisdigit.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmilan <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/19 16:54:54 by pmilan            #+#    #+#             */
/*   Updated: 2018/04/20 15:29:32 by pmilan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <libft.h>

int		ft_strisdigit(char *str)
{
	int		i;

	if (str == NULL)
		return (0);
	i = -1;
	while (str[++i])
	{
		if (!((i == 0 && str[i] == '-') || (str[i] >= '0' && str[i] <= '9')))
			return (0);
	}
	return (1);
}
