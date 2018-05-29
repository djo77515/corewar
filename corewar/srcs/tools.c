/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eparisot <eparisot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/25 23:28:10 by eparisot          #+#    #+#             */
/*   Updated: 2018/05/29 14:33:28 by eparisot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <corewar.h>

char		*translate(int64_t val)
{
	char	*text;
	int		i;

	i = 0;
	if (!(text = ft_strnew(5)))
		exit(EXIT_FAILURE);
	text[0] = val >> 24;
	text[1] = val >> 16;
	text[2] = val >> 8;
	text[3] = val & 0x000000FF;
	text[4] = '\0';
	return (text);
}

int		pad(char **str, int n)
{
	char	*tmp;
	char	zeros[n + 1];
	int		i;
	int		len;

	i = 0;
	len = n - ft_strlen(*str);
	tmp = *str;
	while (len--)
		zeros[i++] = '0';
	while (i <= n)
		zeros[i++] = '\0';
	if (!(*str = ft_strjoin(zeros, *str)))
		exit(EXIT_FAILURE);
	free(tmp);
	return (SUCCESS);
}
