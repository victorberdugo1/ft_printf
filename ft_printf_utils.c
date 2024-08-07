/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vberdugo <vberdugo@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/07 16:03:05 by vberdugo          #+#    #+#             */
/*   Updated: 2024/08/07 16:04:12 by vberdugo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	printstr(char *str)
{
	int	count;

	if (str == NULL)
		str = "(null)";
	count = strlen(str);
	write(1, str, count);
	return (count);
}
