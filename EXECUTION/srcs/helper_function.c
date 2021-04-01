/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helper_function.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-omar@student.1337.ma <mel-omar>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/21 13:46:58 by mel-omar          #+#    #+#             */
/*   Updated: 2021/04/01 14:31:24 by mel-omar@st      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_cstrcmp(const char *s1, const char *s2)
{
	unsigned int	iterator;

	iterator = 0;
	while (s1[iterator] && s2[iterator] && s1[iterator] == s2[iterator])
		iterator++;
	return ((int)(s1[iterator] - s2[iterator]));
}
