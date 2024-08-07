/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtoupper.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vberdugo <vberdugo@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/07 11:15:53 by vberdugo          #+#    #+#             */
/*   Updated: 2024/08/07 11:46:38 by vberdugo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_strtoupper(char *str)
{
	while (*str)
	{
		if (*str >= 'a' && *str <= 'f')
			*str -= 32;
		str++;
	}
}