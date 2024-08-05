/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vberdugo <vberdugo@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/28 14:27:23 by vberdugo          #+#    #+#             */
/*   Updated: 2024/08/05 16:54:27 by vberdugo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printf(char const *format, ...)
{
	va_list	args;
	int		count;

	count = 0;
	va_start( args, format);
    while (*format)
    {
        if (*format == '%')
        {
            format++;
            if (*format == 'c')
            {
                ft_putchar_fd((char) va_arg(args, int), 1);
                count++;
            }
        }
        else
        {
            ft_putchar_fd(*format, 1);
            count++;
        }
        format++;
    }
	va_end (args);
	return (count);
}
