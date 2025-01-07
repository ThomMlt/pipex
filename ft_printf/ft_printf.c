/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: toto <toto@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/15 14:32:24 by toto              #+#    #+#             */
/*   Updated: 2024/11/18 17:42:41 by toto             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_parse_printf(const char *str, va_list args, int *count)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] == '%')
			ft_check_option(str[++i], args, count);
		else
		{
			ft_putchar(str[i]);
			(*count)++;
		}
		i++;
	}
}

void	ft_check_option(char c, va_list args, int *count)
{
	if (c == 'c')
	{
		ft_putchar((char)va_arg(args, int));
		(*count)++;
	}
	else if (c == 's')
		ft_putstr_count(va_arg(args, char *), count);
	else if (c == 'p')
		ft_print_pointer(va_arg(args, unsigned long), count);
	else if (c == 'd')
		ft_putnbr_count(va_arg(args, int), count);
	else if (c == 'i')
		ft_putnbr_count(va_arg(args, int), count);
	else if (c == 'x')
		ft_putnbr_hexa_lowercase(va_arg(args, int), count);
	else if (c == 'X')
		ft_putnbr_hexa_uppercase(va_arg(args, int), count);
	else if (c == 'u')
		ft_putnbr_count_unsigned(va_arg(args, unsigned int), count);
	else if (c == '%')
	{
		ft_putchar('%');
		(*count)++;
	}
}

int	ft_printf(const char *str, ...)
{
	va_list	args;
	int		count;

	va_start(args, str);
	count = 0;
	ft_parse_printf(str, args, &count);
	va_end(args);
	return (count);
}

// void main()
// {
// 	printf("size : %d \n", ft_printf(" %x ", -1));
// 	printf("size : %d", printf(" %x ", -1));
// }