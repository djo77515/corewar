/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isupper.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmilan <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/20 17:30:19 by pmilan            #+#    #+#             */
/*   Updated: 2017/12/20 17:30:48 by pmilan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int			ft_isupper(int c)
{
	return (c >= 'A' && c <= 'Z') ? 1 : 0;
}
