/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vberdugo <vberdugo@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/28 14:27:23 by vberdugo          #+#    #+#             */
/*   Updated: 2024/08/06 18:03:52 by vberdugo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <unistd.h>

int	ft_putnum_hex(unsigned long num)
{
	char	*hex_digits;
	char	buffer[16];
	int		i;
	int		count;

	hex_digits = "0123456789abcdef";
	i = 0;
	count = 0;
	if (num == 0)
	{
		write(1, "0", 1);
		return (1);
	}
	while (num != 0)
	{
		buffer[i++] = hex_digits[num % 16];
		num /= 16;
	}
	while (i--)
	{
		write(1, &buffer[i], 1);
		count++;
	}
	return (count);
}

int	ft_print_ptr(void *p)
{
	unsigned long	addr;
	int				count;

	count = 0;
	addr = (unsigned long)p;
	if (addr == 0)
	{
		ft_putstr_fd("(nil)", 1);
		count += 5;
		return (count);
	}
	else
	{
		write(1, "0x", 2);
		count += 2;
		count += ft_putnum_hex(addr);
	}
	return (count);
}

int	handle_format(const char **format, va_list args)
{
	int		count;
	char	*str ;

	count = 0;
	(*format)++;
	if (**format == 'c')
		count += ft_putchar_fd((char)va_arg(args, int), 1);
	else if (**format == 's')
	{
		str = va_arg(args, char *);
		ft_putstr_fd(str, 1);
		count += ft_strlen(str);
	}
	else if (**format == 'p')
		count += ft_print_ptr(va_arg(args, void *));
	else if (**format == 'd' || **format == 'i' )
		count += ft_putnbr_fd(va_arg(args, int), 1);
	else if (**format == 'u')
		count += ft_putnbr_fd(va_arg(args, int), 1);
	else if (**format == 'x' || **format == 'X' )
		count += ft_putnbr_fd(va_arg(args, int), 1);
	return (count);
}

int	ft_printf(char const *format, ...)
{
	va_list	args;
	int		count;

	count = 0;
	va_start(args, format);
	while (*format)
	{
		if (*format == '%')
		{
			count += handle_format(&format, args);
		}
		else
		{
			ft_putchar_fd(*format, 1);
			count++;
		}
		format++;
	}
	va_end(args);
	return (count);
}
