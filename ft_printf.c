/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vberdugo <vberdugo@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/28 14:27:23 by vberdugo          #+#    #+#             */
/*   Updated: 2024/08/05 20:48:39 by victor           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printf(char const *format, ...)
{
	va_list	args;
	int		count;

	count = 0;
	va_start( args, format);
	while (*format) {
        if (*format == '%') {
            format++;
            if (*format == 'c') {
                ft_putchar_fd((char)va_arg(args, int), 1);
                count++;
            } else if (*format == 'd') {
                ft_putnbr_fd(va_arg(args, int), 1);

            } else if (*format == 's') {
                ft_putstr_fd(va_arg(args, char *), 1);

            }
        } else {
            ft_putchar_fd(*format, 1);
            count++;
        }
        format++;
    }
	va_end (args);
	return (count);
}
